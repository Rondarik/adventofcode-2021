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
    int filterCO2[zeilen] = {1};
    int filterOX[zeilen] = {1};
    for (int j = 0; j < zeilen; j++)
    {
        filterCO2[j] = 1;
        filterOX[j] = 1;
    }

    int anzEinsen = 0;
    int anzNullen = 0;
    int anzBetrachtetCO2 = 0;
    int anzBetrachtetOX = 0;
    int loesungCO2[spalten] = {0};
    int loesungOX[spalten] = {0};
    int bigdata[zeilen][spalten];

    for (int j = 0; j < zeilen; j++)
    {
        for (int i = 0; i < spalten; i++)
        {
            bigdata[j][i] = fgetc(fp) - '0';
        }
        fgetc(fp); // zeilenumbruch rauswerfen
    }

   
    for (int i = 0; i < spalten; i++)
    {
        anzBetrachtetCO2 = 0;
        anzBetrachtetOX = 0;
        anzEinsen = 0;
        anzNullen = 0;

        for (int j = 0; j < zeilen; j++)
        {
            if (filterCO2[j] == 1)
            {
                anzEinsen += bigdata[j][i];
                anzBetrachtetCO2++;
            }
            if (filterOX[j] == 1)
            {
                if (bigdata[j][i] == 0)
                {
                    anzNullen++;
                }
                anzBetrachtetOX++;
                
            }
        }
        if (anzEinsen < anzBetrachtetCO2 - anzEinsen)
        {
            loesungCO2[i] = 1;
        }
        if (anzNullen <= anzBetrachtetOX - anzNullen)
        {
            loesungOX[i] = 1;
        }
        int filter1CountCO2 = 0;
        int filter1IndexCO2 = 0;
        int filter1CountOX = 0;
        int filter1IndexOX = 0;
        for (int j = 0; j < zeilen; j++)
        {
            if (bigdata[j][i] != loesungCO2[i])
            {
                filterCO2[j] = 0;
            }
            if (filterCO2[j] == 1)
            {
                filter1CountCO2++;
                filter1IndexCO2 = j;
            }
             if (bigdata[j][i] != loesungOX[i])
            {
                filterOX[j] = 0;
            }
            if (filterOX[j] == 1)
            {
                filter1CountOX++;
                filter1IndexOX = j;
            }
        }
        if (filter1CountCO2 == 1)
        {
            for (int i = 0; i < spalten; i++)
            {
                loesungCO2[i] = bigdata[filter1IndexCO2][i];
            }
            filterCO2[filter1IndexCO2] = 0;
        }
        if (filter1CountOX == 1)
        {
            for (int i = 0; i < spalten; i++)
            {
                loesungOX[i] = bigdata[filter1IndexOX][i];
            }
            filterOX[filter1IndexOX] = 0;
        }
    }
    fclose(fp);

    int CO2rating = 0;
    for (int i = 0; i < spalten; i++)
    {
        printf("%d", loesungCO2[i]);
        CO2rating <<= 1;
        CO2rating += loesungCO2[i];
    }
    printf("\n %d \n", CO2rating);

    int OXrating = 0;
    for (int i = 0; i < spalten; i++)
    {
        printf("%d", loesungOX[i]);
        OXrating <<= 1;
        OXrating += loesungOX[i];
    }
    printf("\n %d", OXrating);
    printf("\n %d", OXrating*CO2rating);

}
