#ifndef COMMON_H_
#define COMMON_H_

#include <stdint.h>

//Structs
typedef struct {
    int8_t left;  //Control surface position in degrees. 
    int8_t right; //0 degrees is straight 
    int8_t top;
    int8_t bottom;
} actuatorData;

typedef struct {
    int16_t roll; //Accelerometer position in degrees
    int16_t pitch;
    int16_t yaw;
} accelData;

typedef struct {
    uint16_t rpm;
    double velocity; 
    double depth;
    accelData accelPos;
//    actuatorData actuatorPos;
} dataStruct;

bool logData(dataStruct *dataToLog);
void datalogger_init();

void getGyroPos(accelData *accelStruct);
void accel_init();

#endif
