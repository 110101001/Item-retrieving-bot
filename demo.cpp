#include<pigpio.h>
#include"motor.h"
#include"robot_control.h"
#include<unistd.h>


int main(){
	
    gpioInitialise();

    moveForward(255);
    
    sleep(3);
    
    turnLeft(255);
    
    sleep(3);
    
    moveForward(255);
    
    sleep(3);
    
    turnRight(255);
    
    sleep(3);

    robotStop();

    gpioTerminate();


}
