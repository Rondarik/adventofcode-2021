
#include "common.h"
#include <stdlib.h>
#include <string.h>

const int DAYS = 80;

int *alter;
int anzahlFische = 0;

int leseZahl(FILE *fp);
int gesamtAlter();

void zahlZufuegen(int zahl);
void fischeAltern();

int main(int argc, char *argv[])
{
    alter = malloc(0);
    read("realinput6.txt");
}

void parstxt(FILE *fp)
{
    int zahl = leseZahl(fp);
    while (zahl != -1)
    {
        zahlZufuegen(zahl);
        zahl = leseZahl(fp);
    }

    size_t anzahl = anzahlFische;
    for (int i = 0; i < DAYS; i++)
    {

        if (i == 18)
        {
            printf("Tag 18, Anzahl: %d\n", anzahlFische);
        }
        fischeAltern();
    }

    // int ergebnis = gesamtAlter();
    printf("Gesamtalter: %d\n\n", anzahlFische);
}

int gesamtAlter()
{
    size_t anzahl = anzahlFische;
    int ergebnis = 0;
    for (int i = 0; i < anzahl; i++)
    {
        ergebnis += alter[i];
    }
    return ergebnis;
}

void fischeAltern()
{
    int anzahl = anzahlFische;
    for (int i = 0; i < anzahl; i++)
    {
        if (alter[i] == 0)
        {
            alter[i] = 6;
            zahlZufuegen(8);
        }
        else
        {
            alter[i] = alter[i] - 1;
        }
    }
}

void zahlZufuegen(int zahl)
{
    int intSize = sizeof(int);
    int bisherigeGroesse = anzahlFische;
    int neueGroesse = (bisherigeGroesse + 1);
    int *alt = alter;
    alter = (int *)malloc(neueGroesse * intSize);
    memcpy(alter, alt, bisherigeGroesse * intSize);
    alter[neueGroesse - 1] = zahl;
    free(alt);
    anzahlFische = anzahlFische + 1;
}