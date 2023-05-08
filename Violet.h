#include <kipr/wombat.h>

void DebugPrint(char message[]);
void followWall(int ET_PORT, int LEFTWHEEL_PORT, int RIGHTWHEEL_PORT);
void followWallBack(int ET_PORT, int LEFTWHEEL_PORT, int RIGHTWHEEL_PORT, int LEFTBUTTON_PORT, int RIGHTBUTTON_PORT);
const int DEBUG_MODE = 0;

const int ET_MIN_RANGE = 2700;
const int ET_MAX_RANGE = 2800;

void DebugPrint(char message[])
{
    if (DEBUG_MODE){
        printf("%s\n",message);
        msleep(3000);
    }
}

void followWall(int ET_PORT, int LEFTWHEEL_PORT, int RIGHTWHEEL_PORT)
{
    //Use DebugPrint to output the start of the function
    DebugPrint("Violet: START followWall\n");
    int iMaxTime = 6000;
    int iCurrentTime = 0;
    //int bDriveRight = 0;
    int iLeftWheelSpeed;
    int iRightWheelSpeed;
    while(iCurrentTime < iMaxTime){     
        printf("%d: ", analog(ET_PORT));
        if (analog(ET_PORT) >= ET_MIN_RANGE && analog(ET_PORT) <= ET_MAX_RANGE) {
            while (iCurrentTime < iMaxTime && analog(ET_PORT) >= ET_MIN_RANGE && analog(ET_PORT) <= ET_MAX_RANGE) {
            	printf("drive straight - %d\n", iCurrentTime);
        		iLeftWheelSpeed = 1000;
            	iRightWheelSpeed = 1000;
            	mav(LEFTWHEEL_PORT,iLeftWheelSpeed);
            	mav(RIGHTWHEEL_PORT,iRightWheelSpeed);
           	 	msleep(1);
                iCurrentTime += 3;
            }
        }
        if (analog(ET_PORT) > ET_MIN_RANGE) {
            while (iCurrentTime < iMaxTime && analog(ET_PORT) > ET_MAX_RANGE) {
            	printf("drive left - %d\n", iCurrentTime);
                printf("ET SENSOR = %i\n", analog(ET_PORT));
        		iLeftWheelSpeed = 800;
            	iRightWheelSpeed = 900;
            	mav(LEFTWHEEL_PORT,iLeftWheelSpeed);
            	mav(RIGHTWHEEL_PORT,iRightWheelSpeed);
                msleep(1);
                iCurrentTime += 3;
            }
            
        }
        else if (analog(ET_PORT) < ET_MIN_RANGE){ 
            while (iCurrentTime < iMaxTime && analog(ET_PORT) < ET_MAX_RANGE) {
            	printf("gentle drive right - %d\n", iCurrentTime);
                printf("ET SENSOR = %i\n", analog(ET_PORT));
        		iLeftWheelSpeed = 900;
            	iRightWheelSpeed = 800;
            	mav(LEFTWHEEL_PORT,iLeftWheelSpeed);
            	mav(RIGHTWHEEL_PORT,iRightWheelSpeed);
                msleep(1);
                iCurrentTime += 3;
            }
         }    
        
    }
}


void followWallBack(int ET_PORT, int LEFTWHEEL_PORT, int RIGHTWHEEL_PORT, int LEFTBUTTON_PORT, int RIGHTBUTTON_PORT)
{
    //int iMaxTime = 16000;
    int iCurrentTime = 0;
    //int bDriveRight = 0;
    int iLeftWheelSpeed;
    int iRightWheelSpeed;
    while(!(digital(LEFTBUTTON_PORT) || digital(RIGHTBUTTON_PORT))){     
        printf("%d: ", analog(ET_PORT));
        printf("%i: ", digital(LEFTBUTTON_PORT));
        printf("%i: ", digital(RIGHTBUTTON_PORT));
        if (analog(ET_PORT) >= ET_MIN_RANGE && analog(ET_PORT) <= ET_MAX_RANGE) {
            while (!(digital(LEFTBUTTON_PORT) || digital(RIGHTBUTTON_PORT)) && analog(ET_PORT) >= ET_MIN_RANGE && analog(ET_PORT) <= ET_MAX_RANGE) {
            	printf("drive straight - %d\n", iCurrentTime);
                printf("%i: ", digital(LEFTBUTTON_PORT));
       			printf("%i: ", digital(RIGHTBUTTON_PORT));
        		iLeftWheelSpeed = -1500;
            	iRightWheelSpeed = -1500;
            	mav(LEFTWHEEL_PORT,iLeftWheelSpeed);
            	mav(RIGHTWHEEL_PORT,iRightWheelSpeed);
           	 	msleep(1);
                iCurrentTime += 3;
            }
        }
        if (analog(ET_PORT) > ET_MIN_RANGE) {
            while (!(digital(LEFTBUTTON_PORT) || digital(RIGHTBUTTON_PORT)) && analog(ET_PORT) > ET_MAX_RANGE) {
            	printf("drive left - %d\n", iCurrentTime);
                printf("ET SENSOR = %i\n", analog(ET_PORT));
        		iLeftWheelSpeed = -200;
            	iRightWheelSpeed = -300;
            	mav(LEFTWHEEL_PORT,iLeftWheelSpeed);
            	mav(RIGHTWHEEL_PORT,iRightWheelSpeed);
                msleep(1);
                iCurrentTime += 3;
            }
            
        }
        else if (analog(ET_PORT) < ET_MIN_RANGE){ 
            while (!(digital(LEFTBUTTON_PORT) || digital(RIGHTBUTTON_PORT)) && analog(ET_PORT) < ET_MAX_RANGE) {
            	printf("gentle drive right - %d\n", iCurrentTime);
                printf("ET SENSOR = %i\n", analog(ET_PORT));
        		iLeftWheelSpeed = -1500;
            	iRightWheelSpeed = -1100;
            	mav(LEFTWHEEL_PORT,iLeftWheelSpeed);
            	mav(RIGHTWHEEL_PORT,iRightWheelSpeed);
                msleep(1);
                iCurrentTime += 3;
            }
         }    
        
    }
    printf("Left Button = %i: \n", digital(LEFTBUTTON_PORT));
    printf("Right Button = %i: \n", digital(RIGHTBUTTON_PORT));
    ao();
}