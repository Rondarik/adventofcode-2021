#include <stdio.h>
void parstxt(FILE *fp);
int sucheZahl(FILE *fp);

int main(int argc, char *argv[9])
{
    // Dateizeiger erstellen
    FILE *fp;

    // Datei oeffnen
    fp = fopen("realinput2.txt", "r");

    if (fp == NULL)
    {
        printf("Datei konnte NICHT geoeffnet werden.\n");
    }

    parstxt(fp);
}

void parstxt(FILE *fp)
{
    int temp, horizontal = 0, depth = 0;
    // komplette Datei zeichenweise ausgeben
    while ((temp = fgetc(fp)) != EOF)
    {
        if (temp == 'f')
        {
            horizontal += sucheZahl(fp);
        }
        else if (temp == 'd')
        {
            depth += sucheZahl(fp);
        }
        else if (temp == 'u')
        {
            depth -= sucheZahl(fp);
        }
    }

    printf("\n %d \n", (depth * horizontal));
    fclose(fp);
}

int sucheZahl(FILE *fp)
{
    int temp;
    while ((temp = fgetc(fp)) < 48 || temp > 57)
    { // Ziffer suchen
    }
    return (temp - '0');
}