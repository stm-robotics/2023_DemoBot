#include <kipr/wombat.h>

void turnRight(int RIGHT_MOTOR_PORT, int LEFT_MOTOR_PORT);
void pickUpCube(int CLAW_PORT,int CLAW_CLOSE);
void releaseCube(int CLAW_PORT,int CLAW_OPEN);

void turnRight(int RIGHT_MOTOR_PORT, int LEFT_MOTOR_PORT)
{
	move_to_position(0,-500,1500/4);
    move_to_position(3,500,1500/4);
    
    
}

void pickUpCube(int CLAW_PORT, int CLAW_CLOSE)
{
	set_servo_position(CLAW_PORT, CLAW_CLOSE); 
    msleep(1000);

}


void releaseCube(int CLAW_PORT,int CLAW_OPEN)
{
    set_servo_position(CLAW_PORT, CLAW_OPEN);
    
}
