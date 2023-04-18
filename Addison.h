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
    mrp(LEFT_MOTOR_PORT,-1000,3000);
    msleep(2500);
}

void pickUpCube(int CLAW_PORT, int CLAW_CLOSE)
{
    DebugPrint("AF pick up cube");
	set_servo_position(CLAW_PORT, CLAW_CLOSE); 
        
    msleep(1000);

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
    msleep(150);
    
    ao();
}