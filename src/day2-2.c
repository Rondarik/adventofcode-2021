#include <stdio.h>
#include "common.h"

int main(int argc, char *argv[9])
{
    read("realinput2.txt");
}

void parstxt(FILE *fp)
{
    int temp, aim = 0, horizontal = 0, depth = 0;
    // komplette Datei zeichenweise ausgeben
    while ((temp = fgetc(fp)) != EOF)
    {
        if (temp == 'f')
        {
            temp = sucheZahl(fp);
            horizontal += temp;
            depth += aim * temp;
        }
        else if (temp == 'd')
        {
            aim += sucheZahl(fp);
        }
        else if (temp == 'u')
        {
            aim -= sucheZahl(fp);
        }
    }

    printf("\n depth: %d horizontal: %d result: %d \n", depth, horizontal, (depth * horizontal));
    fclose(fp);
}
