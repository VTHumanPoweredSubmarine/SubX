/*
 * rpm.h
 *
 *  Created on: Nov 8, 2019
 *      Author: Charlotte Ross
 */

#ifndef RPM_H_
#define RPM_H_

#include <stdint.h>


void initRPM();
void rpmIRQHandler();
uint16_t getRPM();
//uint32_t second();

#endif /* RPM_H_ */
