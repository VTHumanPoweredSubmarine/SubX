/*
 * timer_driver.c
 *
 *  Created on: Oct 29, 2019
 *      Author: Charlotte Ross
 */

#include "timer_driver.h"


void Init_Timers()
{
    Timer32_initModule(TIMER32_0_BASE, TIMER32_PRESCALER_256, TIMER32_32BIT, TIMER32_PERIODIC_MODE);
    Timer32_setCount(TIMER32_0_BASE, COUNT0);
    Timer32_startTimer(TIMER32_0_BASE, CONTINUOUS);
    Timer32_initModule(TIMER32_1_BASE, TIMER32_PRESCALER_16, TIMER32_32BIT, TIMER32_PERIODIC_MODE);
    Timer32_setCount(TIMER32_1_BASE, COUNT1);
    Timer32_startTimer(TIMER32_1_BASE, CONTINUOUS);
}

bool Timer0_Expired()
{
    static unsigned int previousSnap = 0;
    unsigned int currentSnap;
    bool returnValue;

    currentSnap = Timer32_getValue(TIMER32_0_BASE);
    returnValue = (currentSnap > previousSnap);
    previousSnap = currentSnap;
    return returnValue;
}

bool Timer1_Expired()
{
    static unsigned int previousSnap = 0;
    unsigned int currentSnap;
    bool returnValue;

    currentSnap = Timer32_getValue(TIMER32_1_BASE);
    returnValue = (currentSnap > previousSnap);
    previousSnap = currentSnap;
    return returnValue;
}

