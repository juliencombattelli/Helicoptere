#include "mbed.h"
#include "Menu/Menu.h"
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

	while(1)
	{
		char cmd = 0;
		cmd = getchar();
		switch(cmd)
		{
		case 0x01:
		{
			char value = getchar();
			helico.motorMainSetSpeed(((float)value)/100.f);
			break;
		}
		case 0x02:
		{
			char value = getchar();
			helico.motorTailSetSpeed(((float)value)/100.f);
			break;
		}
		case 0xFF:
		{
			helico.motorMainSetSpeed(0);
			helico.motorTailSetSpeed(0);
			break;
		}
		};
		printf("M : %d | T : %d \r\n", helico.motorMainGetSpeed(), helico.motorTailGetSpeed());
	}
}
