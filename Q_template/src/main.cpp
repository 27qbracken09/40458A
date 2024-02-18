/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Quinn                                                     */
/*    Created:      4/13/2023, 2:33:52 PM                                     */
/*    Description:  IQ2 project                                               */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"


using namespace vex;


//Declare Drive Chassis, L, R, Gyro, Wheel Travel(inches)
Drive chassis(PORT4,PORT11, PORT1,7.874);


int main() {

    chassis.SetPID(1,0,0,0,2,5000,10000, 0);
	
    Brain.Screen.print("Quinn's Code V1.1\n");
    Brain.Screen.print("Battery: ");
    Brain.Screen.print("%i",Brain.Battery.capacity());
    Brain.Screen.print("%\n");

    printf("Quinn's Code V1.1\n");
    printf("Battery: %i Percent\n\n", Brain.Battery.capacity());

    Outtake.outtake_motor_group.setPosition(0, deg);
    
    
    
    controllerInit();
    //vex::thread thread1 = thread(Touchledtest);
    this_thread::sleep_for(100);
    //left_auton();

    
    while(1) {
        //if (drivemethod == ARCADE){chassis.update(ARCADE);}
        //if (drivemethod == TANK){chassis.update(TANK);}
        chassis.update(ARCADE);


        double L_velocity = chassis.L.velocity(pct);
        double R_velocity = chassis.R.velocity(pct);
        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("%3.2f", L_velocity);

        Brain.Screen.setCursor(2,1);
        Brain.Screen.print("%3.2f", R_velocity);

        //printf("Left: %3.2f\n", L_velocity);
        //printf("Right: %3.2f\n", R_velocity);


        
        
        
        this_thread::sleep_for(50);
    }
}