#include "common.h"

int sucheZahl(FILE *fp)
{
    int temp;
    while ((temp = fgetc(fp)) < 48 || temp > 57)
    { // Ziffer suchen
    }
    return (temp - '0');
}

void read(const char *filename)
{
    // Dateizeiger erstellen
    FILE *fp;

    // Datei oeffnen
    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Datei konnte NICHT geoeffnet werden.\n");
    }
    else
    {
        parstxt(fp);
    }
}

//liest Ziffern aus und setzt sie zu einer Zahl zusammen
int leseZahl(FILE *fp)
{
    int temp = fgetc(fp);
    int zahl = 0;

    if (temp == EOF)
    {
        return -1;
    }
    
    while (temp >= 48 && temp <= 57)
    {
        zahl = (zahl * 10) + (temp - '0');
        temp = fgetc(fp);
    }
    return zahl;
}