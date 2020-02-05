/*#include "src/I2Cdev.h"
#include "src/MPU6050.h"
#include "Wire.h"
#include "common.h"

//#define I2CDEV_IMPLEMENTATION I2CDEV_ARDUINO_WIRE
#define NUM_CALIBRATION_ITER 50

MPU6050 accelgyro(0x68);

void accel_init(void) {
    Wire.begin();
    accelgyro.initialize();
    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");

    //Calibrate accelerometer
    Serial.println("Calibrating...");

    //Clear stored offsets
    accelgyro.setXGyroOffset(0);
    accelgyro.setYGyroOffset(0);
    accelgyro.setZGyroOffset(0);

    //Store running totals
    int32_t x = 0,y = 0,z = 0;

    //Take NUM_CALIBRATION_ITER readings in a row
    for (size_t i = 0; i < NUM_CALIBRATION_ITER; i++) {
        int16_t tx, ty, tz;
        accelgyro.getRotation(&tx, &ty, &tz);
        x += tx;
        y += ty;
        z += tz;
        delay(300);
        Serial.print("x = ");
        Serial.print(tx, DEC);
        Serial.print(" y = ");
        Serial.print(ty, DEC);
        Serial.print(" z = ");
        Serial.println(tz, DEC);
    }

    //Find average reading
    //Divide by 4 for who knows why
    int16_t x_of = (0 - (x / NUM_CALIBRATION_ITER) ) / 4;
    int16_t y_of = (0 - (y / NUM_CALIBRATION_ITER) ) / 4;
    int16_t z_of = (0 - (z / NUM_CALIBRATION_ITER) ) / 4;

    //Set offsets
    Serial.print("X offset = ");
    Serial.print(x_of, DEC);
    Serial.print(" Y offset = ");
    Serial.print(y_of, DEC);
    Serial.print(" Z offset = ");
    Serial.println(z_of, DEC);
    
    accelgyro.setXGyroOffset(x_of);
    accelgyro.setYGyroOffset(y_of);
    accelgyro.setZGyroOffset(z_of);
        
    Serial.println("Calibration Complete");

}

void getGyroPos(accelData *accelStruct) {
    accelgyro.getRotation( &(accelStruct->roll), &(accelStruct->pitch), &(accelStruct->yaw) );
}
*/

