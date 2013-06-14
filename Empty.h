#ifndef EMPTY_H
#define EMPTY_H
#include "Ocean.h"

class Empty : public Creature
{
    public:
        Empty(int a, int b, Ocean* c) : Creature(a,b,c)
        {
            type = 0;
        }
        Empty(RunLengthEncoding* RLE) : Creature(RLE)
        {
            type = 0;
        }
        int gettype();
        void checkSurroundings(Ocean *c);
        int getStarve();
        ~Empty();
};

#endif // EMPTY_H
