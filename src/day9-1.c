#include "common.h"
#include <stdlib.h>
#include <stdio.h>

#include "dynarray.h"

int isLowPoint(dynArray *array, int x, int y);
int getResult(dynArray *array);
void parstxt(FILE *fp){}

int main(int argc, char *argv[])
{
    dynArray *array = erzeuge();

    // Dateizeiger erstellen
    FILE *fp;

    // Datei oeffnen
    fp = fopen("input9.txt", "r");

    int i = 0, j = 0;
    int input = fgetc(fp);

    while (input != EOF)
    {
        while ((input != '\n') && (input != EOF))
        {
            wertRein(array, i, j, (input - '0'));
            j++;
            printf("%d/%d\n", j, i);
            input = fgetc(fp);
        }
        i++;
        j = 0;
        input = fgetc(fp);
    }
    ausgabe(array);
    getResult(array);
    // printf("werte: %d %d\n", wertbei(0, 0, array), wertbei(99, 99, array));
}

int getResult(dynArray *array)
{
    printf("%d",wertbei(array,0,0));
    printf("%d\n",isLowPoint(array,0,0));
    /*
    int maxX = getMaxX(array);
    int maxY = getMaxY(array);

    for (int i = 0; i < maxX; i++)
    {
        if (wertbei(array, i, 0) < wertbei(array, i + 1, 0))
        {
            if (wertbei(array, i, 0) < wertbei(array, i, 1))
            {
            }
        }
    }*/
}

int isLowPoint(dynArray *array, int x, int y)
{
    int maxX = getMaxX(array);
    int maxY = getMaxY(array);
    int isLowPoint = 0;

    int point = wertbei(array, x, y);
    
    if (x < maxX)
    {
        if (point < wertbei(array, x + 1, y))
        {
            isLowPoint = 1;
        }
    }
    if (x > 0)
    {
        if (point < wertbei(array, x - 1, y))
        {
            isLowPoint = 1;
        }else{
            isLowPoint = 0;
        }
    }
    if (y > 0)
    {
        if (point < wertbei(array, x, y - 1))
        {
            isLowPoint = 1;
        }else{
            isLowPoint = 0;
        }
    }
    if (y < maxY)
    {
        if (point < wertbei(array, x, y + 1))
        {
            isLowPoint = 1;
        }else{
            isLowPoint = 0;
        }
    }

   return isLowPoint;
    
}
