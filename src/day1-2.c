#include <stdio.h>
void parstxt(FILE *fp);
void flsum(int zahl);

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
    parstxt(fp);
}

void parstxt(FILE *fp)
{
    int temp, zeile = 0, sum = 0, counter = 0;
    int i = 0, sumold = 0;
    int array[3] = {0, 0, 0};

    // komplette Datei zeichenweise ausgeben
    while ((temp = fgetc(fp)) != EOF)
    {
        if (temp != '\n')
        {
            zeile = ((zeile * 10) + temp - '0');
        }
        else
        {
            array[2] = array[1];
            array[1] = array[0];
            array[0] = zeile;
            printf("o: %d, 1: %d, 2: %d \n", array[0], array[1], array[2]);
            zeile = 0;

            if (i >= 2)
            {
                sum = array[0] + array[1] + array[2];

                if (sumold < sum)
                {
                    counter++;
                }
                printf("%d \n", sum);
                sumold = sum;
            }
            i++;
        }
    }

    printf("\n %d \n", counter - 1);
    fclose(fp);
}
