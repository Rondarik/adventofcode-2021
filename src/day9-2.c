#include "common.h"
#include <stdlib.h>
#include <stdio.h>

#include "dynarray.h"

int isLowPoint(dynArray *array, int x, int y);
dynArray *findeLowPoints(dynArray *array);
dynArray *erstelleNachbarListe(dynArray *array, int x, int y);
int istSinnvollerNachbar(dynArray *array, int x, int y);
int istInnerhalbDerGrenzen(dynArray *array, int x, int y);
dynArray *erstelleBasin(dynArray *array, int x, int y);

void parstxt(FILE *fp) {}

int main(int argc, char *argv[])
{
    dynArray *array = erzeuge();

    // Dateizeiger erstellen
    FILE *fp;

    // Datei oeffnen
    fp = fopen("input9.txt", "r");

    int i = 0, j = 0;
    int input = fgetc(fp);

    while (input != EOF)
    {
        while ((input != '\n') && (input != EOF))
        {
            wertRein(array, i, j, (input - '0'));
            j++;
            input = fgetc(fp);
        }
        i++;
        j = 0;
        input = fgetc(fp);
    }
    dynArray *koordinatenArray = findeLowPoints(array);
    ausgabe(koordinatenArray);
    printf("%d\n\n", getMaxX(koordinatenArray));
    
    dynArray *Nachbarn = erstelleNachbarListe(array, 0, 0);
}

dynArray *findeLowPoints(dynArray *array)
{
    dynArray *lowPointKoordinaten = erzeuge();
    int maxX = getMaxX(array);
    int maxY = getMaxY(array);
    int a = 0;

    for (int x = 0; x <= maxX; x++)
    {
        for (int y = 0; y <= maxY; y++)
        {
            if (isLowPoint(array, x, y))
            {
                wertRein(lowPointKoordinaten, a, 0, x);
                wertRein(lowPointKoordinaten, a, 1, y);
                a++;
            }
        }
    }
    return lowPointKoordinaten;
}


int isLowPoint(dynArray *array, int x, int y)
{
    int maxX = getMaxX(array);
    int maxY = getMaxY(array);
    int point = wertbei(array, x, y);

    if (x < maxX)
    {
        if (point >= wertbei(array, x + 1, y))
        {
            return 0;
        }
    }
    if (x > 0)
    {
        if (point >= wertbei(array, x - 1, y))
        {
            return 0;
        }
    }
    if (y > 0)
    {
        if (point >= wertbei(array, x, y - 1))
        {
            return 0;
        }
    }
    if (y < maxY)
    {
        if (point >= wertbei(array, x, y + 1))
        {
            return 0;
        }
    }

    return 1;
}

dynArray *erstelleNachbarListe(dynArray *array, int x, int y){
    dynArray *ListeNachbarn = erzeuge();
    int c = 0;

    if (istSinnvollerNachbar(array, x+1,y))
    {
        wertRein(ListeNachbarn,c ,0, x+1);
        wertRein(ListeNachbarn,c ,1, y);
        c++;
    } 
    if (istSinnvollerNachbar(array, x-1,y))
    {
        wertRein(ListeNachbarn,c ,0, x-1);
        wertRein(ListeNachbarn,c ,1, y);
        c++;
    }if (istSinnvollerNachbar(array, x,y+1))
    {
        wertRein(ListeNachbarn,c ,0, x);
        wertRein(ListeNachbarn,c ,1, y+1);
        c++;
    } if (istSinnvollerNachbar(array, x,y-1))
    {
        wertRein(ListeNachbarn,c ,0, x);
        wertRein(ListeNachbarn,c ,1, y-1);
        c++;
    } 
    ausgabe(ListeNachbarn);
    return ListeNachbarn;

}

int istSinnvollerNachbar(dynArray *array, int x, int y){

    if ((istInnerhalbDerGrenzen(array, x, y)) && (wertbei(array, x, y) < 9 ))
    {
        return 1; 
    }

    return 0;
}

int istInnerhalbDerGrenzen(dynArray *array, int x, int y){
    if ((x < 0) || (y < 0) || (x > getMaxX(array)) || (y > getMaxY(array)))
    {
        return 0;
    }
    
    return 1;
}

int istSchonGeprueft(){


}

dynArray *erstelleBasin(dynArray *array, int x, int y){
    dynArray *Basin = erzeuge();
    dynArray *dieLiebenNachbarn;

    wertRein(Basin, 0, 0 ,x);
    wertRein(Basin, 0, 1 ,y);

    dieLiebenNachbarn = erstelleNachbarListe(array, x, y);
    

    return Basin;
}