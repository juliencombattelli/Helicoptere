/*
 * Helicopter.h
 *
 *  Created on: 9 févr. 2017
 *      Author: JulienCombattelli
 */

#ifndef HELICOPTER_H_
#define HELICOPTER_H_

#include "mbed.h"
#include "Config/Pin_config.h"
#include "CommunicationProtocol.h"
#include "Waveform.h"

class Helicopter
{
public:

	Helicopter();

	void run();
	void stop();

	void motorMainSetSpeed(float speed);
	void motorMainIncreaseSpeed(float speed);
	void motorMainDecreaseSpeed(float speed);
	int  motorMainGetSpeed();

	void motorTailSetSpeed(float speed);
	void motorTailIncreaseSpeed(float speed);
	void motorTailDecreaseSpeed(float speed);
	int  motorTailGetSpeed();

	void setAnalog1(float value);
	void setAnalog2(float value);
	float getAnalog1();
	float getAnalog2();

private:

	void handleInitializationFrame();
	void handleSignalRotorMainFrame();
	void handleSignalRotorTailFrame();
	void handleStartFrame();

	void process();

	PwmOut m_motorMain;
	PwmOut m_motorTail;

	AnalogIn m_adc1;
	AnalogIn m_adc2;
	AnalogOut m_dac1;
	AnalogOut m_dac2;
	//I2C m_i2c;
	//Serial m_remotePC;
	/* TODO:
	 * 	add m_remotePC initialization in constructor
	 * 	replace standard I/O redirection with the original one (on USB and not Bluetooth)
	 */

	uint16_t m_Te;
	uint32_t m_Tsim;
	uint32_t m_currentTime;

	Waveform* m_waveformMain;
	Waveform* m_waveformTail;

	Ticker m_ticker;
};

#endif /* HELICOPTER_H_ */
