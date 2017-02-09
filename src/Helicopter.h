/*
 * Helicopter.h
 *
 *  Created on: 9 févr. 2017
 *      Author: JulienCombattelli
 */

#ifndef HELICOPTER_H_
#define HELICOPTER_H_

#include "mbed.h"

class Helicopter
{
public:

	Helicopter();

	void motorMainSetSpeed(float speed);
	void motorMainIncreaseSpeed(float speed);
	void motorMainDecreaseSpeed(float speed);

	void motorTailSetSpeed(float speed);
	void motorTailIncreaseSpeed(float speed);
	void motorTailDecreaseSpeed(float speed);

private:

	PwmOut m_motorMain;
	PwmOut m_motorTail;

	/*AnalogIn adc1(PA_0);
	AnalogIn adc2(PA_1);
	AnalogOut dac1(PA_6);
	AnalogOut dac2(PA_5);
	I2C i2c(PB_7,PB_6);*/
};

#endif /* HELICOPTER_H_ */
