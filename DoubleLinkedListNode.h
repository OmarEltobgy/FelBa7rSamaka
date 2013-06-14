#ifndef DOUBLELINKEDLISTNODE_H
#define DOUBLELINKEDLISTNODE_H
#include <stdio.h>
#include "Creature.h"

class Creature;
class DoubleLinkedListNode
{
    public:
        DoubleLinkedListNode(Creature* k, int num);
        Creature* getCreature();
        void setNumber(int num);
        DoubleLinkedListNode* getNext();
        DoubleLinkedListNode* getPrevious();
        void setNext(DoubleLinkedListNode* n);
        void setPrevious(DoubleLinkedListNode* p);
        int getNumber();
    private:
        Creature* kind;
        int number;
        DoubleLinkedListNode* next;
        DoubleLinkedListNode* previous;
};

#endif // DOUBLELINKEDLISTNODE_H
