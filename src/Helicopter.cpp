/*
 * Helicopter.cpp
 *
 *  Created on: 9 févr. 2017
 *      Author: JulienCombattelli
 */

#include "Helicopter.h"

Helicopter::Helicopter() :
	m_motorMain(PA_8), m_motorTail(PA_11)
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


