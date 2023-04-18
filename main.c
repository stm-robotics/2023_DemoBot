#include <Violet.h>
#include <kipr/wombat.h>
#include <Addison.h>
#include <Madelyn.h>
#include <Eddie.h>
#include <Thomas.h>


const int RMP=0;//right motor
const int LMP=3;//left motor
const int SP=1;//servo
const int ETS=1;//et sensor
const int LS=0;//touch sensor
const int THP=0;//top hat
const int CLAW_CLOSE = 770;
const int CLAW_OPEN = 2045;
const int SPEED=1500;

int main()
{
    printf("Hello World\n");
    
    releaseCube(SP,CLAW_OPEN);
    //open claw
    //Located in Addison.h
    
     set_servo_enabled(SP,1);
     //Wait for light MP 
    //Located in Madelyn .h
    //shut down in 120 seconds
    shut_down_in (120);
    
    //turn right 90 degrees AF
    turnRight(RMP,LMP);
    
    //Find Wall with ET Sensor MP
    //findWall(ETS,RMP,LMP);
    
    //move forward following wall with ET Sensor VN
    followWall(ETS,LMP,RMP);
   
    //is robot alighned to cube ER
    alignToCube(LMP,RMP,SPEED);
    driveToTouch(LMP,RMP,1000,LS);
    //Pick up cube AF
    backUp (RMP,LMP);
    pickUpCube(SP,CLAW_CLOSE);
    set_servo_enabled(SP,0);
return 0;
    //Find wall with ET sensor MP
    findWall(ETS,RMP,LMP);
    //Located in Madelyn.h 
    //move backwards following wall w/ et sensor VN
    
    //are tougch sensors engaged VN
  
    //move forward TK
    //Is there a black line TK
    findBlackLine(1000, THP, LMP, RMP);
    //Located in Thomas.h
    //turn LEFT 90 degrees TK
    turnLeft90(1000, RMP);
    //follow black line TK
    fLineToLimit(LMP,RMP,SPEED,THP, 3000, 300);
    //turn LEFT 90 degrees TK
    turnLeft90(1000, RMP);
    //Located in Thomas.h
    //Follow Black line ER
    int black= (3390 + 192) / 2;
    fblacklineToTouch(LMP,RMP,SPEED,THP,LS, black);
    //is lever sensor Engaged VN
    
    //release cube AF
    releaseCube(1,CLAW_OPEN);
  //Located in Addison.h
    //  disable_servos();
    return 0;
}