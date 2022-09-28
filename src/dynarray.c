#include "dynarray.h"

#include <stdlib.h>
#include <stdio.h>

dynArray *erzeuge()
{
    int **data = NULL;
    dynArray *result = (dynArray *)malloc(sizeof(dynArray));
    result->data = data;
    result->maxX = -1;
    result->maxY = -1;
    return result;
}

void wertRein(dynArray *array, int xPos, int yPos, int wert)
{
    int neuesX = (xPos > array->maxX)
                     ? xPos
                     : array->maxX;
    int neuesY = (yPos > array->maxY)
                     ? yPos
                     : array->maxY;
    if (neuesX > array->maxX ||
        neuesY > array->maxY)
    {
        vergroessere(array, neuesX, neuesY);
    }
    array->data[xPos][yPos] = wert;
}

int wertbei(dynArray *array, int x, int y)
{
    return array->data[x][y];
}

int getMaxX(dynArray *array)
{
    return array->maxX;
}

int getMaxY(dynArray *array)
{
    return array->maxY;
}

void vergroessere(dynArray *array, int neuesX, int neuesY)
{
    int **newData = (int **)malloc((neuesX + 1) * sizeof(int *));
    for (int i = 0; i <= neuesX; i++)
    {
        newData[i] = (int *)malloc((neuesY + 1) * sizeof(int *));
        if (i <= array->maxX)
        {
            for (int j = 0; j <= array->maxY; j++)
            {
                newData[i][j] = array->data[i][j];
            }
        }
    }
    free(array->data);
    array->data = newData;
    array->maxX = neuesX;
    array->maxY = neuesY;
}

void ausgabe(dynArray *array)
{
    for (int i = 0; i <= array->maxX; i++)
    {
        for (int j = 0; j <= array->maxY; j++)
        {
            printf("%4d ", wertbei(array, i, j));
        }
        printf("\n");
    }
    printf("\n");
}
