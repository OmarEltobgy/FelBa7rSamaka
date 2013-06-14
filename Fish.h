#ifndef FISH_H
#define FISH_H
#include "Ocean.h"

class Fish : public Creature
{
    public:
        Fish(int a, int b, Ocean * c) : Creature(a, b, c)
        {
            type = 2;
        }
        Fish(RunLengthEncoding* RLE) : Creature(RLE)
        {
            type = 2;
        }
        void checkSurroundings(Ocean * c);
        int gettype();
        int getStarve();
        ~Fish();
};

#endif // FISH_H
