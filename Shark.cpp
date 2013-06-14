#include "Shark.h"
#include "Creature.h"

int Shark::gettype()
{
    return 1;
}
int Shark :: getStarve()
{
    return starveTime;
}
void Shark::checkSurroundings(Ocean * c)
{
    bool flagEmpty = false;
    for(int a = -1; a <= 1 && flagEmpty == false; a++)
    {
        for(int b = -1; b <= 1 && flagEmpty == false; b++)
        {
            int contents = homeOcean->cellContents((iPos+a), (jPos+b));
            if(contents == homeOcean->FISH)
                flagEmpty =true;
        }
    }

    if(flagEmpty == true)
    {
        /**/
        c->addShark(iPos, jPos, homeOcean->getStarveTime());
    }
    else
    {
        starveTime --;
        if(starveTime >=0)
        {
            c->addShark(iPos, jPos, starveTime);
        }
    }
}
Shark::~Shark()
{
    //destructor
}
