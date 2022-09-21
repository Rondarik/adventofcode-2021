
#include <stdlib.h>
#include <stdio.h>
#include "arrayclass.h"

DynArray::DynArray()
{
    maxX = -1;
    maxY = -1;
    array = NULL;
}

void DynArray::wertRein(int xPos, int yPos, int wert)
{
    int neuesX = (xPos > maxX)
                     ? xPos
                     : maxX;
    int neuesY = (yPos > maxY)
                     ? yPos
                     : maxY;
    if (neuesX > maxX ||
        neuesY > maxY)
    {
        vergroessere(neuesX, neuesY);
    }
    array[xPos][yPos] = wert;
}

int DynArray::wertBei(int x, int y)
{
    return array[x][y];
}

void DynArray::vergroessere(int neuesX, int neuesY)
{
    int **newData = (int **)malloc((neuesX + 1) * sizeof(int *));
    for (int i = 0; i <= neuesX; i++)
    {
        newData[i] = (int *)malloc((neuesY + 1) * sizeof(int *));
        if (i <= maxX)
        {
            for (int j = 0; j <= maxY; j++)
            {
                newData[i][j] = array[i][j];
            }
        }
    }
    free(array);
    array = newData;
    maxX = neuesX;
    maxY = neuesY;
}

void DynArray::ausgabe()
{
    for (int i = 0; i <= maxX; i++)
    {
        for (int j = 0; j <= maxY; j++)
        {
            printf("%4d ", wertBei(i, j));
        }
        printf("\n");
    }
    printf("\n");
}
