#include "Ocean.h"
#include "Creature.h"
#include "Empty.h"
#include "Shark.h"
#include "Fish.h"
#include <stdio.h>
//Default Empty Constructor
Ocean::Ocean()
{
    width = 50;                              // Default ocean width
    height = 25;                            // Default ocean height
    starveTime = 3;                // Default shark starvation time
}

//Main Constructor
/**
*  Ocean() is a constructor that creates an empty ocean having width i and
*  height j, in which sharks starve after starveTime timesteps.
*  @param i is the width of the ocean.
*  @param j is the height of the ocean.
*  @param starveTime is the number of timesteps sharks survive without food.
*/
Ocean::Ocean(int i, int j, int time)
{
    width = i;                              // Input ocean width
    height = j;                            // Input ocean height
    starveTime = time;                // Input shark starvation time
    oceanContents = new Creature**[height];
    for(int h = 0; h < height; h++)
    {
        oceanContents[h] = new Creature*[width];
    }
    for(int h = 0; h < height; h++)
    {
        for(int w = 0; w < width; w++)
        {
            Ocean* tosend = this;
            oceanContents[h][w] = new Empty(w, h, tosend);
            oceanContents[h][w]->gettype();
        }
    }
}

//Destructor
Ocean::~Ocean()
{
    for(int h = 0; h < height; h++)
    {
        for(int w = 0; w < width; w++)
        {
            delete(oceanContents[h][w]);
        }
        delete(oceanContents[h]);
    }
    delete(oceanContents);
}

/**
*  width() returns the width of an Ocean object.
*  @return the width of the ocean.
*/
int Ocean::getWidth()
{
    return width;
}

/**
*  height() returns the height of an Ocean object.
*  @return the height of the ocean.
*/
int Ocean::getHeight()
{
    return height;
}

/**
*  starveTime() returns the number of timesteps sharks survive without food.
*  @return the number of timesteps sharks survive without food.
*/
int Ocean::getStarveTime()
{
    return starveTime;
}

/**
 *  addFish() places a fish in cell (x, y) if the cell is empty.  If the
 *  cell is already occupied, leave the cell as it is.
 *  @param x is the x-coordinate of the cell to place a fish in.
 *  @param y is the y-coordinate of the cell to place a fish in.
 */
void Ocean::addFish(int x, int y)
{
    if(oceanContents[y][x]->gettype() == this->EMPTY)//EMPTY
    {
        delete(oceanContents[y][x]);
        oceanContents[y][x] = new Fish(x, y, this);
    }
}

/**
 *  addShark() (with two parameters) places a newborn shark in cell (x, y) if
 *  the cell is empty.  A "newborn" shark is equivalent to a shark that has
 *  just eaten.  If the cell is already occupied, leave the cell as it is.
 *  @param x is the x-coordinate of the cell to place a shark in.
 *  @param y is the y-coordinate of the cell to place a shark in.
 */
void Ocean::addShark(int x, int y)
{
    if(oceanContents[y][x]->gettype() == this->EMPTY)//EMPTY
    {
        delete(oceanContents[y][x]);
        oceanContents[y][x] = new Shark(x, y, this);
    }
}

/**
 *  cellContents() returns EMPTY if cell (x, y) is empty, FISH if it contains
 *  a fish, and SHARK if it contains a shark.
 *  @param x is the x-coordinate of the cell whose contents are queried.
 *  @param y is the y-coordinate of the cell whose contents are queried.
 */
int Ocean::cellContents(int x, int y)
{
    int newX;
    int newY;
    if(x >= 0)
        newX = x % width;
    else
    {
        while(x<0)
            x = x + width;
        newX = x % width;
    }
    if(y >= 0)
        newY = y % height;
    else
    {
        while(y<0)
            y = y + height;
        newY = y % height;
    }
    return oceanContents[newY][newX]->gettype();
}

/**
 *  timeStep() performs a simulation timestep as described in README.
 *  @return an ocean representing the elapse of one timestep.
 */
Ocean* Ocean::timeStep()
{
    int h, w;
    Ocean *newOcean = new Ocean (width, height, starveTime);
    for(h=0; h<height; h++)
    {
        for(w=0; w<width; w++)
        {
            oceanContents[h][w]->checkSurroundings(newOcean);
        }
    }
    return newOcean;
}

/**
 *  addShark() (with three parameters) places a shark in cell (x, y) if the
 *  cell is empty.  The shark's hunger is represented by the third parameter.
 *  If the cell is already occupied, leave the cell as it is.  You will need
 *  this method to help convert run-length encodings to Oceans.
 *  @param x is the x-coordinate of the cell to place a shark in.
 *  @param y is the y-coordinate of the cell to place a shark in.
 *  @param feeding is an integer that indicates the shark's hunger.  You may
 *         encode it any way you want; for instance, "feeding" may be the
 *         last timestep the shark was fed, or the amount of time that has
 *         passed since the shark was last fed, or the amount of time left
 *         before the shark will starve.  It's up to you, but be consistent.
 **/

void Ocean::addShark(int x, int y, int feeding)
{
    if(oceanContents[y][x]->gettype() == this->EMPTY)//EMPTY
    {
        delete(oceanContents[y][x]);
        oceanContents[y][x] = new Shark(x, y, feeding, this);
    }
}

/**
 *  sharkFeeding() returns an integer that indicates the hunger of the shark
 *  in cell (x, y), using the same "feeding" representation as the parameter
 *  to addShark() described above.  If cell (x, y) does not contain a shark,
 *  then its return value is undefined--that is, anything you want.
 *  Normally, this method should not be called if cell (x, y) does not
 *  contain a shark.  You will need this method to help convert Oceans to
 *  run-length encodings.
 *  @param x is the x-coordinate of the cell whose contents are queried.
 *  @param y is the y-coordinate of the cell whose contents are queried.
 */

int Ocean::sharkFeeding(int x, int y)
{
    return oceanContents[y][x]->getStarve();
}



