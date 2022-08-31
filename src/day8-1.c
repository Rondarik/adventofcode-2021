#include "common.h"

const int blank = ' ';

int eins = 0;
int vier = 0;
int sieben = 0;
int acht = 0;

int zaehleBuchstaben(FILE *);
void erhoeheZaehler(int);

int zeilenEnde = 0;
int main(int argc, char *argv[])
{
    read("realinput8.txt");
}

void parstxt(FILE *fp)
{
    int inOutput = 0;
    int anzahl = 1;

    while (!zeilenEnde || (anzahl != 0))
    {
        anzahl = zaehleBuchstaben(fp);
        if (anzahl == 1) // start output gefunden
        {
            inOutput = 1;
        }

        if (inOutput == 1)
        {
            erhoeheZaehler(anzahl);
        }

        if (zeilenEnde)
        {
            inOutput = 0;
        }
    }

    printf("%d + %d + %d + %d = %d\n\n", eins, vier, sieben, acht, eins + vier + sieben + acht);
}

int zaehleBuchstaben(FILE *fp)
{
    zeilenEnde = 0;
    int anzahl = 0;

    int input = fgetc(fp);
    while (input != blank)
    {
        if ((input != '\n') && (input != EOF)) // normales zeichen gelesen
        {
            anzahl++;
        }
        else // eol/eof gelesen
        {
            zeilenEnde = 1;
            break;
        }
        input = fgetc(fp);
    }

    return anzahl;
}

void erhoeheZaehler(int anzahl)
{
    if (anzahl == 2)
    {
        eins++;
    }
    else if (anzahl == 4)
    {
        vier++;
    }
    else if (anzahl == 3)
    {
        sieben++;
    }
    else if (anzahl == 7)
    {
        acht++;
    }
}