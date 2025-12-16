#include "imu.h"

MPU6050 _mpu6050(Wire);


IMU::IMU(float frequency) {
  _temp = _accX = _accY = _accZ = 0.0;
  _gyroX = _gyroY = _gyroZ = 0;
  _angleX = _angleY = _angleZ = 0;
  _imuDataUpdateRoutineTimer = 0;
  _imuUpdateTimePeriod = 1000.0 / frequency;
  _isDataUpToDate = false;
}

bool IMU::isUpToDate() {
  return _isDataUpToDate;
}
void IMU::setIMUFrequency(float frequency) {
  _imuUpdateTimePeriod = 1000.0 / frequency;
}

void IMU::begin() {
  Wire.begin();
  _mpu6050.begin();
}

void IMU::calibrate() {
  _mpu6050.calcGyroOffsets(true);
}

void IMU::update() {
  _mpu6050.update();

  if (millis() - _imuDataUpdateRoutineTimer > _imuUpdateTimePeriod) {
    _temp = _mpu6050.getTemp();
    _accX = _mpu6050.getAccX();
    _accY = _mpu6050.getAccY();
    _accZ = _mpu6050.getAccZ();
    _gyroX = _mpu6050.getGyroX();
    _gyroY = _mpu6050.getGyroY();
    _gyroZ = _mpu6050.getGyroZ();
    _angleX = _mpu6050.getAngleX();
    _angleY = _mpu6050.getAngleY();
    _angleZ = _mpu6050.getAngleZ();
    _imuDataUpdateRoutineTimer = millis();
    _isDataUpToDate = true;
    return;
  }
  _isDataUpToDate = false;
}

float IMU::getTemp() {
  return _temp;
}

float IMU::getAccX() {
  return _accX;
}

float IMU::getAccY() {
  return _accY;
}
float IMU::getAccZ() {
  return _accZ;
}

float IMU::getGyroX() {
  return _gyroX;
}

float IMU::getGyroY() {
  return _gyroY;
}

float IMU::getGyroZ() {
  return _gyroZ;
}

float IMU::getAngleX() {
  return _angleX;
}

float IMU::getAngleY() {
  return _angleY;
}

float IMU::getAngleZ() {
  return _angleZ;
}




