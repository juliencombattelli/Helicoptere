#include "mbed.h"

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

Serial bt(PA_9, PA_10, 115200);
Serial pc(USBTX, USBRX);
PwmOut mot1(PA_8);
PwmOut mot2(PA_11);
AnalogIn adc1(PA_0);
AnalogIn adc2(PA_1);
AnalogOut dac1(PA_6);
AnalogOut dac2(PA_5);
I2C i2c(PB_7,PB_6);

int main()
{
	pc.puts("Test start\r\n");
	bt.puts("hello\r\n");

    while(1)
    {
        myled = 1; // LED is ON
        wait(1); // 200 ms
        myled = 0; // LED is OFF
        wait(1); // 1 sec
    }
}
