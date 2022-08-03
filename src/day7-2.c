#include "common.h"
#include <stdlib.h>
#include <string.h>

int *krabbenpos = {0};
int max = 0;
int anzahlKrabben = 0;

int fuel(int max);
void einlesen(FILE *fp);
void zahlZufuegen(int zahl);

int main(int argc, char *argv[])
{

    read("realinput7.txt");
}

void parstxt(FILE *fp)
{
    int minfuel = 1000000000;
    einlesen(fp);
    printf("Menge der Krabben: %d \n", anzahlKrabben);

    for (int i = 0; i < max; i++)
    {
        if (fuel(i) < minfuel)
        {
            minfuel = fuel(i);
        }
    }

    printf("\nmin fuel ist: %d \n\n", minfuel);
}

void einlesen(FILE *fp)
{
    int temp = leseZahl(fp);

    while (temp != -1)
    {
        zahlZufuegen(temp);
        if (temp > max)
        {
            max = temp;
        }
        temp = leseZahl(fp);
    }
}

int fuel(int pos)
{
    int summe = 0;
    for (int i = 0; i < anzahlKrabben; i++)
    {

        int fuel = krabbenpos[i] - pos;
        if (fuel < 0)
        {
            fuel = fuel * -1;
        }
        
        summe = summe + (fuel*(fuel+1)/2);
    }

    return summe;
}

void zahlZufuegen(int zahl)
{
    int intSize = sizeof(int);
    int bisherigeGroesse = anzahlKrabben;
    int neueGroesse = (bisherigeGroesse + 1);
    int *alt = krabbenpos;
    krabbenpos = (int *)malloc(neueGroesse * intSize);
    memcpy(krabbenpos, alt, bisherigeGroesse * intSize);
    krabbenpos[neueGroesse - 1] = zahl;
    free(alt);
    anzahlKrabben = anzahlKrabben + 1;
}