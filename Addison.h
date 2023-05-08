#include <kipr/wombat.h>

void turnRight(int RIGHT_MOTOR_PORT, int LEFT_MOTOR_PORT);
void pickUpCube(int CLAW_PORT,int CLAW_CLOSE);
void releaseCube(int CLAW_PORT,int CLAW_OPEN);

void turnRight(int RIGHT_MOTOR_PORT, int LEFT_MOTOR_PORT)
{
    DebugPrint("AF turning right");
	//move_to_position(RIGHT_MOTOR_PORT,-500,-1500/4);
    //move_to_position(LEFT_MOTOR_PORT,500,1500/4);
    //msleep(3000);
    mrp(LEFT_MOTOR_PORT,-1000,3000); //changed 5/1/23 from 3000 to 2556 //this should be mav
    //mav(RIGHT_MOTOR_PORT,-700);
    //mav(LEFT_MOTOR_PORT,900);
    
    //cmpc(RIGHT_MOTOR_PORT);
    //cmpc(LEFT_MOTOR_PORT);
 /****** suggest to tweak the click value to something slightly less *******/
    //mtp(LEFT_MOTOR_PORT,1000, 3000);
    
    msleep(4000);
}

void pickUpCube(int CLAW_PORT, int CLAW_CLOSE)
{
    DebugPrint("AF pick up cube");
	set_servo_position(CLAW_PORT, CLAW_CLOSE); 
        
    //msleep(1000);

}


void releaseCube(int CLAW_PORT,int CLAW_OPEN)
{
    DebugPrint("AF release cube");
    set_servo_position(CLAW_PORT, CLAW_OPEN);  
}
void backUp (int RIGHT_MOTOR_PORT, int LEFT_MOTOR_PORT)
{
    DebugPrint("AF back up");
    mav(RIGHT_MOTOR_PORT,-1500);
    mav(LEFT_MOTOR_PORT,-1500);
    msleep(100);
    
    ao();
}