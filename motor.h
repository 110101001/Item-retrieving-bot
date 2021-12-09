#ifndef _motor_
#define _motor_
#include <pigpio.h>

void initialMotors();
void setLeftMode(int mode);
void setRightMode(int mode);
void setLeftSpeed(int speedValue);
void setRightSpeed(int speedValue);
void stop();

#endif
