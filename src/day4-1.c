#include <stdio.h>
#include "common.h"

int gezogen[100];
typedef int board[5][5];
board boards[100];

void leseZahlen(FILE *fp);
void leseBoard(FILE *fp, board *myBoard);
int findeGewinnerBoard(int boardCount);
int pruefeBoard(int gezogeneZahl, board *aktuellesBoard);
int berechneScore(int letzteGezogeneZahl, board *winnerBoard);
void printBoard(board *myboard);

int main(int argc, char *argv[])
{
    read("realinput4.txt");
}

void parstxt(FILE *fp)
{
    int temp;
    int boardCount = 0;
    int score = 0;

    leseZahlen(fp);
    while (temp = fgetc(fp) != EOF)
    {
        leseBoard(fp, &(boards[boardCount]));
        boardCount++;
    }
    printf("%d Boards gelesen\n\n", boardCount);

    score = findeGewinnerBoard(boardCount);

    printf("der Gewinner ist %d\n\n", score);
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

    printBoard(myBoard);
    printf("\n");
}

void printBoard(board *myboard)
{
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            printf("%d ", (*myboard)[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}

int findeGewinnerBoard(int boardCount)
{
    int istGewinner = 0;

    for (int i = 0; i < sizeof(gezogen); i++)
    {
        int letzteGezogene = gezogen[i];
        printf("%d gezogen an Stelle %d\n", letzteGezogene, i);
        for (int j = 0; j < boardCount; j++)
        {
            board *myBord = &(boards[j]);
            istGewinner = pruefeBoard(letzteGezogene, myBord);
            if (istGewinner)
            {
                return berechneScore(letzteGezogene, myBord);
            }
        }
    }
    return -1;
}

int pruefeBoard(int gezogeneZahl, board *aktuellesBoard)
{
    int xCounter = 0;
    int yCounter[5] = {0};

    for (int y = 0; y < 5; y++)
    {
        xCounter = 0;
        for (int x = 0; x < 5; x++)
        {
            int inhalt = (*aktuellesBoard)[x][y];
            if (inhalt == gezogeneZahl)
            {
                (*aktuellesBoard)[x][y] = -1;
            }
            if ((*aktuellesBoard)[x][y] == -1)
            {
                xCounter++;
                yCounter[x]++;
                if ((xCounter == 5) || (yCounter[x] == 5))
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int berechneScore(int letzteGezogeneZahl, board *winnerBoard)
{
    int score = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int inhalt = (*winnerBoard)[i][j];
            if (inhalt != -1)
            {
                score += inhalt;
            }
        }
    }
    return score * letzteGezogeneZahl;
}
