#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

int oeffnend(int input);
int passtZusammen(int oeffnend, int schliessend);
int wertVon(int schliessend);
int schliessend(int input);
int indexVon(int suchenIn[], int schliessend);

const int anzahlklammern = 4;
int oeffnendeKlammern[] = {'(', '[', '{', '<'};
int schliessendeKlammern[] = {')', ']', '}', '>'};
int klammerwerte[] = {3, 57, 1197, 25137};
int wertIncomplete[] = {1, 2, 3, 4};

int main(int argc, char *argv[])
{

    stack *theStack = newStack();

    // Datei oeffnen
    FILE *fp = fopen("realinput10.txt", "r");

    int64_t score = 0;
    int64_t korrekturScore = 0;
    int corrupted = 0;
    int low = 0;
    int middle = 0;
    int hight = 0;
    int input;
    int korrekturCount = 0;
    while ((input = getc(fp)) != EOF)
    {
        if (oeffnend(input))
        {
            push(theStack, input);
        }
        else if (schliessend(input))
        {
            if (corrupted)
            {
                continue;
            }

            if (isEmpty(theStack) || (!passtZusammen(pop(theStack), input)))
            {
                corrupted = 1;
                score += wertVon(input);
            }
        }
        else
        {
            if (corrupted || isEmpty(theStack))
            {
                corrupted = 0;
                clearStack(theStack);
            }
            else
            {
                korrekturCount++;
                while (!isEmpty(theStack))
                {
                    int temp = wertIncomplete[indexVon(oeffnendeKlammern, pop(theStack))];
                    korrekturScore = (korrekturScore * 5) + temp;
                }
                printf("korrekturScore: %ld\n", korrekturScore);
               

                korrekturScore = 0;
            }
        }
    }
    printf("Score: %ld\n", score);
    printf("korrekturen: %d\n", korrekturCount);
    //printf("korrekturScore: %ld\n\n", korrekturScore);
}

int oeffnend(int input)
{
    return indexVon(oeffnendeKlammern, input) != -1;
}
int schliessend(int input)
{
    return indexVon(schliessendeKlammern, input) != -1;
}

int passtZusammen(int oeffnend, int schliessend)
{
    int index = indexVon(schliessendeKlammern, schliessend);
    return oeffnendeKlammern[index] == oeffnend;
}

int wertVon(int schliessend)
{
    int index = indexVon(schliessendeKlammern, schliessend);
    return klammerwerte[index];
}

int indexVon(int suchenIn[], int schliessend)
{
    for (int i = 0; i < anzahlklammern; i++)
    {
        if (suchenIn[i] == schliessend)
        {
            return i;
        }
    }
    return -1;
}