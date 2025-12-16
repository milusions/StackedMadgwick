#ifndef IMU_H
#define IMU_H

#include <MPU6050_tockn.h>
#include "ArrayOperations.h"
#include <Wire.h>


class IMU {

public:
  IMU(float frequency);
  void setIMUFrequency(float frequency);
  void begin();
  void calibrate();
  void update();
  bool isUpToDate();
  float getTemp();
  float getAccX();
  float getAccY();
  float getAccZ();
  float getGyroX();
  float getGyroY();
  float getGyroZ();
  float getAngleX();
  float getAngleY();
  float getAngleZ();

private:
   float _temp, _accX, _accY, _accZ;
   float _gyroX, _gyroY, _gyroZ;
   float _angleX, _angleY, _angleZ;
   long _imuDataUpdateRoutineTimer;
   float _imuUpdateTimePeriod;
   bool _isDataUpToDate;

   const float _rad_to_deg = 180.0 / PI;


};

#endif

