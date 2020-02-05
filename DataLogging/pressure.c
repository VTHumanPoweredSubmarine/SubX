/*
 * pressure.c
 *
 *  Created on: Nov 8, 2019
 *      Author: Charlotte Ross
 */


#include <ti/devices/msp432p4xx/inc/msp.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <math.h>
#include "pressure.h"
#include "pins.h"


// GPIO_setAsInputPin(port, pin)
// GPIO_getInputPinValue(port, pin)
void initPressure()
{
    GPIO_setAsInputPin(GPIO_PORT_P4, GPIO_PIN0); //which ones are which?
    GPIO_setAsInputPin(GPIO_PORT_P6, GPIO_PIN1);
}


double getVelocity()
{
    // this function can be called for in the race code and calculates velocity
    // the ftvelocity equation can be removed for the race code as it is for testing on the AOE tow tank

    //retrieve raw data
    uint16_t raw_static_pressure = GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN0);//analogRead(STATIC_SENSOR); // add/subtract constants to zero pressure sensors
    uint16_t raw_dynamic_pressure = GPIO_getInputPinValue(GPIO_PORT_P6, GPIO_PIN1);//analogRead(DYNAMIC_SENSOR);

    //convert from raw data to volts*1024 (5V = 1024 raw data increments)
    uint16_t static_voltage = (raw_static_pressure) / 1024* 5;
    uint16_t dynamic_voltage = (raw_dynamic_pressure)/ 1024 *5;

    //convert volts to Pascals (1V = 5500Pa)
    double static_pressure = (static_voltage * 5500) ; //Add Pa to these to zero the sensors to the same Pa if needed
    double dynamic_pressure = (dynamic_voltage * 5500) ;

    //calculated velocity in m/s using Bernoulli's Equation (see documentation)
    double velocity = sqrt((2 * abs(static_pressure - dynamic_pressure)) / 1000);
    return velocity;
}


double depthFunction()
{
  // this function can be called for in the race code and calculates depth

  //retrieve raw data
  double raw_static_pressure = GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN0);//analogRead(STATIC_SENSOR);

  //convert from raw data to volts (5V = 1024 raw data increments)
  double static_voltage = (raw_static_pressure/1024) * 5;

  //convert volts to Pascals (1V = 5500Pa)
  double static_pressure = static_voltage * 5500;

  //calculated depth assuming 2988.98Pa/ft
  double depth = static_pressure / 2988.98;

  return depth;

}
