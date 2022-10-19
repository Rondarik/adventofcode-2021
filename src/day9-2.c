#include "common.h"
#include <stdlib.h>
#include <stdio.h>

#include "dynarray.h"

#define TARGET_COUNT 3

int isLowPoint(dynArray *array, int x, int y);
dynArray *findeLowPoints(dynArray *array);
dynArray *erstelleNachbarListe(dynArray *array, int x, int y);
int istSinnvollerNachbar(dynArray *array, int x, int y);
void fuelleBaisin(dynArray *basin, dynArray *array, int x, int y);

void parstxt(FILE *fp) {}

int main(int argc, char *argv[])
{
    dynArray *array = erzeuge();

    // Datei oeffnen
    FILE *fp = fopen("realinput9.txt", "r");

    int y = 0, x = 0;

    int input;
    while ((input = fgetc(fp)) != EOF)
    {
        if (input != '\n')
        {
            wertRein(array, y, x++, (input - '0'));
        }
        else
        {
            y++;
            x = 0;
        }
    }
    dynArray *koordinatenArray = findeLowPoints(array);

    printf("Anz LowPoints: %d\n\n", groesseX(koordinatenArray));

    int groesste[TARGET_COUNT] = { 0 };

    for (int x = 0; x < groesseX(koordinatenArray); x++)
    {
        dynArray *basin = erzeuge();
        fuelleBaisin(basin, array, wertbei(koordinatenArray, x, 0), wertbei(koordinatenArray, x, 1));

        int basinGroesse = groesseX(basin);
        int verschieben = 0;
        for (int i = 0; i < TARGET_COUNT; i++) {
            if (basinGroesse > groesste[i] && !verschieben) {
                verschieben = groesste[i];
                groesste[i] = basinGroesse;
            } else if (verschieben) {
                int temp = groesste[i];
                groesste[i] = verschieben;
                verschieben = temp;
            }
        }
    }

    int result = 1;
    for (int i = 0; i < TARGET_COUNT; i++) {
        printf("%d: %d ", i, groesste[i]);
        result *= groesste[i];
    }
    printf("\nEndergebnis: %d\n\n", result);
}

dynArray *findeLowPoints(dynArray *array)
{
    dynArray *lowPointKoordinaten = erzeuge();
    int a = 0;

    for (int x = 0; x < groesseX(array); x++)
    {
        for (int y = 0; y <= groesseY(array); y++)
        {
            if (isLowPoint(array, x, y))
            {
                wertRein(lowPointKoordinaten, a, 0, x);
                wertRein(lowPointKoordinaten, a, 1, y);
                a++;
            }
        }
    }
    return lowPointKoordinaten;
}

int isLowPoint(dynArray *array, int x, int y)
{
    int point = wertbei(array, x, y);

    int result = 1;
    result = result && !(x < getMaxX(array) && point >= wertbei(array, x + 1, y));
    result = result && !(x > 0 && point >= wertbei(array, x - 1, y));
    result = result && !(y > 0 && point >= wertbei(array, x, y - 1));
    result = result && !(y < getMaxY(array) && point >= wertbei(array, x, y + 1));

    return result;
}

dynArray *erstelleNachbarListe(dynArray *array, int x, int y)
{
    dynArray *listeNachbarn = erzeuge();
    int c = 0;

    if (istSinnvollerNachbar(array, x + 1, y))
    {
        wertRein(listeNachbarn, c, 0, x + 1);
        wertRein(listeNachbarn, c, 1, y);
        c++;
    }
    if (istSinnvollerNachbar(array, x - 1, y))
    {
        wertRein(listeNachbarn, c, 0, x - 1);
        wertRein(listeNachbarn, c, 1, y);
        c++;
    }
    if (istSinnvollerNachbar(array, x, y + 1))
    {
        wertRein(listeNachbarn, c, 0, x);
        wertRein(listeNachbarn, c, 1, y + 1);
        c++;
    }
    if (istSinnvollerNachbar(array, x, y - 1))
    {
        wertRein(listeNachbarn, c, 0, x);
        wertRein(listeNachbarn, c, 1, y - 1);
        c++;
    }

    return listeNachbarn;
}

int istSinnvollerNachbar(dynArray *array, int x, int y)
{
    int result = (x >= 0);
    result = result && (y >= 0);
    result = result && (x <= getMaxX(array));
    result = result && (y <= getMaxY(array));
    result = result && (wertbei(array, x, y) < 9);

    return result;
}

void fuelleBaisin(dynArray *basin, dynArray *array, int x, int y)
{

    dynArray *dieLiebenNachbarn;
    int insertAt = getMaxX(basin) + 1;

    wertRein(basin, insertAt, 0, x);
    wertRein(basin, insertAt, 1, y);

    dieLiebenNachbarn = erstelleNachbarListe(array, x, y);

    for (int i = 0; i <= getMaxX(dieLiebenNachbarn); i++)
    {
        if (!istInBaisin(basin, wertbei(dieLiebenNachbarn, i, 0), wertbei(dieLiebenNachbarn, i, 1)))
        {
            fuelleBaisin(basin, array, wertbei(dieLiebenNachbarn, i, 0), wertbei(dieLiebenNachbarn, i, 1));
        }
    }
}

int istInBaisin(dynArray *basin, int x, int y)
{
    for (int i = 0; i < groesseX(basin); i++)
    {
        if ((wertbei(basin, i, 0) == x) && (wertbei(basin, i, 1) == y))
        {
            return 1;
        }
    }

    return 0;
}
