#include <stdio.h>
void parstxt (FILE *fp);

int main(int argc, char *argv[9])
{
    // Dateizeiger erstellen
    FILE *fp;

    // Datei oeffnen
    fp = fopen("realinput1.txt", "r");

    if (fp == NULL)
    {
        printf("Datei konnte NICHT geoeffnet werden.\n");
    }
    /*else
    {
        printf("Datei konnte geoeffnet werden.\n");
        // Datei schliessen
        fclose(fp);
    }*/

    parstxt(fp);
}

void parstxt (FILE *fp)
{
    int  temp, zeile = 0, zeilealt = 0, counter =0;
    // komplette Datei zeichenweise ausgeben
	while((temp = fgetc(fp))!=EOF) {
        if (temp != '\n') {
            zeile = ((zeile*10)+ temp-'0');
        } else {
            if  (zeilealt < zeile) {
                counter++;
            }
            //printf("%d ", zeile);
            zeilealt = zeile;
            zeile = 0;
        }   
	}
    
    printf("\n %d \n", counter-1);
	fclose(fp);
}