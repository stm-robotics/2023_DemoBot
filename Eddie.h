#include <kipr/wombat.h>
//variable definitions constant variable
//const int lmp=3;
//const int rmp=0;
//const int rmv=-225;
//const int lmv=225;
//function definition
void alignToCube(int lmp,int rmp, int Speed);
void fblacklineToTouch(int Lmp, int Rmp, int Speed, int Tpp, int Tsp, int black);
int lineFollow(int Lmp, int Rmp, int Speed, int Tpp, int black);
void fLineToLimit(int Lmp, int Rmp, int Speed, int Tpp, int black, int limit);

const int COLOR_BLACK = 1;
const int COLOR_WHITE = 0;

void alignToCube(int Lmp, int Rmp, int Speed)
{
    DebugPrint("ER align cube");
    //using motor0 and motor3 (motor0 backward and motor3 forward)
    mav(Rmp,-1*Speed);
    mav(Lmp,Speed);
    msleep(150);
    alloff();
}
	
//-----------------------------------------------------------------------------------------------------------------------------
void fblacklineToTouch(int Lmp, int Rmp, int Speed, int Tpp, int Tsp, int black)
//lmp=leftmotorport
//rmp=rightmotorport
//speed; it defines itself
//tpp=tophatport(0)
//tsp=touchsensorport
{
	DebugPrint("ER follow black line to touch");
    printf("Following black line\n");
  //  msleep(3000);
    //what the black line is is in the next two lines
    
    // anything greater than average is black; lower is white
    // assume on black line already, if not, turn right, if not turn left, if not, do all again until found
    // while on black line move forward
    while (digital(Tsp) == 0)
    {
	    int color = lineFollow(Lmp, Rmp, Speed, Tpp, black);
    }
    
    ao();
    //msleep(1000);
}

void driveToTouch(int Lmp, int Rmp, int Speed, int Tsp)
{
    DebugPrint("ER graping the fire wall; stopping on touch");
    
    while (digital(Tsp) == 0)
    {
	    //drive straight
        mav(Rmp,Speed);
        mav(Lmp,Speed);
    }
    
    ao();
   // msleep(1000);
}
void fLineToLimit(int Lmp, int Rmp, int Speed, int Tpp, int black, int limit)
{
	int colorCount = 0;
    int colorCurrent;
    int colorPrev;
    
    DebugPrint("ER follow line to limit");
    printf("fLineToLimit\n");
  //  msleep(3000);
    while(colorCount <= limit){
        colorCurrent = lineFollow(Lmp, Rmp, Speed, Tpp, black);
        
        if (colorCurrent == colorPrev){//color is the same as last read
            colorCount += 1;
            printf("colorCount is %d\n", colorCount);
        }
        else {//color changed
            printf("Changing color after %d\n", colorCount);
            colorCount = 1;
            colorPrev = colorCurrent;
        }
    }
    ao();
    //msleep(1000);
}
	

int lineFollow(int Lmp, int Rmp, int Speed, int Tpp, int black)
{
    int tppReading = analog(Tpp);
     if (tppReading < black) //white
     {
         printf("turn right: %i\n", tppReading);
         // turn right
         mav(Rmp,0.5*Speed);
         mav(Lmp,Speed);
         
         return COLOR_WHITE;
     }
     else //black
     {
         printf("turn left: %i\n", tppReading);
         //turn left
         mav(Rmp,Speed);
         mav(Lmp,0.5*Speed);
         
         return COLOR_BLACK;
     }
}
//----------------------------------------------------------------------------------------------------------------------------
void turnLeft(int RIGHT_MOTOR_PORT, int LEFT_MOTOR_PORT)

{
	//Use DebugPrint to output the start of the function
    DebugPrint("Eddie: START turnLeft\n");
	//cmpc = clear motor position counter
	//Clear the position counter for the right motor
    cmpc(RIGHT_MOTOR_PORT);
	//Clear the position counter for the left motor
    cmpc(LEFT_MOTOR_PORT);
 	//mtp = motor to position
 	//Use the left motor to move 2500 clicks at a speed of 1000
 	//this will turn the robot 90 degrees to the right

    mtp(RIGHT_MOTOR_PORT,1000,2300);

    

	//msleep to allow the motor command time to function

    msleep(4000);

    

	//Use DebugPrint to output the completion of the function

    DebugPrint("Eddie: FINISH turnLeft\n");

}

