#include <kipr/wombat.h>
#include <Violet.h>
#include <Addison.h>
#include <Madelyn.h>
#include <Eddie.h>
#include <Thomas.h>

const int RMP=0;//right motor
const int LMP=3;//left motor
const int SP=0;//servo
const int ETS=1;//et sensor
const int LS=0;//touch sensor
const int THP=0;//top hat
const int LBP=8;//left button
const int RBP=9;//right button
const int RIGHT_MOTOR_PORT=0;
const int LEFT_MOTOR_PORT=3;
const int CLAW_CLOSE = 945;
const int CLAW_OPEN = 2047;
const int SPEED=1500;

int main()
{

    printf("Hello World\n");
/************ Let's get wait for light implemented **************/
    //Wait for light MP 
    //Located in Madelyn .h
    //shut down in 120 seconds
    
    shut_down_in (120);
    
    set_servo_enabled(SP,1);
    
    releaseCube(SP,CLAW_OPEN);
    //open claw
    //Located in Addison.h
    
/********* This turn looks to be slightly to large - check if we should adjust ***********/    
    //turn right 90 degrees AF
    turnLeft(RIGHT_MOTOR_PORT,LEFT_MOTOR_PORT);
    DebugPrint("TURN_RIGHT COMPLETED\n");
    //Find Wall with ET Sensor MP
    //findWall(ETS,RMP,LMP);
    
/********* Something isn't working properly here to pick up the cube *******************/
/********* CHECK: how long do we follow the wall? **************************************/
    //move forward following wall with ET Sensor VN
    followWall(ETS,LMP,RMP);
    DebugPrint("FOLLOW_WALL COMPLETED\n");
   
    //is robot alighned to cube ER
    alignToCube(LMP,RMP,SPEED);
    DebugPrint("FOLLOW_WALL COMPLETED\n");
    
/*********** Why is the speed hard coded here?  ****************************************/
/*********** We should be using the constant variable **********************************/
    driveToTouch(LMP,RMP,1000,LS); //1000;
    DebugPrint("DRIVE_TO_TOUCH COMPLETED\n");
    //Pick up cube AF
    backUp (RMP,LMP);
    
    
    pickUpCube(SP,CLAW_CLOSE);

    
    followWallBack(ETS,LMP,RMP, LBP, RBP);
    //set_servo_enabled(SP,0);

    //Find wall with ET sensor MP
    //findWall(ETS,RMP,LMP);
    //Located in Madelyn.h 
    //move backwards following wall w/ et sensor VN
    
    //are touch sensors engaged VN
    
    //move forward TK
    //Is there a black line TK
    findBlackLine(1000, THP, LMP, RMP);
	//Located in Thomas.h
/*******  can we just line follow here? **********/      
    //turn LEFT 90 degrees TK
    turnLeft90(1000, RMP);
    //follow black line TK
    fLineToLimit(LMP,RMP,SPEED,THP, 3000, 300);
    //turn LEFT 90 degrees TK
    turnLeft90(1000, RMP);
    //Located in Thomas.h
 //Follow Black line ER
    int black= 3000;
    fblacklineToTouch(LMP,RMP,SPEED,THP,LS,black);
    //is lever sensor Engaged VN  
/********** Why are we releasing the cube before the lever sensor is hit? **************/
    //release cube AF
    releaseCube(1,CLAW_OPEN);
    //Located in Addison.h
    
  
    //is lever sensor Engaged VN  
   
    //  disable_servos();
    return 0;
}