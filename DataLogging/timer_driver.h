/*
 * timer_driver.h
 *
 *  Created on: Oct 29, 2019
 *      Author: Charlotte Ross
 */

#ifndef TIMER_DRIVER_H_
#define TIMER_DRIVER_H_

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

#define COUNT0           750       //4 ms
#define COUNT1           187500    //1 s
#define CONTINUOUS      false

void Init_Timers();
bool Timer0_Expired();
bool Timer1_Expired();

#endif /* TIMER_DRIVER_H_ */
