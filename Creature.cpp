#include "Creature.h"
#include "Fish.h"
#include "Shark.h"
#include "Empty.h"
#include "Ocean.h"

Creature :: Creature(int a, int b, Ocean* c)
{
    //ctor
    iPos = a;
    jPos = b;
    homeOcean = c;
}
void Creature::checkSurroundings(Ocean * c)
{
    return;
}
int Creature :: gettype()
{
    return -1;
}
int Creature :: getStarve()
{
    return -1;
}
Creature::~Creature()
{
    //destructor
}
