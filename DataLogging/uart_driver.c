/*
 * uart_driver.c
 *
 *  Created on: Oct 29, 2019
 *      Author: Charlotte Ross
 */

#include "uart_driver.h"


void UART_init()
{
   const eUSCI_UART_Config config =
   {
    EUSCI_A_UART_CLOCKSOURCE_SMCLK,
    prescaler,
    firstModReg,
    secondModReg,
    EUSCI_A_UART_NO_PARITY,
    EUSCI_A_UART_LSB_FIRST,
    EUSCI_A_UART_ONE_STOP_BIT,
    EUSCI_A_UART_MODE,
    EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION
   };

   initUART(EUSCI_A2_BASE, &config);
}


void initUART(uint32_t moduleInstance, const eUSCI_UART_Config *config)
{
    UART_initModule(moduleInstance, config);
    UART_enableModule(moduleInstance);
    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P3, GPIO_PIN2,GPIO_PRIMARY_MODULE_FUNCTION);
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P3, GPIO_PIN3,GPIO_PRIMARY_MODULE_FUNCTION);

    //for EUSCI_A0_BASE
    UART_initModule(EUSCI_A0_BASE, config);
    UART_enableModule(EUSCI_A0_BASE);
    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1, GPIO_PIN2,GPIO_PRIMARY_MODULE_FUNCTION);
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P1, GPIO_PIN3,GPIO_PRIMARY_MODULE_FUNCTION);
}

uint8_t UARTGetChar(uint32_t moduleInstance)
{
    if(UARTHasChar(moduleInstance))
        return UART_receiveData(moduleInstance);
    else
        return 0;
}
void UARTPutChar(uint32_t moduleInstance, uint8_t transmittedChar)
{
    if (UARTCanSend(moduleInstance))
        UART_transmitData(moduleInstance, transmittedChar);
}

bool UARTHasChar(uint32_t moduleInstance)
{
    return UART_getInterruptStatus(moduleInstance, EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG);
}
bool UARTCanSend(uint32_t moduleInstance)
{
    return UART_getInterruptStatus(moduleInstance, EUSCI_A_UART_TRANSMIT_INTERRUPT_FLAG);
}

int receive()
{
    char rx_char;
    rx_char = UARTGetChar(EUSCI_A2_BASE);

    int r_value = rx_char;

    if (rx_char)
    {

        UARTPutChar(EUSCI_A0_BASE, rx_char);
         if (rx_char == alive) // l
            r_value = 0;
         else if (rx_char == SDinit) // 2
            r_value = 0;
         else if (rx_char == ready) // <
            r_value = 1;
    }
    return r_value;
}

void send(char *data_buffer)
{
    char tx_char;
    int i = 0;

    tx_char = data_buffer[i];

    while(tx_char != '\0')
   {
      if (Timer0_Expired())
      {
          UARTPutChar(EUSCI_A0_BASE, tx_char);
          UARTPutChar(EUSCI_A2_BASE, tx_char);
          i++;
          tx_char = data_buffer[i];
      }
   }
}


