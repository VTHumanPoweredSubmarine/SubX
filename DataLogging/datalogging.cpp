/*`1#include "Arduino.h"
#include "common.h"


bool logData(dataStruct *dataToLog) {

    unsigned long timeStamp = millis();
    
    Serial.print( (timeStamp / 3600000), DEC);
    Serial.print(":");
    Serial.print( (timeStamp / 60000) % 60, DEC);
    Serial.print(":");
    Serial.println( (timeStamp / 1000) % 60, DEC);
    
    Serial.print("RPM = ");
    Serial.println(dataToLog->rpm, DEC);



    Serial.print("Velocity = ");
    Serial.println(dataToLog->velocity, DEC);

    Serial.print("Depth = ");
    Serial.println(dataToLog->depth, 4);

    Serial.print("Roll = ");
    Serial.print(dataToLog->accelPos.roll, DEC);
    Serial.print(", Pitch = ");
    Serial.print(dataToLog->accelPos.pitch, DEC);
    Serial.print(", Yaw = ");
    Serial.println(dataToLog->accelPos.yaw, DEC);

    
    
    Serial.println(" ");
    Serial.println(" ");
   

    
    return 0;
}

void datalogger_init(void){
    
}
    */
