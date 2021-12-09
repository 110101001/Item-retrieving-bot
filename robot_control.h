#ifndef _robot_control_
#define _robot_control_
#include <pigpio.h>
#include "motor.h"

void initRobot();
void moveForward(int speed);
void moveBackward(int speed);
void robotStop();
void turnLeft(int speed);
void turnRight(int speed);

#endif