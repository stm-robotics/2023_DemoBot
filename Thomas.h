//function declarations
void findBlackLine(int vel, int TOPHAT_PORT, int LEFT_MOTOR, int RIGHT_MOTOR);
void turnLeft90(int vel, int RIGHT_MOTOR);

const int TOPHAT_BLACK = 3000;
const int MAX_TICKS = 1500;

//function definitions
void findBlackLine(int vel, int TOPHAT_PORT, int LEFT_MOTOR, int RIGHT_MOTOR)
{
    printf("Finding black line\n");
  //  msleep(3000);
    while(analog(TOPHAT_PORT) <= TOPHAT_BLACK){ //Is there not a black line?
        //onward!
        mav(LEFT_MOTOR, vel);	
        mav(RIGHT_MOTOR, vel);
    }
    ao();
    
}

void turnLeft90(int vel, int RIGHT_MOTOR)
{
    double dPos = 1.6;
    printf("Turn left 90\n");
  //  msleep(3000);
    mrp(RIGHT_MOTOR, vel, dPos * MAX_TICKS);
    msleep(2500);

}
