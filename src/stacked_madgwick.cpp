#include "stacked_madgwick.h"

StackedMadgwick::StackedMadgwick(float samplingFrequency) {
  _samplingFrequency = samplingFrequency;
  _accXFilterFlow = IMUFilterFlow();
  _accYFilterFlow = IMUFilterFlow();
  _accZFilterFlow = IMUFilterFlow();

  _gyroXFilterFlow = IMUFilterFlow();
  _gyroYFilterFlow = IMUFilterFlow();
  _gyroZFilterFlow = IMUFilterFlow();

  _magXFilterFlow = IMUFilterFlow();
  _magYFilterFlow = IMUFilterFlow();
  _magZFilterFlow = IMUFilterFlow();
}

void StackedMadgwick::begin() {
  _mdwkFilter.begin(_samplingFrequency);
}

float StackedMadgwick::getRoll() {
  return _mdwkFilter.getRoll();
}

float StackedMadgwick::getPitch() {
  return _mdwkFilter.getPitch();
}
float StackedMadgwick::getYaw() {
  return _mdwkFilter.getYaw();
}
void StackedMadgwick::updateIMU(float gyroX, float gyroY, float gyroZ, float accX, float accY, float accZ) {

  _accXFilterFlow.pushValue(accX);
  _accYFilterFlow.pushValue(accY);
  _accZFilterFlow.pushValue(accZ);

  _gyroXFilterFlow.pushValue(gyroX);
  _gyroYFilterFlow.pushValue(gyroY);
  _gyroZFilterFlow.pushValue(gyroZ);

  float filteredAccX = _accXFilterFlow.getFilteredValue();
  float filteredAccY = _accYFilterFlow.getFilteredValue();
  float filteredAccZ = _accZFilterFlow.getFilteredValue();

  float filteredGyroX = _gyroXFilterFlow.getFilteredValue();
  float filteredGyroY = _gyroYFilterFlow.getFilteredValue();
  float filteredGyroZ = _gyroZFilterFlow.getFilteredValue();

  _mdwkFilter.updateIMU(filteredGyroX, filteredGyroY, filteredGyroZ, filteredAccX, filteredAccY, filteredAccZ);
}

void StackedMadgwick::update(float gyroX, float gyroY, float gyroZ, float accX, float accY, float accZ, float magX, float magY, float magZ) {

  _accXFilterFlow.pushValue(accX);
  _accYFilterFlow.pushValue(accY);
  _accZFilterFlow.pushValue(accZ);

  _gyroXFilterFlow.pushValue(gyroX);
  _gyroYFilterFlow.pushValue(gyroY);
  _gyroZFilterFlow.pushValue(gyroZ);

  _magXFilterFlow.pushValue(magX);
  _magYFilterFlow.pushValue(magY);
  _magZFilterFlow.pushValue(accZ);

  float filteredAccX = _accXFilterFlow.getFilteredValue();
  float filteredAccY = _accYFilterFlow.getFilteredValue();
  float filteredAccZ = _accZFilterFlow.getFilteredValue();

  float filteredGyroX = _gyroXFilterFlow.getFilteredValue();
  float filteredGyroY = _gyroYFilterFlow.getFilteredValue();
  float filteredGyroZ = _gyroZFilterFlow.getFilteredValue();

  float filteredMagX = _magXFilterFlow.getFilteredValue();
  float filteredMagY = _magYFilterFlow.getFilteredValue();
  float filteredMagZ = _magZFilterFlow.getFilteredValue();

  _mdwkFilter.update(filteredGyroX, filteredGyroY, filteredGyroZ, filteredAccX, filteredAccY, filteredAccZ, filteredMagX, filteredMagY, filteredMagZ);
}