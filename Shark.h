#ifndef SHARK_H
#define SHARK_H
#include "Ocean.h"

class Shark : public Creature
{
    public:
        Shark(int a, int b ,Ocean *c) : Creature(a, b , c)
        {
            type = 1;
            starveTime=c->getStarveTime();
        }
        Shark(int a, int b, int feeding ,Ocean *c) : Creature(a, b , c)
        {
            type = 1;
            starveTime=feeding;
        }
        Shark(int feeding, RunLengthEncoding* RLE) : Creature(RLE)
        {
            starveTime = feeding;
        }
        ~Shark();
        void checkSurroundings(Ocean * c);
        int gettype ();
        int getStarve();
    private:
        int starveTime;
};

#endif // SHARK_H
