#ifndef RUNLENGTHENCODING_H
#define RUNLENGTHENCODING_H
#include "Ocean.h"
#include "DoubleLinkedList.h"
#include "DoubleLinkedListNode.h"

class Ocean;
class DoubleLinkedList;
class RunLengthEncoding
{
public:
    RunLengthEncoding(int i, int j, int starveTime);
    RunLengthEncoding(int i, int j, int feeding, Creature** runTypes, int size, int* runLengths);
    RunLengthEncoding(Ocean* sea);
    ~RunLengthEncoding();
    void restartRuns();
    void nextRun(int* result, int* size);
    Ocean toOcean();
    void view();
    void addFish(int x, int y);
    void addShark(int x, int y);
protected:
private:
    int width;
    int height;
    int starveTime;
    DoubleLinkedList* RLEocean;
    void check();
    /*
     *  Define any variables associated with a RunLengthEncoding object here.
     *  These variables MUST be private.
     */
};

#endif // RUNLENGTHENCODING_H
