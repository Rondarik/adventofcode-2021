
#include "common.h"

int leseZahl(FILE *fp);

int main(int argc, char *argv[])
{
    read("realinput5.txt");
}

void parstxt(FILE *fp)
{
    int ventsBoard[1000][1000] = {0};

    int x1,x2;
    int y1,y2;

    while ((x1 = leseZahl(fp)) != -1)
    {

        
        y1 = leseZahl(fp);
        fgetc(fp);
        fgetc(fp);
        fgetc(fp);
        x2 = leseZahl(fp);
        y2 = leseZahl(fp);

        printf("%d,%d -> %d,%d\n\n", x1, y1, x2, y2);

        if (x1 > x2)
        {
            int temp;
            temp = x1;
            x1 = x2;
            x2 = temp;
        }
        
        if (y1 > y2)
        {
            int temp;
            temp = y1;
            y1 = y2;
            y2 = temp;
        }


        if (x1 == x2)
        {
            for (int y = y1; y <= y2; y++)
            {
                ventsBoard[x1][y] += 1;
            }
        }
        else if (y1 == y2)
        {
            for (int x = x1; x <= x2; x++)
            {
                ventsBoard[x][y1] += 1;
            }
        }
    }

    for (int y = 0; y < 1000; y++)
    {
        for (int x = 0; x < 1000; x++)
        {
            printf("%d", ventsBoard[x][y]);
        }
        printf("\n");
    }
    printf("\n\n");
}

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