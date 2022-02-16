#include <stdio.h>
#include "common.h"

#define spalten 12
#define zeilen 1000

int main(int argc, char *argv[9])
{
    read("realinput3.txt");
}

void parstxt(FILE *fp)
{
    int filter[zeilen] = {1};
    for (int j = 0; j < zeilen; j++)
    {
        filter[j] = 1;
    }

    int anzEinsen = 0;
    int anzBetrachtet = 0;
    int loesung[spalten] = {0};
    int bigdata[zeilen][spalten];

    for (int j = 0; j < zeilen; j++)
    {
        for (int i = 0; i < spalten; i++)
        {
            bigdata[j][i] = fgetc(fp) - '0';
        }
        fgetc(fp); //zeilenumbruch rauswerfen
    }

    int temp = 0;
    for (int i = 0; i < spalten; i++)
    {
        anzBetrachtet = 0;
        anzEinsen = 0;

        for (int j = 0; j < zeilen; j++)
        {
            if (filter[j] == 1)
            {
                anzEinsen += bigdata[j][i];
                anzBetrachtet++;
            }
        }
        if (anzEinsen < anzBetrachtet - anzEinsen)
        {
            loesung[i] = 1;
        }
        int filter1Count = 0;
        int filter1Index = 0;
        for (int j = 0; j < zeilen; j++)
        {
            if (bigdata[j][i] != loesung[i])
            {
                filter[j] = 0;
            }
            if (filter[j] == 1) {
                filter1Count++;
                filter1Index = j;
            }
        }
        if (filter1Count == 1) {
            for (int i = 0; i < spalten; i++) {
                loesung[i] = bigdata[filter1Index][i];
            }
            break;
        }
    }
    fclose(fp);

    for (int i = 0; i < spalten; i++)
    {
        printf("%d", loesung[i]);
        temp <<= 1;
        temp += loesung[i];
    }
    printf("\n %d", temp);
}
