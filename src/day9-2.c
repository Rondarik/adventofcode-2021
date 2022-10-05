#include "common.h"
#include <stdlib.h>
#include <stdio.h>

#include "dynarray.h"

int isLowPoint(dynArray *array, int x, int y);
dynArray *findeLowPoints(dynArray *array);
void parstxt(FILE *fp) {}

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
            input = fgetc(fp);
        }
        i++;
        j = 0;
        input = fgetc(fp);
    }
    dynArray *koordinatenArray = findeLowPoints(array);
    ausgabe(koordinatenArray);
    printf("%d\n\n", getMaxX(koordinatenArray));
}

dynArray *findeLowPoints(dynArray *array)
{
    dynArray *lowPointKoordinaten = erzeuge();
    int maxX = getMaxX(array);
    int maxY = getMaxY(array);
    int a = 0;

    for (int i = 0; i <= maxX; i++)
    {
        for (int j = 0; j <= maxY; j++)
        {
            if (isLowPoint(array, i, j))
            {
                wertRein(lowPointKoordinaten, a, 0, i);
                wertRein(lowPointKoordinaten, a, 1, j);
                a++;
            }
        }
    }
    return lowPointKoordinaten;
}


int isLowPoint(dynArray *array, int x, int y)
{
    int maxX = getMaxX(array);
    int maxY = getMaxY(array);
    int point = wertbei(array, x, y);

    if (x < maxX)
    {
        if (point >= wertbei(array, x + 1, y))
        {
            return 0;
        }
    }
    if (x > 0)
    {
        if (point >= wertbei(array, x - 1, y))
        {
            return 0;
        }
    }
    if (y > 0)
    {
        if (point >= wertbei(array, x, y - 1))
        {
            return 0;
        }
    }
    if (y < maxY)
    {
        if (point >= wertbei(array, x, y + 1))
        {
            return 0;
        }
    }

    return 1;
}
