/*
 * Helicopter.cpp
 *
 *  Created on: 9 févr. 2017
 *      Author: JulienCombattelli
 */

#include "Helicopter.h"

Helicopter::Helicopter() :
	m_motorMain(PIN_MOT_1), m_motorTail(PIN_MOT_2),
	m_adc1(PIN_ADC_1), m_adc2(PIN_ADC_2),
	m_dac1(PIN_DAC_1), m_dac2(PIN_DAC_2),
	m_i2c(PIN_SDA,PIN_SCL)
{
	m_motorMain = 1.0f;
	m_motorTail = 1.0f;
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
