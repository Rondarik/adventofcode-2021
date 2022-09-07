#include "common.h"

const int blank = ' ';

__int8_t eins = 0;
__int8_t vier = 0;
__int8_t sieben = 0;

int einlesen(FILE *, int inOutput);
__int8_t setBit(__int8_t temp, int bit);
void setGlobalVariable(int anzahl, __int8_t temp);
int vergleich(int anzahl, __int8_t temp);
int auswertungFuenfBit(__int8_t temp);
int auswertungSechsBit(__int8_t temp);
int bitCount(__int8_t temp);

int zeilenEnde = 0;
int main(int argc, char *argv[])
{
    read("input8.txt");
}

void parstxt(FILE *fp)
{
    int inOutput = 0;
    int anzahl = 1;

    while (!zeilenEnde || (anzahl != 0))
    {
        anzahl = einlesen(fp, inOutput);
        if (anzahl == 1) // start output gefunden
        {
            inOutput = 1;
        }

        if (zeilenEnde)
        {
            inOutput = 0;
        }
    }
}

int einlesen(FILE *fp, int inOutput)
{
    zeilenEnde = 0;
    int anzahl = 0;
    int ergebnis;
    __int8_t temp = 0;

    int input = fgetc(fp);
    while (input != blank)
    {
        if ((input != '\n') && (input != EOF)) // normales zeichen gelesen
        {
            anzahl++;
            temp = setBit(temp, (input - 'a'));
        }
        else // eol/eof gelesen
        {
            zeilenEnde = 1;
            break;
        }
        input = fgetc(fp);
    }

    if (inOutput == 0)
    {
        setGlobalVariable(anzahl, temp);
    }
    else
    {
        ergebnis = vergleich(anzahl, temp);
        printf("%d\n\n", ergebnis);
    }

    return anzahl;
}

__int8_t setBit(__int8_t temp, int bit)
{
    return temp | (1 << bit);
}

int vergleich(int anzahl, __int8_t temp)
{
    if (anzahl == 2)
    {
        return 1;
    }
    if (anzahl == 4)
    {
        return 4;
    }
    if (anzahl == 3)
    {
        return 7;
    }
    if (anzahl == 5)
    {
        return auswertungFuenfBit(temp);
    }

    if (anzahl == 6)
    {
        return auswertungSechsBit(temp);
    }
    if (anzahl == 7)
    {
        return 8;
    }
}

int auswertungFuenfBit(__int8_t temp)
{
    if (bitCount(temp & eins) == 2)
    {
        return 3;
    }
    if (bitCount(temp & vier) == 2)
    {
        return 2;
    }
    else
    {
        return 5;
    }
}

int auswertungSechsBit(__int8_t temp)
{
    if (bitCount(temp & eins) == 1)
    {
        return 6;
    }
    if (bitCount(temp & vier) == 4)
    {
        return 9;
    }
    else
    {
        return 0;
    }
}

void setGlobalVariable(int anzahl, __int8_t temp)
{
    if (anzahl == 2)
    {
        eins = temp;
    }
    if (anzahl == 3)
    {
        sieben = temp;
    }
    if (anzahl == 4)
    {
        vier = temp;
    }
}

int bitCount(__int8_t temp)
{
    __int8_t filter = 1;
    int anzahl = 0;

    for (int i = 0; i < 7; i++)
    {
        if ((temp & filter) != 0)
        {
            anzahl++;
        }
        filter = filter << 1;
    }
    return anzahl;
}