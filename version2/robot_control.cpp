#include "motor.h"
#include <pigpio.h>
#include <time.h>
#include <unistd.h>

void moveForward(int speed, int time){
    //speed 0-255
    setLeftMode(2);
    setRightMode(1);
    setLeftSpeed(speed);
    setRightSpeed(speed);
    sleep(time);
    stop();
}

void moveBackward(int speed, int time){
    setLeftMode(1);
    setRightMode(2);
    setLeftSpeed(speed);
    setRightSpeed(speed);
    sleep(time);
    stop();
}

void turnLeft(int angle){
    setLeftMode(1);
    setRightMode(1);
    setLeftSpeed(200);
    setRightSpeed(200);
    sleep(angle);
    stop();
}

void turnRight(int angle){
    setLeftMode(2);
    setRightMode(2);
    setLeftSpeed(255);
    setRightSpeed(255);
    sleep(angle);
    stop();
}

void robotStop(){
    stop();
}