#include "common.h"
#include <stdlib.h>
#include <stdio.h>

#include "dynarray.h"

int isLowPoint(dynArray *array, int x, int y);
dynArray *findeLowPoints(dynArray *array);
dynArray *erstelleNachbarListe(dynArray *array, int x, int y);
int istSinnvollerNachbar(dynArray *array, int x, int y);
int istInnerhalbDerGrenzen(dynArray *array, int x, int y);
void fuelleBaisin(dynArray *basin, dynArray *array, int x, int y);

void parstxt(FILE *fp) {}

int main(int argc, char *argv[])
{
    dynArray *array = erzeuge();

    // Dateizeiger erstellen
    FILE *fp;

    // Datei oeffnen
    fp = fopen("realinput9.txt", "r");

    int y = 0, x = 0;

    int input;
    while ((input = fgetc(fp)) != EOF)
    {
        if (input != '\n')
        {
            wertRein(array, y, x, (input - '0'));
            x++;
        }
        else
        {
            y++;
            x = 0;
        }
    }
    dynArray *koordinatenArray = findeLowPoints(array);

    printf("Anz LowPoints: %d\n\n", groesseX(koordinatenArray));

    int gold = 0, silber = 0, bronze = 0;
    int groesste[3] = { 0 };

    for (int x = 0; x < groesseX(koordinatenArray); x++)
    {
        dynArray *basin = erzeuge();
        fuelleBaisin(basin, array, wertbei(koordinatenArray, x, 0), wertbei(koordinatenArray, x, 1));

        int basinGroesse = groesseX(basin);
        for (int i = 0; i < 3; i++) {
            if (basinGroesse > groesste[i]) {
                groesste[i] = basinGroesse;
                break;
            }
        }
    }

    int result = 1;
    for (int i = 0; i < 3; i++) {
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
    int maxX = getMaxX(array);
    int maxY = getMaxY(array);
    int point = wertbei(array, x, y);

    if (x < maxX && point >= wertbei(array, x + 1, y))
    {
        return 0;
    }
    if (x > 0 && point >= wertbei(array, x - 1, y))
    {
        return 0;
    }
    if (y > 0 && point >= wertbei(array, x, y - 1))
    {
        return 0;
    }
    if (y < maxY && point >= wertbei(array, x, y + 1))
    {
        return 0;
    }

    return 1;
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

    if ((istInnerhalbDerGrenzen(array, x, y)) && (wertbei(array, x, y) < 9))
    {
        return 1;
    }

    return 0;
}

int istInnerhalbDerGrenzen(dynArray *array, int x, int y)
{
    if ((x < 0) || (y < 0) || (x > getMaxX(array)) || (y > getMaxY(array)))
    {
        return 0;
    }

    return 1;
}

int istInBaisin(dynArray *basin, int x, int y)
{

    for (int i = 0; i <= getMaxX(basin); i++)
    {
        if ((wertbei(basin, i, 0) == x) && (wertbei(basin, i, 1) == y))
        {
            return 1;
        }
    }

    return 0;
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