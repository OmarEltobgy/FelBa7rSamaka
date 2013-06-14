#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "DoubleLinkedListNode.h"
#include "Creature.h"

class DoubleLinkedListNode;
class DoubleLinkedList
{
    public:
        DoubleLinkedList();
        ~DoubleLinkedList();
        void add(Creature* k, int num);
        void add(Creature* k, int num, int index);
        DoubleLinkedListNode* getNode(int index);
        DoubleLinkedListNode* getTail();
        int getSize();
        void removeNode(int index);
        void clearList();
        void print();
    protected:
        DoubleLinkedListNode* tail;
        DoubleLinkedListNode* head;
        int Size;
};

#endif // DOUBLELINKEDLIST_H
