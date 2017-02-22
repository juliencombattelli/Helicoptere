/*
 * Helicopter.cpp
 *
 *  Created on: 9 févr. 2017
 *      Author: JulienCombattelli
 */

#include "Helicopter.h"
#include "CommunicationProtocol.h"

Helicopter::Helicopter() :
	m_motorMain(PIN_MOT_1), m_motorTail(PIN_MOT_2),
	m_adc1(PIN_ADC_1), m_adc2(PIN_ADC_2),
	m_dac1(PIN_DAC_1), m_dac2(PIN_DAC_2),
	//m_i2c(PIN_SDA,PIN_SCL)
	m_Te(0), m_Tsim(0), m_currentTime(0),
	m_waveformMain(nullptr),
	m_waveformTail(nullptr)
{
	m_motorMain = 1.0f;
	m_motorTail = 1.0f;
}

void Helicopter::run()
{
	while(1)
	{
		//if(m_remotePC.readable())
		//{
			char cmd = 0;
			cmd = getchar();
			switch(cmd)
			{
			case 0x01:
				motorMainSetSpeed(((float)getchar())/100.f);
				break;
			case 0x02:
				motorTailSetSpeed(((float)getchar())/100.f);
				break;
			case FrameType_Stop:
				stop();
				break;
			case FrameType_Initialization:
				handleInitializationFrame();
				break;
			case FrameType_SignalRotorMain:
				handleSignalRotorMainFrame();
				break;
			case FrameType_SignalRotorTail:
				handleSignalRotorTailFrame();
				break;
			case FrameType_Start:
				m_ticker.attach_us(callback(this, &Helicopter::process), m_Te);
				while(1);
				break;
			};
		//}
	}
}

void Helicopter::stop()
{
	m_ticker.detach();
	motorMainSetSpeed(0);
	motorTailSetSpeed(0);
}

void Helicopter::motorMainSetSpeed(float speed)
{
	m_motorMain = 1.0f - speed;
}

void Helicopter::motorMainIncreaseSpeed(float speed)
{
	m_motorMain = m_motorMain - speed;
}

void Helicopter::motorMainDecreaseSpeed(float speed)
{
	m_motorMain = m_motorMain + speed;
}

int Helicopter::motorMainGetSpeed()
{
	return 100 - (int(m_motorMain.read() * 100.f));
}

void Helicopter::motorTailSetSpeed(float speed)
{
	m_motorTail = 1.0f - speed;
}

void Helicopter::motorTailIncreaseSpeed(float speed)
{
	m_motorTail = m_motorTail - speed;
}

void Helicopter::motorTailDecreaseSpeed(float speed)
{
	m_motorTail = m_motorTail + speed;
}

void Helicopter::setAnalog1(float value)
{
	m_dac1.write(value);
}

void Helicopter::setAnalog2(float value)
{
	m_dac2.write(value);
}

float Helicopter::getAnalog1()
{
	return m_adc1.read();
}

float Helicopter::getAnalog2()
{
	return m_adc2.read();
}

int Helicopter::motorTailGetSpeed()
{
	return 100 - (int(m_motorTail.read() * 100.f));
}

void Helicopter::handleInitializationFrame()
{
	uint8_t buffer[4];

	receive(buffer, 2);
	m_Te = to_uint16(buffer);

	receive(buffer,4);
	m_Tsim = to_uint32(buffer);
}

void Helicopter::handleSignalRotorMainFrame()
{
	uint8_t buffer[4];

	receive(buffer, 4);
	uint32_t Tstart = to_uint32(buffer);

	uint8_t waveform = getchar();
	switch(waveform)
	{
	case WaveformType_Step:
	{
		receive(buffer, 4);
		uint32_t finalValue = to_uint32(buffer);
		m_waveformMain = new StepWaveform(Tstart, finalValue);
		break;
	}
	case WaveformType_Ramp:
	{
		receive(buffer, 4);
		uint32_t slope = to_uint32(buffer);
		m_waveformMain = new RampWaveform(Tstart, slope);
		break;
	}
	}
}

void Helicopter::handleSignalRotorTailFrame()
{
	uint8_t buffer[4];

	receive(buffer, 4);
	uint32_t Tstart = to_uint32(buffer);

	uint8_t waveform = getchar();
	switch(waveform)
	{
	case WaveformType_Step:
	{
		receive(buffer, 4);
		uint32_t finalValue = to_uint32(buffer);
		m_waveformTail = new StepWaveform(Tstart, finalValue);
		break;
	}
	case WaveformType_Ramp:
	{
		receive(buffer, 4);
		uint32_t slope = to_uint32(buffer);
		m_waveformTail = new RampWaveform(Tstart, slope);
		break;
	}
	}
}

void Helicopter::process()
{
	float commandRotorMain = m_waveformMain->generate(m_currentTime)/100000000.f;
	//printf("main : %d\r\n", int(commandRotorMain*100));
	printf("main : %lu at time : %lu\r\n", m_waveformMain->generate(m_currentTime), m_currentTime*m_Te);
	motorMainSetSpeed(commandRotorMain);

	float commandRotorTail = m_waveformTail->generate(m_currentTime)/100000000.f;
	//printf("tail : %d\r\n", int(commandRotorTail*100));
	motorTailSetSpeed(commandRotorTail);

	m_currentTime++;
	if(m_currentTime > m_Tsim)
		stop();
}
