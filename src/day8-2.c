#include "common.h"

const int blank = ' ';

__int8_t eins = 0;
__int8_t vier = 0;
//__int8_t sieben = 0;

int einlesen(FILE *);
__int8_t setBit(__int8_t setzeIn, int bit);
void setGlobalVariable(int anzahlBits, __int8_t setzeAuf);
int auswertung(__int8_t auszuwerten);
int auswertungFuenfBit(__int8_t auszuwerten);
int auswertungSechsBit(__int8_t auszuwerten);
int bitCount(__int8_t zaehleIn);

int zeilenEnde = 0;
int main(int argc, char *argv[])
{
    read("realinput8.txt");
}

void parstxt(FILE *fp)
{
    int inOutput = 0;
    int gelesen = 0;
    int anzahlBits = 0;
    int ergebnisProZeile = 0;
    int endsumme = 0;

    while (!zeilenEnde || (gelesen != 0))
    {
        gelesen = einlesen(fp);
        anzahlBits = bitCount(gelesen);

        if (anzahlBits == 0) // start output gefunden
        {
            inOutput = 1;
        }
        else
        {
            if (inOutput == 0)
            {
                setGlobalVariable(anzahlBits, gelesen);
                ergebnisProZeile = 0;
            }
            else
            {
                int ziffer = auswertung(gelesen);
                printf("gelesen: %d\n\n", ziffer);

                ergebnisProZeile = (ergebnisProZeile * 10 + ziffer);
            }
        }

        if (zeilenEnde)
        {
            endsumme = (endsumme + ergebnisProZeile);
            printf("Ergebnis Zeile: %d, Zwischensumme: %d\n", ergebnisProZeile, endsumme);
            ergebnisProZeile = 0;
            inOutput = 0;
        }
    }
    printf("Endergebnigs: %d\n", endsumme);
}

int einlesen(FILE *fp)
{
    zeilenEnde = 0;
    __int8_t gelesen = 0;

    int input = fgetc(fp);
    while (input != blank)
    {
        if ((input != '\n') && (input != EOF)) // normales zeichen gelesen
        {
            gelesen = setBit(gelesen, (input - 'a'));
        }
        else // eol/eof gelesen
        {
            zeilenEnde = 1;
            break;
        }
        input = fgetc(fp);
    }
    return gelesen;
}

__int8_t setBit(__int8_t setzeIn, int bit)
{
    return setzeIn | (1 << bit);
}

int auswertung(__int8_t auszuwerten)
{
    int anzahlBits = bitCount(auszuwerten);
    if (anzahlBits == 2)
    {
        return 1;
    }
    if (anzahlBits == 4)
    {
        return 4;
    }
    if (anzahlBits == 3)
    {
        return 7;
    }
    if (anzahlBits == 5)
    {
        return auswertungFuenfBit(auszuwerten);
    }

    if (anzahlBits == 6)
    {
        return auswertungSechsBit(auszuwerten);
    }
    if (anzahlBits == 7)
    {
        return 8;
    }
}

int auswertungFuenfBit(__int8_t auszuwerten)
{
    if (bitCount(auszuwerten & eins) == 2)
    {
        return 3;
    }
    if (bitCount(auszuwerten & vier) == 2)
    {
        return 2;
    }
    else
    {
        return 5;
    }
}

int auswertungSechsBit(__int8_t auszuwerten)
{
    if (bitCount(auszuwerten & eins) == 1)
    {
        return 6;
    }
    if (bitCount(auszuwerten & vier) == 4)
    {
        return 9;
    }
    else
    {
        return 0;
    }
}

void setGlobalVariable(int anzahlBits, __int8_t setzeAuf)
{
    if (anzahlBits == 2)
    {
        eins = setzeAuf;
    }
    if (anzahlBits == 4)
    {
        vier = setzeAuf;
    }
}

int bitCount(__int8_t zaehleIn)
{
    __int8_t filter = 1;
    int anzahlBits = 0;

    for (int i = 0; i < 7; i++)
    {
        if ((zaehleIn & filter) != 0)
        {
            anzahlBits++;
        }
        filter = filter << 1;
    }
    return anzahlBits;
}