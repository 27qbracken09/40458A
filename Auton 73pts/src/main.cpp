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


//Declare Drive Chassis, L, R, Gyro, Wheel Travel(inches) 7.874
Drive chassis(PORT4,PORT11,PORT1,15.758);




int main() {

    chassis.SetPID(0.6,0,0.2,0,2,3000,150000, 1);
    chassis.SetTurnPID(1.5,0,0.5,0,2,500,150000, 1);
	
    Brain.Screen.print("Quinn's Code V1.1\n");
    Brain.Screen.print("Battery: ");
    Brain.Screen.print("%i",Brain.Battery.capacity());
    Brain.Screen.print("%\n");

    printf("Quinn's Code V1.1\n");
    printf("Battery: %i Percent\n\n", Brain.Battery.capacity());
    
    
    
    controllerInit();
    chassis.clearSensors(false);
    
    //two_green();
    //test4green();
    //right_auton();    
    //vex::thread thread1 = thread(Touchledtest);
    //left_auton();
    //right_auton();
    //plus_auton();

    //chassis.TurnTo(-90);
    

    

    //Wait to set up auton, because I don't have a touchled
    //second_basket();

    
    
   

    

    
    

    /*
    while(1) {
        if (drivemethod == ARCADE){chassis.update(ARCADE);}
        if (drivemethod == TANK){chassis.update(TANK);}
        
        this_thread::sleep_for(10);
    }
    */
}


