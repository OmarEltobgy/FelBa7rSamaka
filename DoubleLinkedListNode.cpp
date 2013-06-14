#include "DoubleLinkedListNode.h"

DoubleLinkedListNode::DoubleLinkedListNode(Creature* k, int num)
{
    number = num;
    kind = k;
    next = NULL;
    previous =NULL;
}

Creature* DoubleLinkedListNode::getCreature()
{
    return kind;
}

int DoubleLinkedListNode::getNumber()
{
    return number;
}

void DoubleLinkedListNode::setNumber(int num)
{
    number = num;
}
DoubleLinkedListNode* DoubleLinkedListNode::getNext()
{
    return next;
}
DoubleLinkedListNode* DoubleLinkedListNode::getPrevious()
{
    return previous;
}
void DoubleLinkedListNode::setNext(DoubleLinkedListNode* n)
{
    next = n;
}
void DoubleLinkedListNode::setPrevious(DoubleLinkedListNode* p)
{
    previous = p;
}
