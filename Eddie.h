#include <kipr/wombat.h>
//variable definitions constant variable
//const int lmp=3;
//const int rmp=0;
//const int rmv=-225;
//const int lmv=225;
//function definition
void alignToCube(int lmp,int rmp, int Speed);
void fblackline(int Lmp, int Rmp, int Speed, int Tpp, int Tsp);

void alignToCube(int Lmp, int Rmp, int Speed)
{//using motor0 and motor3 (motor0 backward and motor3 forward)
    mav(Rmp,Speed);
    mav(Lmp,Speed);
    msleep(2000);
}
//-----------------------------------------------------------------------------------------------------------------------------
void fblackline(int Lmp, int Rmp, int Speed, int Tpp, int Tsp)
//lmp=leftmotorport
//rmp=rightmotorport
//speed; it defines itself
//tpp=tophatport(0)
//tsp=touchsensorport
{
    //what the black line is is in the next two lines
    int black=3390;
    black= (3390 + 192) / 2;
    // anything greater than average is black; lower is white
    // assume on black line already, if not, turn right, if not turn left, if not, do all again until found
    // while on black line move forward
    while (digital(Tsp) == 0)
    {
     if (analog(Tpp) < black)
     {
         // turn right
         mav(Rmp,0.5*Speed);
         mav(Lmp,Speed);
     }
     else 
     {
         //turn left
         mav(Rmp,Speed);
         mav(Lmp,0.5*Speed);
     }
    }
}