
#include "common.h"

#define SIZE 1000

int main(int argc, char *argv[])
{
    read("realinput5.txt");
}

void parstxt(FILE *fp)
{
    int ventsBoard[SIZE][SIZE] = {0};

    int x1, x2;

    int y1, y2;

    while ((x1 = leseZahl(fp)) != -1)
    {

        y1 = leseZahl(fp);
        fgetc(fp);
        fgetc(fp);
        fgetc(fp);
        x2 = leseZahl(fp);
        y2 = leseZahl(fp);

        printf("%d,%d -> %d,%d\n\n", x1, y1, x2, y2);

        int xmin, xmax;
        int ymin, ymax;

        if (x1 > x2)
        {
            xmin = x2;
            xmax = x1;
        }
        else
        {
            xmin = x1;
            xmax = x2;
        }

        if (y1 > y2)
        {
            ymin = y2;
            ymax = y1;
        }
        else
        {
            ymin = y1;
            ymax = y2;
        }

        if (xmin == xmax)
        {
            for (int y = ymin; y <= ymax; y++)
            {
                ventsBoard[x1][y] += 1;
            }
        }
        else if (ymin == ymax)
        {
            for (int x = xmin; x <= xmax; x++)
            {
                ventsBoard[x][y1] += 1;
            }
        }
        else if ((xmax - xmin) == (ymax - ymin))
        {
            if (((x1 == xmax) && (y1 == ymin)) || ((x1 == xmin) && (y1 == ymax)))
            {
                int y = ymax;
                for (int x = xmin; x <= xmax; x++, y--)
                {
                    ventsBoard[x][y] += 1;
                }
            }
            else
            {
                int y = ymin;
                for (int x = xmin; x <= xmax; x++, y++)
                {
                    ventsBoard[x][y] += 1;
                }
            }
        }
    }

    int count = 0;

    for (int y = 0; y < SIZE; y++)
    {
        for (int x = 0; x < SIZE; x++)
        {

            if (ventsBoard[x][y] >= 2)
            {
                count++;
            }
        }
    }

    printf("%d\n\n", count);
}
