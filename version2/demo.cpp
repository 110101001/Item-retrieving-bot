#include <pigpio.h>
#include "motor.h"
#include "robot_control.h"
#include <time.h>
#include <unistd.h>

int main(){
    gpioInitialise();

    moveForward(255,2);
    
    turnLeft(3);
    
    moveForward(255,2);
    
    turnLeft(3);

    robotStop();

    gpioTerminate();

    return 0;
}
