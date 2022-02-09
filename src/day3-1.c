#include <stdio.h>
#include "common.h"

#define spalten 12

int main(int argc, char *argv[9])
{
    read("realinput3.txt");
}

void parstxt(FILE *fp)
{
    int zeile = 1, temp, gamma = 0, epsilon = 0, pos = 0;
    int posa[spalten] = {0};

    while ((temp = fgetc(fp)) != EOF)
    {
        if (temp != '\n')
        {
            posa[pos] += temp - '0';
            pos++;
        }
        else
        {
            pos = 0;
            zeile++;
        }
    }

    for (int i = 0; i < spalten; i++)
    {
        gamma <<= 1;
        epsilon <<= 1;
        if (zeile - posa[i] < posa[i])
        {
            gamma |= 1;
        }
        else 
        {
            epsilon |= 1;
        }
    }

    //printf("\n gamma rate: %d epsilon rate: %d power: %d\n" , gamma, epsilon, (gamma*epsilon));
    printf(" Anz Zeilen: %d gamma: %d epsilon: %d power: %d\n", zeile, gamma, epsilon, gamma*epsilon);
    for (int i = 0; i < spalten; i++)
    {
        printf("posnr: %d wert: %d\n", i + 1, posa[i]);
    }
    fclose(fp);
}
