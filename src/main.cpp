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
	Menu_init("Beautiful menu");
	Menu_add_item("Main -", mot1m_handler);
	Menu_add_item("Main +", mot1p_handler);
	Menu_add_item("Tail -", mot2m_handler);
	Menu_add_item("Tail +", mot2p_handler);

	while(1)
	{
		puts("\r\n");
		Menu_print();
		char userInput = 0;
		userInput = getchar();
		Menu_choose(userInput-'0');
	}
}
