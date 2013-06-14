#include <iostream>
#include "Ocean.h"
#include "Creature.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "RunLengthEncoding.h"

using namespace std;
int i = 50;                             // Default ocean width
int j = 25;                            // Default ocean height
int starveTime = 3;           // Default shark starvation time

void paint(Ocean* sea)
{
    int width = sea->getWidth();
    int height = sea->getHeight();

    /* Draw the ocean. */
    for (int x = 0; x < width + 2; x++)
    {
        cout << "-";
    }
    cout << endl;
    for (int y = 0; y < height; y++)
    {
        cout << "|";
        for (int x = 0; x < width; x++)
        {
            int contents = sea->cellContents(x, y);
            if (contents == sea->SHARK)
            {
                cout << 'S';
            }
            else if (contents == sea->FISH)
            {
                cout << '~';
            }
            else if(contents == sea->EMPTY)
            {
                cout << ' ';
            }
            else
            {
                cout << '7';
            }
        }
        cout << "|\n";
    }
    for (int x = 0; x < width + 2; x++)
    {
        cout << "-";
    }
    cout << endl;
}

int main()
{
    /*printf("Enter the width : ");
    scanf("%d",&i);
    printf("Enter the height : ");
    scanf("%d",&j);
    printf("Enter the starveTime : ");
    scanf("%d",&starveTime);*/

    Ocean* sea = new Ocean(4, 3, 4);

    sea->addFish(3, 0);
    sea->addFish(0, 1);
    sea->addFish(1, 1);
    sea->addShark(2, 1, 1);
    sea->addShark(3, 1, 0);
    sea->addShark(0, 2, 3);
    sea->addFish(1, 2);
    sea->addFish(2, 2);
    paint(sea);
    paint(sea->timeStep());
    RunLengthEncoding* RLE = new RunLengthEncoding(sea);
    RLE->view();
    return 0;
}
