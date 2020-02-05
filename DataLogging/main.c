#include <ti/devices/msp432p4xx/inc/msp.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <stdio.h>
#include "uart_driver.h"
#include "timer_driver.h"
#include "rpm.h"
#include "pressure.h"

typedef enum {init, log_data} log_state_;


void initBoard();
void initialize();

/*
 * Main function
 */
int main(void)
{

    initialize();

    log_state_ log_state = init;

    char string[20];
    uint16_t rpm;

    while (1)
    {
        rpm = getRPM();
        switch (log_state)
        {
        case init:
            if (receive())
                log_state = log_data;
            break;
        case log_data:
            if (Timer0_Expired())
            {
                sprintf(string, "RPM:\t%d \n", rpm);
                send(string);
            }
            break;
        }
    }
}

void initBoard()
{
    /* Halting WDT and disabling master interrupts */
    MAP_WDT_A_holdTimer();
    MAP_Interrupt_disableMaster();

    /* Set the core voltage level to VCORE1 */
    MAP_PCM_setCoreVoltageLevel(PCM_VCORE1);

    /* Set 2 flash wait states for Flash bank 0 and 1*/
    MAP_FlashCtl_setWaitState(FLASH_BANK0, 2);
    MAP_FlashCtl_setWaitState(FLASH_BANK1, 2);

    /* Initializes Clock System */
    MAP_CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_48);
    MAP_CS_initClockSignal(CS_MCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1);
    MAP_CS_initClockSignal(CS_HSMCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1);
    MAP_CS_initClockSignal(CS_SMCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1);
    MAP_CS_initClockSignal(CS_ACLK, CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_1);
}


void initialize()
{
    initBoard();
    UART_init();
    Init_Timers();
    initRPM();
    initPressure();
}
