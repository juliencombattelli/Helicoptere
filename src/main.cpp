#include "mbed.h"
#include "Helicopter.h"

DigitalOut myled(LED1);
Helicopter helico;

#define STEP (0.05f)

void mot1p_handler()
{
	printf("Main : %d%%\r\n", helico.motorMainGetSpeed());
	helico.motorMainIncreaseSpeed(STEP);
}

void mot1m_handler()
{
	printf("Main : %d%%\r\n", helico.motorMainGetSpeed());
	helico.motorMainDecreaseSpeed(STEP);
}

void mot2p_handler()
{
	printf("Tail : %d%%\r\n", helico.motorTailGetSpeed());
	helico.motorTailIncreaseSpeed(STEP);
}

void mot2m_handler()
{
	printf("Tail : %d%%\r\n", helico.motorTailGetSpeed());
	helico.motorTailDecreaseSpeed(STEP);
}

int main()
{
	printf("hello Word\r\n");

	helico.run();
}
