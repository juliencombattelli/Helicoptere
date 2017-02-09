#include "mbed.h"
#include "Menu/Menu.h"

/*
 * Tx1 PA9 Rx1 PA10
 * Tx2 PA2 Rx2 PA3
 * Mot1 PA8 Mot2 PA11
 * Pot1 PA7 Pot2 PB0
 * AnalogIn1 PA0 AnalogIn2 PA1
 * AnalogOut1 pA6 AnalogOut2 PA5
 * SDA PB7 SCL PB6
 * MOSI PB5 MISO PB4 SCLK PB3 CS PA4
 */

DigitalOut myled(LED1);
PwmOut mot1(PA_8);
PwmOut mot2(PA_11);
AnalogIn adc1(PA_0);
AnalogIn adc2(PA_1);
AnalogOut dac1(PA_6);
AnalogOut dac2(PA_5);
I2C i2c(PB_7,PB_6);

#define STEP (0.05f)

void mot1p_handler()
{
	printf("mot1 : %d%%\r\n", int(mot1.read()*100));
	mot1 = mot1 + STEP;
}

void mot1m_handler()
{
	printf("mot1 : %d%%\r\n", int(mot1.read()*100));
	mot1 = mot1 - STEP;
}

void mot2p_handler()
{
	printf("mot2 : %d%%\r\n", int(mot2.read()*100));
	mot2 = mot2 + STEP;
}

void mot2m_handler()
{
	printf("mot2 : %d%%\r\n", int(mot2.read()*100));
	mot2 = mot2 - STEP;
}

int main()
{
	mot1 = 1;
	mot2 = 1;

	Menu_init("Beautifull menu");
	Menu_add_item("Mot1 +", mot1p_handler);
	Menu_add_item("Mot1 -", mot1m_handler);
	Menu_add_item("Mot2 +", mot2p_handler);
	Menu_add_item("Mot2 -", mot2m_handler);

	while(1)
	{
		puts("\r\n");
		Menu_print();
		char userInput = 0;
		userInput = getchar();
		Menu_choose(userInput-'0');
	}
}
