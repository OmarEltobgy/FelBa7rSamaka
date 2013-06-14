#include "DoubleLinkedList.h"
#include "DoubleLinkedListNode.h"
#include <stdio.h>

DoubleLinkedList::DoubleLinkedList()
{
    head = NULL;
    tail = NULL;
    Size = 0;
}
void DoubleLinkedList::add(Creature* k, int num)
{
    if(head == NULL)
    {
        DoubleLinkedListNode* newNode = new DoubleLinkedListNode(k, num);
        head = newNode;
        tail = newNode;
        Size++;
    }
    else
    {
        DoubleLinkedListNode* newNode = new DoubleLinkedListNode(k, num);
        newNode->setPrevious(tail);
        tail->setNext(newNode);
        tail = newNode;
        Size++;
    }
}
void DoubleLinkedList::add(Creature* k, int num, int index)
{
    DoubleLinkedListNode* current = head;
    DoubleLinkedListNode* newNode = new DoubleLinkedListNode(k, num);
    if(index == 0)
    {
        newNode->setNext(head);
        head->setPrevious(newNode);
        head = newNode;
        if(head == NULL)
            tail = newNode;
        Size++;
        return;
    }
    else if(head != NULL)
    {
        for(int i=0; i<Size; i++)
        {
            if(index == i+1)
            {
                newNode->setNext(current->getNext());
                (current->getNext())->setPrevious(newNode);
                current->setNext(newNode);
                newNode->setPrevious(current);
                Size++;
                return;
            }
            current = current->getNext();
        }
    }
    printf("Index out of bounds\n");
}
DoubleLinkedListNode* DoubleLinkedList::getNode(int index)
{
    DoubleLinkedListNode* current = head;
    for(int i=0; i<Size; i++)
    {
        if(i == index)
            return current;
        current = current->getNext();
    }
    printf("Index out of bounds\n");
    return 0;
}
DoubleLinkedListNode* DoubleLinkedList::getTail()
{
    return tail;
}
int DoubleLinkedList::getSize()
{
    return Size;
}

void DoubleLinkedList::removeNode(int index)
{
    DoubleLinkedListNode* current = head;
    DoubleLinkedListNode* temp;
    if(index == 0)
    {
        temp = head;
        head = head->getNext();
        delete(temp);
        if(head!=NULL)
            head->setPrevious(NULL);
        Size--;
        return;
    }
    else
        for(int i=0; i<Size-1; i++)
        {
            if(index == i+1)
             {
                temp = current->getNext();
                current->setNext((current->getNext())->getNext());
                if(index!=Size-1)
                   (temp->getNext())->setPrevious(current);
                else
                    tail = current;
                delete(temp);
                Size--;
                return;
             }
            current = current->getNext();
        }
    printf("Index out of bounds\n");
}

void DoubleLinkedList::clearList()
{
    int temp = Size;
    for(int i=0; i<temp; i++)
        removeNode(0);
}
DoubleLinkedList::~DoubleLinkedList()
{
    printf("destructor\n");
    clearList();
}

void DoubleLinkedList::print()
{
    DoubleLinkedListNode* current = head;
    for(int i=0; i<Size; i++)
    {
        printf("Type: %d   StarveTime: %d   Number: %d \n", current->getCreature()->gettype(), current->getCreature()->getStarve(), current->getNumber());
        current = current->getNext();
    }
}
