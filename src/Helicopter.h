/*
 * Helicopter.h
 *
 *  Created on: 9 f�vr. 2017
 *      Author: JulienCombattelli
 */

#ifndef HELICOPTER_H_
#define HELICOPTER_H_

#include "mbed.h"
#include "Config/Pin_config.h"

class Helicopter
{
public:

	Helicopter();

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

	PwmOut m_motorMain;
	PwmOut m_motorTail;

	AnalogIn m_adc1;
	AnalogIn m_adc2;
	AnalogOut m_dac1;
	AnalogOut m_dac2;
	I2C m_i2c;
};

#endif /* HELICOPTER_H_ */
