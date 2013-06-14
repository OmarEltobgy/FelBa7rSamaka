#ifndef OCEAN_H
#define OCEAN_H
#include "Creature.h"
class Creature;

class Ocean
{
    public:
        static const int EMPTY = 0;
        static const int SHARK = 1;
        static const int FISH = 2;
        Ocean();
        Ocean(int i, int j, int time);
        ~Ocean();
        int getWidth();
        int getHeight();
        int getStarveTime();
        void addFish(int x, int y);
        void addShark(int x, int y);
        int cellContents(int x, int y);
        Ocean *timeStep();
        void addShark(int x, int y, int feeding);
        int sharkFeeding(int x, int y);

    private:
        int width;
        int height;
        int starveTime;
        Creature*** oceanContents;
};

#endif // OCEAN_H
