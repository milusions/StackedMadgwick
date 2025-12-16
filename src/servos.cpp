#include "servos.h"

Servos::Servos() {
  _servoPool = Adafruit_PWMServoDriver(0x40);
}
void Servos::init() {
  _servoPool.begin();
  _servoPool.setPWMFreq(60);
}
void Servos::setServoAngle(int servoIndex, int angle) {
  _servoPool.setPWM(servoIndex, 0, angleToPulse(angle));
}

int Servos::angleToPulse(int ang) {
  int pulse = map(ang, 0, 180, _SERVOMIN, _SERVOMAX);
  return pulse;
}
