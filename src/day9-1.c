#include "common.h"
#include <stdlib.h>
#include <stdio.h>

#include "dynarray.h"

int isLowPoint(dynArray *array, int x, int y);
int getResult(dynArray *array);
void parstxt(FILE *fp) {}

int main(int argc, char *argv[])
{
    dynArray *array = erzeuge();

    // Dateizeiger erstellen
    FILE *fp;

    // Datei oeffnen
    fp = fopen("realinput9.txt", "r");

    int i = 0, j = 0;
    int input = fgetc(fp);

    while (input != EOF)
    {
        while ((input != '\n') && (input != EOF))
        {
            wertRein(array, i, j, (input - '0'));
            j++;
            input = fgetc(fp);
        }
        i++;
        j = 0;
        input = fgetc(fp);
    }
    printf("Das Ergebnis lautet: %d\n", getResult(array));
}

int getResult(dynArray *array)
{

    int maxX = getMaxX(array);
    int maxY = getMaxY(array);
    int ergebnis = 0;

    for (int i = 0; i <= maxX; i++)
    {
        for (int j = 0; j <= maxY; j++)
        {
            if (isLowPoint(array, i, j))
            {
                ergebnis = (1 + ergebnis + wertbei(array, i, j));
            }
        }
    }
    return ergebnis;
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
        else
        {
            return isLowPoint;
        }
    }
    if (x > 0)
    {
        if (point < wertbei(array, x - 1, y))
        {
            isLowPoint = 1;
        }
        else
        {
            isLowPoint = 0;
            return isLowPoint;
        }
    }
    if (y > 0)
    {
        if (point < wertbei(array, x, y - 1))
        {
            isLowPoint = 1;
        }
        else
        {
            isLowPoint = 0;
            return isLowPoint;
        }
    }
    if (y < maxY)
    {
        if (point < wertbei(array, x, y + 1))
        {
            isLowPoint = 1;
        }
        else
        {
            isLowPoint = 0;
        }
    }

    return isLowPoint;
}
