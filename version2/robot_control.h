#ifndef _robot_control_
#define _robot_control_
#include <pigpio.h>
#include "motor.h"

void moveForward(int speed, int time);
void moveBackward(int speed, int time);
void robotStop();
void turnLeft(int angle);
void turnRight(int angle);

#endif