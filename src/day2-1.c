#include <stdio.h>
#include "common.h"

int main(int argc, char *argv[9])
{
    read("realinput2.txt");
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
