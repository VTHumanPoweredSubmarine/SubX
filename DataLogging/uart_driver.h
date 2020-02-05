/*
 * uart_driver.h
 *
 *  Created on: Oct 29, 2019
 *      Author: Charlotte Ross
 */

#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_


#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <ti/devices/msp432p4xx/driverlib/uart.h>
#include <ti/devices/msp432p4xx/driverlib/gpio.h>
#include "timer_driver.h"

#define prescaler 156
#define firstModReg 4
#define secondModReg 0
#define alive 0x31
#define SDinit 0x32
#define ready 0x3C
#define escapeChar 0x24


void UART_init();
void initUART(uint32_t moduleInstance, const eUSCI_UART_Config *config);
uint8_t UARTGetChar(uint32_t moduleInstance);
void UARTPutChar(uint32_t moduleInstance, uint8_t transmittedChar);

bool UARTHasChar(uint32_t moduleInstance);
bool UARTCanSend(uint32_t moduleInstance);

int receive();
void send(char *data_buffer);

#endif /* UART_DRIVER_H_ */
