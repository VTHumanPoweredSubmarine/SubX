/*
 * rpm.c
 *
 *  Created on: Nov 8, 2019
 *      Author: Charlotte Ross
 */

#include <ti/devices/msp432p4xx/inc/msp.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "rpm.h"
#include "pins.h"
#include "timer_driver.h"

static volatile unsigned long rpmA;
static volatile unsigned long rpmB;
static volatile unsigned long countA;
static volatile unsigned long countB;

void initRPM()
{
    //clear interrupts
    Interrupt_disableMaster();
    GPIO_clearInterruptFlag(GPIO_PORT_P2, GPIO_PIN4 | GPIO_PIN6);

    //initialize pins
    GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P2, GPIO_PIN4 | GPIO_PIN6); //pull down?

    //set as rising edge interrupt
    GPIO_interruptEdgeSelect(GPIO_PORT_P2, GPIO_PIN4 | GPIO_PIN6, GPIO_LOW_TO_HIGH_TRANSITION);

    //enable Interrupts
    GPIO_enableInterrupt(GPIO_PORT_P2, GPIO_PIN4 | GPIO_PIN6);
    Interrupt_enableInterrupt(INT_PORT2);
    Interrupt_enableMaster();

    countA = 0;
    countB = 0;
}


void PORT2_IRQHandler()
{
    //GPIO_getInputPinValue(GPIO_PORT_2, GPIO_PIN_4) do we need the actual value?
    uint32_t status;

    status = GPIO_getEnabledInterruptStatus(GPIO_PORT_P2);
    GPIO_clearInterruptFlag(GPIO_PORT_P2, status);

    if (status & GPIO_PIN4)
    {
        countA++;
        if (Timer1_Expired())
        {
            rpmA = countA*60;
            countA = 0;
        }
    }
    else if (status & GPIO_PIN6) //maybe maybe not
    {
        countB++;
        if (Timer1_Expired())
        {
            rpmB = countB*60;
            countB = 0;
        }
    }
}

uint16_t getRPM()
{
    return (rpmA + rpmB) / 2;
}


