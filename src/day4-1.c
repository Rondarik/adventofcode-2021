#include <stdio.h>
#include "common.h"

int gezogen[100];
typedef int board[5][5];
board boards[100];

void leseZahlen(FILE *fp);
void leseBoard(FILE *fp, board *myBoard);

int main(int argc, char *argv[])
{
    read("input4.txt");
}

void parstxt(FILE *fp)
{
    int temp;
    int boardCount = 0;

    leseZahlen(fp);
    while (temp = fgetc(fp) != EOF)
    {
        leseBoard(fp, &(boards[boardCount]));
        boardCount++;
    }
    printf("%d Boards gelesen\n\n", boardCount);
}

void leseZahlen(FILE *fp)
{
    int i = 0;
    int zahl = 0;
    int temp;

    while ((temp = fgetc(fp)) != '\n')
    {
        if (temp == ',')
        {
            i++;
            zahl = 0;
        }
        else
        {
            zahl = (zahl * 10) + (temp - '0');
            gezogen[i] = zahl;
        }
    }
}

void leseBoard(FILE *fp, board *myBoard)
{
    int x = 0, y = 0;
    int zahl = 0;
    int temp = 0;
    int ignoreblank = 1;

    while (y < 5)
    {
        temp = fgetc(fp);
        if (temp == ' ')
        {
            if (ignoreblank == 0)
            {
                x++;
                zahl = 0;
                ignoreblank = 1;
            }
        }
        else if ((temp == '\n') || (temp == EOF))
        {
            x = 0;
            y++;
            zahl = 0;
            ignoreblank = 1;
        }
        else
        {
            zahl = (zahl * 10) + (temp - '0');
            (*myBoard)[x][y] = zahl;
            ignoreblank = 0;
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            printf("%d ", (*myBoard)[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    // fflush(stdout);
}