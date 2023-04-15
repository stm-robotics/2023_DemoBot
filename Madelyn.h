#include <kipr/wombat.h>
void findWall(int etport, int rmp, int lmp);

void findWall(int etport, int rmp, int lmp)
{
    DebugPrint("MP find wall");
    int wall;
    wall=2417;
    //printf "void find wall";
    //et sensor analog 2
    while(analog(etport) != wall);
    {
     mav(rmp,10);
     mav(lmp,-10);
    }
}