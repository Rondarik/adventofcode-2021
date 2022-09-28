#include "common.h"
#include <stdlib.h>
#include <stdio.h>

#include "dynarray.h"

void parstxt(FILE *fp){};

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
            printf("%d/%d\n",j,i);
            input = fgetc(fp);
        }
        i++;
        j = 0;
        input = fgetc(fp);
       
    }
    ausgabe(array);
    // printf("werte: %d %d\n", wertbei(0, 0, array), wertbei(99, 99, array));
}
