#include "RunLengthEncoding.h"
#include "Ocean.h"
#include "Creature.h"
#include "Empty.h"
#include "Fish.h"
#include "Shark.h"
#include<iostream>
using namespace std;

class DoubleLinkedList;

/**
 *  RunLengthEncoding() (with three parameters) is a constructor that creates
 *  a run-length encoding of an empty ocean having width i and height j,
 *  in which sharks starve after starveTime timesteps.
 *  @param i is the width of the ocean.
 *  @param j is the height of the ocean.
 *  @param starveTime is the number of timesteps sharks survive without food.
 */

RunLengthEncoding::RunLengthEncoding(int i, int j, int feeding)
{
    RLEocean = new DoubleLinkedList();
    Creature* first;
    first = new Empty(this);
    RLEocean->add(first,(i*j));
    width=i;
    height=j;
    starveTime=feeding;
}
/**
 *  RunLengthEncoding() (with five parameters) is a constructor that creates
 *  a run-length encoding of an ocean having width i and height j, in which
 *  sharks starve after starveTime timesteps.  The runs of the run-length
 *  encoding are taken from two input arrays.  Run i has length runLengths[i]
 *  and species runTypes[i].
 *  @param i is the width of the ocean.
 *  @param j is the height of the ocean.
 *  @param starveTime is the number of timesteps sharks survive without food.
 *  @param runTypes is an array that represents the species represented by
 *         each run.  Each element of runTypes is Ocean.EMPTY, Ocean.FISH,
 *         or Ocean.SHARK.  Any run of sharks is treated as a run of newborn
 *         sharks (which are equivalent to sharks that have just eaten).
 *  @param runLengths is an array that represents the length of each run.
 *         The sum of all elements of the runLengths array should be i * j.
 */

RunLengthEncoding::RunLengthEncoding(int i, int j, int feeding, Creature** runTypes, int size, int* runLengths)
{
    RLEocean = new DoubleLinkedList();
    width=i;
    height=j;
    starveTime=feeding;
    for(int l = 0; l < size; l++)
    {
        RLEocean->add(runTypes[l], runLengths[l]);
    }
}
// Destructor
RunLengthEncoding::~RunLengthEncoding()
{
    delete(RLEocean);
}
/**
 *  restartRuns() and nextRun() are two methods that work together to return
 *  all the runs in the run-length encoding, one by one.  Each time
 *  nextRun() is invoked, it returns a different run (represented as an
 *  array of two ints), until every run has been returned.  The first time
 *  nextRun() is invoked, it returns the first run in the encoding, which
 *  contains cell (0, 0).  After every run has been returned, nextRun()
 *  returns null, which lets the calling program know that there are no more
 *  runs in the encoding.
 *
 *  The restartRuns() method resets the enumeration, so that nextRun() will
 *  once again enumerate all the runs as if nextRun() were being invoked for
 *  the first time.
 *
 *  (Note:  Don't worry about what might happen if nextRun() is interleaved
 *  with addFish() or addShark(); it won't happen.)
 */
/**
 *  restartRuns() resets the enumeration as described above, so that
 *  nextRun() will enumerate all the runs from the beginning.
 */
void RunLengthEncoding::restartRuns()
{

}

/**
 *  nextRun() returns the next run in the enumeration, as described above.
 *  If the runs have been exhausted, it returns null.  The return value is
 *  an array of two ints (constructed here), representing the type and the
 *  size of the run, in that order.
 *  @return the next run in the enumeration, represented by an array of
 *          two ints.  The int at index zero indicates the run type
 *          (Ocean.EMPTY, Ocean.SHARK, or Ocean.FISH).  The int at index one
 *          indicates the run length (which must be at least 1).
 */

void RunLengthEncoding::nextRun(int* result, int* size)
{

}

/**
 *  toOcean() converts a run-length encoding of an ocean into an Ocean
 *  object.  You will need to implement the three-parameter addShark method
 *  in the Ocean class for this method's use.
 *  @return the Ocean represented by a run-length encoding.
 */

Ocean RunLengthEncoding::toOcean()
{
    return Ocean(1, 1, 1);
}
/**
 *  RunLengthEncoding() (with one parameter) is a constructor that creates
 *  a run-length encoding of an input Ocean.  You will need to implement
 *  the sharkFeeding method in the Ocean class for this constructor's use.
 *  @param sea is the ocean to encode.
 */
RunLengthEncoding::RunLengthEncoding(Ocean* sea)
{
    RLEocean = new DoubleLinkedList();
    width = sea->getWidth();
    height = sea->getHeight();
    starveTime = sea->getStarveTime();
    int beforeContents = sea->cellContents(0,0);
    Creature* first;
    switch(beforeContents)
    {
    case 0:
        {
            first = new Empty(0,0,sea);
            break;
        }
    case 1:
        {
            first = new Shark(0, 0, sea->sharkFeeding(0, 0), sea);
            break;
        }
    case 2:
        {
            first = new Fish(0, 0, sea);
            break;
        }
    }
    RLEocean->add(first,1);
    DoubleLinkedListNode* before = RLEocean->getTail();
    for(int j = 0; j < sea->getHeight(); j++)
    {
        if(before->getCreature()->gettype() == -1)
        {
            cout<<"ana 7omar";
        }
        for(int i = (j==0)?1:0 ; i < sea->getWidth(); i++)
        {
            int contents = sea->cellContents(i, j);
            if(contents == beforeContents)
            {
                if(contents ==0 || contents == 2)
                {
                    before->setNumber(before->getNumber()+1);
                }
                else
                {
                    if(sea->sharkFeeding(i,j)==before->getCreature()->getStarve())
                    {
                        before->setNumber(before->getNumber()+1);
                    }
                    else
                    {
                        Creature* toAdd = new Shark(i, j, sea->sharkFeeding(i,j), sea);
                        RLEocean->add(toAdd, 1);
                        /**/
                        before = RLEocean->getTail();
                    }
                }
            }
            else
            {
                beforeContents = contents;
                Creature* toAdd;
                switch(contents)
                {
                case 0:
                    {
                        toAdd = new Empty(i,j,sea);
                        break;
                    }
                case 1:
                    {
                        toAdd = new Shark(i, j , sea->sharkFeeding(i,j), sea);
                        break;
                    }
                case 2:
                    {
                        toAdd = new Fish(i, j, sea);
                        break;
                    }
                }
                RLEocean->add(toAdd, 1);
                /**/
                before = RLEocean->getTail();
            }
        }
    }
    check();
}
/**
 *  addFish() places a fish in cell (x, y) if the cell is empty.  If the
 *  cell is already occupied, leave the cell as it is.  The final run-length
 *  encoding should be compressed as much as possible; there should not be
 *  two consecutive runs of sharks with the same degree of hunger.
 *  @param x is the x-coordinate of the cell to place a fish in.
 *  @param y is the y-coordinate of the cell to place a fish in.
 */
void RunLengthEncoding::addFish(int x, int y)
{
    check();
}
/**
 *  addShark() (with two parameters) places a newborn shark in cell (x, y) if
 *  the cell is empty.  A "newborn" shark is equivalent to a shark that has
 *  just eaten.  If the cell is already occupied, leave the cell as it is.
 *  The final run-length encoding should be compressed as much as possible;
 *  there should not be two consecutive runs of sharks with the same degree
 *  of hunger.
 *  @param x is the x-coordinate of the cell to place a shark in.
 *  @param y is the y-coordinate of the cell to place a shark in.
 */
void RunLengthEncoding::addShark(int x, int y)
{
    check();
}

/**
 *  check() walks through the run-length encoding and prints an error message
 *  if two consecutive runs have the same contents, or if the sum of all run
 *  lengths does not equal the number of cells in the ocean.
 */

void RunLengthEncoding::check()
{

}

void RunLengthEncoding::view()
{
    RLEocean->print();
}
