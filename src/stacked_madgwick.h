#ifndef STACKED_MADGWICK_H
#define STACKED_MADGWICK_H

#include "imu_filter_flow.h"
#include "MadgwickAHRS.h"

class StackedMadgwick {

public:
  StackedMadgwick(float samplingFrequency);
  void begin();
  float getRoll();
  float getPitch();
  float getYaw();
  void update(float gyroX, float gyroY, float gyroZ, float accX, float accY, float accZ, float magX, float magY, float magZ);
  void updateIMU(float gyroX, float gyroY, float gyroZ, float accX, float accY, float accZ);

private:
  float _samplingFrequency;
  Madgwick _mdwkFilter;
  
  /* Filter Flow for raw IMU data
  Currently, 
  Flow: raw data -> average filter --> low pass filter --> moving average filter --> filtered value */
 
  // Acceleration filters
  IMUFilterFlow _accXFilterFlow;
  IMUFilterFlow _accYFilterFlow;
  IMUFilterFlow _accZFilterFlow;

  // Gyroscopics filters
  IMUFilterFlow _gyroXFilterFlow;
  IMUFilterFlow _gyroYFilterFlow;
  IMUFilterFlow _gyroZFilterFlow;

   // Magnetic filters
  IMUFilterFlow _magXFilterFlow;
  IMUFilterFlow _magYFilterFlow;
  IMUFilterFlow _magZFilterFlow;
};


#endif