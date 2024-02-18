#include "vex.h"



Odom odom;
void no_auton(){
  chassis.clearSensors(false);

}

int auton_odom(){
  chassis.drive_odometry();
  return 0;
}

//Delay can be tweaked to improve timing - Added after 48pt run (1 sec)
float green_cube_delay = 0;

void left_auton(){
  printf("Left Auton Called\n");
  
  chassis.clearSensors(false);
  Outtake.outtake_motor_group.setPosition(0,degrees);
  

  //Hack Solution, run thread in auton_odom
  vex::task odometry(auton_odom);

  //Commented Out for my sanity while I test
  Intake.set_intake(FORWARD);
  

  //Picking Up first Row of greens
  chassis.DriveFor(25);

  /*Old
  chassis.DriveFor(5);
  wait(green_cube_delay, seconds);
  chassis.DriveFor(5);
  wait(green_cube_delay,seconds);
  chassis.DriveFor(6);
  wait(green_cube_delay,seconds);
  chassis.DriveFor(7);
  */

  //Reversing into goal
  chassis.DriveFor(-20);
  chassis.TurnTo(60); //60 Original
  chassis.DriveFor(-35);
  //chassis.DriveFor(-2);

  //Check if intake is jammed, and unjam it
  printf("%f", Intake.intake_motor.current(pct));
  if(Intake.intake_motor.current(pct) > 60){
  Intake.set_intake(REVERSE);
  wait(0.25,sec);
  Intake.set_intake(FORWARD);
  wait(0.25,sec);
  Intake.set_intake(REVERSE);
  wait(0.25,sec);
  Intake.set_intake(FORWARD);
  wait(1,sec);
  }
  

  //Dumping
  Outtake.set_outtake(UP);
  wait(2.4,seconds);
  Outtake.set_outtake(STOP);
  Outtake.outtake_motor.stop(hold);
  Outtake.outtake_motor_2.stop(hold);
  wait(0.5, seconds);
  Outtake.outtake_motor_group.spinToPosition(0,degrees,false);

  //
  
    
    //while(1){wait(1,seconds);}
  
  

}

void right_auton(){
  printf("Right Auton Called\n");
  
  chassis.clearSensors(false);
  Outtake.outtake_motor_group.setPosition(0,degrees);
  

  //Hack Solution, run thread in auton_odom
  vex::task odometry(auton_odom);

  //Commented Out for my sanity while I test
  Intake.set_intake(FORWARD);
  

  //Picking Up first Row of greens
  chassis.DriveFor(25);
  chassis.DriveFor(20);

  /* Old 
  chassis.DriveFor(5);
  wait(green_cube_delay, seconds);
  chassis.DriveFor(5);
  wait(green_cube_delay,seconds);
  chassis.DriveFor(6);
  wait(green_cube_delay,seconds);
  chassis.DriveFor(7);
  wait(green_cube_delay,seconds);
  
  */
 //Old 140
 chassis.TurnTo(-155);



  //Stop intake
  //Intake.set_intake(STOP);
  

  //Backing into goal
  chassis.DriveFor(90);
  chassis.DriveFor(20);
  chassis.TurnTo(-60);
  chassis.DriveFor(-50);
  chassis.DriveFor(-2);


  //Check if intake is jammed, and unjam it
  printf("%f", Intake.intake_motor.current(pct));
  if(Intake.intake_motor.current(pct) > 60){
  Intake.set_intake(REVERSE);
  wait(0.25,sec);
  Intake.set_intake(FORWARD);
  wait(0.25,sec);
  Intake.set_intake(REVERSE);
  wait(0.25,sec);
  Intake.set_intake(FORWARD);
  wait(1,sec);
  }

  //Dumping
  Outtake.set_outtake(UP);
  wait(2.4,seconds);
  Outtake.set_outtake(STOP);
  Outtake.outtake_motor.stop(hold);
  Outtake.outtake_motor_2.stop(hold);
  wait(0.5, seconds);
  Outtake.outtake_motor_group.spinToPosition(0,degrees,false);


  //while(true){ wait(1,seconds);}
}



void mid_auton(){
  printf("Mid Auton Called\n");
  
  chassis.clearSensors(false);
  Outtake.outtake_motor_group.setPosition(0,degrees);
  

  //Hack Solution, run thread in auton_odom
  vex::task odometry(auton_odom);

  //Drive forward to knock off red blocks or Partial Park
  chassis.DriveFor(30);
  chassis.DriveFor(20);
  
}
//Added this to test viability of partial parking directly from the second red block
//Not tested yet - refer to text conversation
void last_red_block_auton(){
  printf("Red Block and Park Auton Called\n");
  
  chassis.clearSensors(false);
  Outtake.outtake_motor_group.setPosition(0,degrees);
  

  //Hack Solution, run thread in auton_odom
  vex::task odometry(auton_odom);

  //Drive forward to knock off red blocks or Partial Park
  chassis.DriveFor(30);
  chassis.DriveFor(20);

  wait(0.25,seconds);

  //Clear the red block stand
  chassis.DriveFor(-10);

  //Partial Park
  chassis.TurnTo(-50);
  chassis.DriveFor(30);
  chassis.DriveFor(15);


  


}
void second_basket(){

  printf("Second Auton Called\n");
  
  chassis.clearSensors(false);
  Outtake.outtake_motor_group.setPosition(0,degrees);
  

  //Hack Solution, run thread in auton_odom
  vex::task odometry(auton_odom);

  //Commented Out for my sanity while I test
  Intake.set_intake(FORWARD);
  

  //Picking Up first Row of greens
  chassis.DriveFor(5);
  wait(green_cube_delay, seconds);
  chassis.DriveFor(5);
  wait(green_cube_delay,seconds);
  
  chassis.TurnTo(-120);

  //Stop intake
  Intake.set_intake(STOP);

  chassis.DriveFor(18);

  chassis.TurnTo(-50);
  //chassis.TurnTo(-60);

  chassis.DriveFor(5);
  chassis.DriveFor(-30);
  chassis.DriveFor(-5);
  

  //Check if intake is jammed, and unjam it
  printf("%f", Intake.intake_motor.current(pct));
  if(Intake.intake_motor.current(pct) > 60){
  Intake.set_intake(REVERSE);
  wait(0.25,sec);
  Intake.set_intake(FORWARD);
  wait(0.25,sec);
  Intake.set_intake(REVERSE);
  wait(0.25,sec);
  Intake.set_intake(FORWARD);
  wait(1,sec);
  }


  //Dumping
  Outtake.set_outtake(UP);
  wait(2.4,seconds);
  Outtake.set_outtake(STOP);
  Outtake.outtake_motor.stop(hold);
  Outtake.outtake_motor_2.stop(hold);
  wait(0.5, seconds);
  Outtake.outtake_motor_group.spinToPosition(0,degrees,false);


}

void third_basket(){
  Intake.set_intake(FORWARD);
  chassis.DriveFor(16);
  wait(0.5,seconds);
  chassis.DriveFor(7);
  wait(0.5, seconds);
  chassis.DriveFor(3);

  chassis.TurnTo(-140);

  chassis.DriveFor(-30);

  //chassis.TurnTo(-160);

  chassis.DriveFor(-15);

  //Dumping
  Outtake.set_outtake(UP);
  wait(2.4,seconds);
  Outtake.set_outtake(STOP);
  Outtake.outtake_motor.stop(hold);
  Outtake.outtake_motor_2.stop(hold);
  wait(0.5, seconds);
  Outtake.outtake_motor_group.spinToPosition(0,degrees,false);

  Intake.set_intake(OFF);

  chassis.DriveFor(5);

  chassis.TurnTo(-130);

  chassis.DriveFor(15);

  chassis.TurnTo(-45);
  chassis.DriveFor(10);
  chassis.DriveFor(-5);
  chassis.TurnTo(-85);

  chassis.DriveFor(30);

  chassis.TurnTo(-45);

  chassis.DriveFor(10);
  chassis.DriveFor(-5);

  chassis.TurnTo(-70);

  chassis.DriveFor(30);
  chassis.TurnTo(-45);
  chassis.DriveFor(15);




  

  

}

void red_block(){
    
    chassis.DriveFor(5);
    chassis.TurnFor(30);
    chassis.DriveFor(20);
}

void two_green(){
  chassis.DriveFor(2);
  chassis.TurnTo(-40);
  chassis.DriveFor(45);

  chassis.TurnTo(-30);
  Intake.set_intake(FORWARD);
  chassis.DriveFor(10);

  chassis.TurnTo(-50);
  chassis.DriveFor(20);

 chassis.DriveFor(-35);
 chassis.clearSensors(false);

 chassis.TurnTo(-80); 
 chassis.DriveFor(-20);

 chassis.TurnTo(-30);
 chassis.DriveFor(-30);






  //chassis.TurnFor(-40);
  //chassis.DriveFor(10);

  
  

}

void test4green(){
  chassis.DriveFor(27);
  chassis.TurnTo(97);

  //First
  Intake.set_intake(FORWARD);
  chassis.DriveFor(6);

  chassis.DriveFor(-8);

  //Check if intake is jammed, and unjam it
  printf("%f", Intake.intake_motor.current(pct));
  if(Intake.intake_motor.current(pct) > 60){
  Intake.set_intake(REVERSE);
  wait(0.25,sec);
  Intake.set_intake(FORWARD);
  wait(0.25,sec);
  Intake.set_intake(REVERSE);
  wait(0.25,sec);
  Intake.set_intake(FORWARD);
  wait(1,sec);
  }

  chassis.TurnTo(83);

  //Second 
  chassis.DriveFor(12);

  chassis.DriveFor(-15);

  //Third
  //chassis.TurnTo(85);
  //chassis.DriveFor(15);

  //chassis.DriveFor(-5);

  //Park
  //60
  chassis.TurnTo(-165);
  chassis.DriveFor(-10);
  //Origanlly 150
  chassis.TurnTo(-135);

  chassis.DriveFor(-20);


  //Originally -200
  chassis.TurnTo(-210);

  chassis.DriveFor(10);

  chassis.TurnTo(-135);

  chassis.DriveFor(-30);
  

  //chassis.DriveFor(-15);
  //chassis.TurnTo(-150);
 //chassis.DriveFor(-20);

 //Check if intake is jammed, and unjam it
  printf("%f", Intake.intake_motor.current(pct));
  if(Intake.intake_motor.current(pct) > 60){
  Intake.set_intake(REVERSE);
  wait(0.25,sec);
  Intake.set_intake(FORWARD);
  wait(0.25,sec);
  Intake.set_intake(REVERSE);
  wait(0.25,sec);
  Intake.set_intake(FORWARD);
  wait(2,sec);
  }

  //Dumping
  Outtake.set_outtake(UP);
  wait(2.4,seconds);
  Outtake.set_outtake(STOP);
  Outtake.outtake_motor.stop(hold);
  Outtake.outtake_motor_2.stop(hold);
  wait(0.5, seconds);
  Outtake.outtake_motor_group.spinToPosition(0,degrees,false);

  Intake.set_intake(OFF);

  Intake.set_intake(REVERSE);


  /*
  //Clear the wall
  chassis.DriveFor(3);
  chassis.TurnTo(-130);

  chassis.DriveFor(4);
  chassis.TurnTo(-85);

  chassis.DriveFor(30);
  */
  




}