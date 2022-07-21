
#include "common.h"
#include <stdlib.h>
#include <string.h>

const long DAYS = 256;

long alter[9] = {0};
long anzahlFische();

void zahlZufuegen(long zahl);
void fischeAltern();

long main(long argc, char *argv[])
{

    read("realinput6.txt");
}

void parstxt(FILE *fp)
{
    long zahl = leseZahl(fp);
    while (zahl != -1)
    {
        zahlZufuegen(zahl);
        zahl = leseZahl(fp);
    }

    for (long i = 0; i < DAYS; i++)
    {

        if (i == 18 || i == 80)
        {
            printf("Tag %ld, Anzahl: %ld\n", i, anzahlFische());
        }

        fischeAltern();
    }

    printf("Anzahl der Fische: %ld\n\n", anzahlFische());
}

long anzahlFische()
{
    long anzahl = 0;
    for (long i = 0; i < 9; i++)
    {
        anzahl = anzahl + alter[i];
    }
    return anzahl;
}

void fischeAltern()
{
    long temp = alter[0];
    for (long i = 0; i < 8; i++)
    {
        alter[i] = alter[i + 1];
    }
    alter[8] = temp;
    alter[6] = alter[6] + temp;
}

void zahlZufuegen(long zahl)
{
    alter[zahl]++;
}