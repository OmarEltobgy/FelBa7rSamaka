#include "Empty.h"
#include "Creature.h"

int Empty :: gettype()
{
    return 0;
}
int Empty :: getStarve()
{
    return -1;
}
void Empty :: checkSurroundings(Ocean * c)
{
    int fishCount=0;
    int sharkCount=0;
    for(int a = -1; a <= 1; a++)
    {
        for(int b = -1; b <= 1; b++)
        {
            int contents = homeOcean->cellContents((iPos+a), (jPos+b));
            if(contents == homeOcean->FISH)
            {
                fishCount++;
            }
            else if(contents == homeOcean->SHARK)
            {
                sharkCount++;
            }
        }
    }
    if(fishCount >= 2 && sharkCount <= 1)
    {
        c->addFish(iPos, jPos);
    }
    else if(fishCount >= 2 && sharkCount >=2)
    {
        c->addShark(iPos, jPos,homeOcean->getStarveTime());
    }
}
Empty::~Empty()
{
    //destructor
}
