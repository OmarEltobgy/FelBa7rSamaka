#include "Fish.h"
#include "Creature.h"

int Fish :: gettype()
{
    return 2;
}
int Fish :: getStarve()
{
    return -1;
}
void Fish::checkSurroundings(Ocean * c)
{
    int count = 0;
    for(int a = -1; a <= 1; a++)
    {
        for(int b = -1; b <= 1; b++)
        {
            int contents = homeOcean->cellContents((iPos+a), (jPos+b));

            if(contents == homeOcean->SHARK)
            {
                count ++ ;
            }
        }
    }
    if(count == 0)
    {
        c->addFish(iPos, jPos);
    }
    else if(count >= 2)
    {
        c->addShark(iPos, jPos, homeOcean->getStarveTime());
    }
}
Fish::~Fish()
{
    //destructor
}
