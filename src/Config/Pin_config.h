/*
 * Pin_config.h
 *
 *  Created on: 9 févr. 2017
 *      Author: guill
 */

#ifndef CONFIG_PIN_CONFIG_H_
#define PIN_CONFIG_PIN_CONFIG_H_

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

/* UART1 for bluetooth -- default redirection*/
#define PIN_TX_1 	PA_9
#define PIN_RX_1 	PA_10

/* UART2 for usb */
#define PIN_TX_2 	PA_2
#define PIN_RX_2 	PA_3

/* Motors -- PWM control */
#define PIN_MOT_1 	PA_8
#define PIN_MOT_2 	PA_11

/* potentiometers */
#define PIN_POT_1 	PA_7
#define PIN_POT_2 	PB_0

/* Analog in -- for XPC target */
#define PIN_ADC_1 	PA_0
#define PIN_ADC_2 	PA_1

/* Analog out -- for XPC target */
#define PIN_DAC_1 	PA_6
#define PIN_DAC_2 	PA_5

/* I2C */
#define PIN_SDA 	PB_7
#define PIN_SCL 	PB_6

/* SPI */
#define PIN_MOSI 	PB_5
#define PIN_MISO 	PB_4
#define PIN_SCLK 	PB_3
#define PIN_CS 		PA_4

#endif /* CONFIG_PIN_CONFIG_H_ */
