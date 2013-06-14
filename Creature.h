#ifndef CREATURE_H
#define CREATURE_H
#include "Ocean.h"
#include "RunLengthEncoding.h"

class RunLengthEncoding;
class Ocean;
class Creature
{
    public:
        Creature(int a, int b, Ocean* c);
        Creature(RunLengthEncoding* RLE);
        virtual int gettype();
        virtual void checkSurroundings(Ocean *c);
        virtual int getStarve();
        virtual ~Creature();
    protected:
        int type;
        int iPos;
        int jPos;
        Ocean *homeOcean;
        RunLengthEncoding* homeRLE;
};

#endif // CREATURE_H
