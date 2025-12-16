
#ifndef SERVOS_H
#define SERVOS_H

#include <Adafruit_PWMServoDriver.h>

class Servos {

public:
 Servos();
 void init();
 int angleToPulse(int ang);
 void setServoAngle(int servoIndex, int angle);

private: 
 Adafruit_PWMServoDriver _servoPool;
 const int _SERVOMIN = 125;
 const int _SERVOMAX = 625; 

};

#endif
