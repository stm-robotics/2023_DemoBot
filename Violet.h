#include <kipr/wombat.h>
void DebugPrint(char message[]);
void followWall(int ET_PORT, int LEFTWHEEL_PORT, int RIGHTWHEEL_PORT);

const int DEBUG_MODE = 1;

const int ET_MIN_RANGE = 2700;
const int ET_MAX_RANGE = 2800;

void DebugPrint(char message[])
{
    if (DEBUG_MODE){
        printf("%s\n",message);
        msleep(300);
    }
}


void followWall(int ET_PORT, int LEFTWHEEL_PORT, int RIGHTWHEEL_PORT)
{
    int iMaxIterations = 10000;
    int iCounter = 0;
    int bDriveRight = 0;
    int iLeftWheelSpeed;
    int iRightWheelSpeed;
    while(iCounter < iMaxIterations){
        //read et sensor
        //if et sensor greater or equal to 2900, change direction
       /* if(analog(ET_PORT) >= ET_WALL){
            bDriveRight = !bDriveRight;
        }*/
       // int iETVal = analog(ET_PORT);
      
        printf("%d: ", analog(ET_PORT));
        if(analog(ET_PORT) > ET_MIN_RANGE && analog(ET_PORT) < ET_MAX_RANGE){
            printf("drive straight\n");
        	iLeftWheelSpeed = 550;
            iRightWheelSpeed = 550;
            mav(LEFTWHEEL_PORT,iLeftWheelSpeed);
            mav(RIGHTWHEEL_PORT,iRightWheelSpeed);
         
        }
        else if (analog(ET_PORT) >= ET_MIN_RANGE){
            printf("drive left\n");
        	iLeftWheelSpeed = -450;
            iRightWheelSpeed = 550;
            mav(LEFTWHEEL_PORT,iLeftWheelSpeed);
            mav(RIGHTWHEEL_PORT,iRightWheelSpeed);
            
        }
         else if (analog(ET_PORT) <= ET_MAX_RANGE){ 
             printf("drive right\n");
            
        	iLeftWheelSpeed = 550;
            iRightWheelSpeed = -450;
            mav(LEFTWHEEL_PORT,iLeftWheelSpeed);
            mav(RIGHTWHEEL_PORT,iRightWheelSpeed);
           
         }
        
        
        
        iCounter += 1;
    }
 
  
}

void moveBackwards()
{
    
}