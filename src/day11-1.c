#include "common.h"
#include <stdlib.h>
#include <stdio.h>

#include "dynarray.h"

void parstxt(FILE *fp) {}

int Steps = 100;

int main(int argc, char *argv[])
{
    dynArray *array = erzeuge();

    // Dateizeiger erstellen
    FILE *fp;

    // Datei oeffnen
    fp = fopen("input11.txt", "r");

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

    PlusOneAll(array);

    Steps = 0;
    while (Steps < 1)
    {
        for (int x = 0; x < 10; x++)
        {
            for (int y = 0; y < 10; y++)
            {
                if (wertbei(array, x, y) == 9)
                {
                    plusOne(array, x, y);
                }
            }
        }

        Steps++;
        ausgabe(array);
    }
}

//
// Funktionen umbenennen + flashs zaehlen beim naechsten Mal
//

void PlusOneAll(dynArray *array)
{
    ausgabe(array);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            wertRein(array, i, j, wertbei(array, i, j) + 1);
        }
    }
    ausgabe(array);
}
// printf("Das Ergebnis lautet: %d\n", Summe );

void plusOne(dynArray *array, int x, int y)
{
    for (int i = -1; i <= 1; i++)
    {
        int xPos = x+i;
        for (int j = -1; j <= 1; j++)
        {
            int yPos = y + j;
            if (xPos >= 0 && xPos < 10 && yPos >= 0 && yPos < 10 && !(i == 0 && j == 0))
                wertRein(array, xPos, yPos, wertbei(array, xPos, yPos) + 1);
        }
    }
}