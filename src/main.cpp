#include "mbed.h"
#include "Menu/Menu.h"
#include "Config/Pin_config.h"

DigitalOut myled(LED1);
PwmOut mot1(PIN_MOT_1);
PwmOut mot2(PIN_MOT_2);
AnalogIn adc1(PIN_ADC_1);
AnalogIn adc2(PIN_ADC_2);
AnalogOut dac1(PIN_DAC_1);
AnalogOut dac2(PIN_DAC_2);
I2C i2c(PIN_SDA,PIN_SCL);

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

	Menu_init("Beautiful menu");
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
