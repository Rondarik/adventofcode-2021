#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

int oeffnend(int input);
int passtZusammen(int oeffnend, int schliessend);
int wertVon(int schliessend);
int schliessend(int input);

void parstxt(FILE *fp) {}

int main(int argc, char *argv[])
{

    stack *theStack = newStack();

    // Datei oeffnen
    FILE *fp = fopen("realinput10.txt", "r");

    int64_t score = 0;
    int corrupted = 0;
    int input;
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
            corrupted = 0;
            clearStack(theStack);
        }
    }
    printf("Score: %ld\n\n", score);
}

int oeffnend(int input)
{
    if (input == '(')
    {
        return 1;
    }
    if (input == '[')
    {
        return 1;
    }
    if (input == '{')
    {
        return 1;
    }
    if (input == '<')
    {
        return 1;
    }

    return 0;
}
int schliessend(int input)
{
    if (input == ')')
    {
        return 1;
    }
    if (input == ']')
    {
        return 1;
    }
    if (input == '}')
    {
        return 1;
    }
    if (input == '>')
    {
        return 1;
    }

    return 0;
}

int passtZusammen(int oeffnend, int schliessend)
{

    if (schliessend == ')')
    {
        return oeffnend == '(';
    }
    if (schliessend == ']')
    {
        return oeffnend == '[';
    }
    if (schliessend == '}')
    {
        return oeffnend == '{';
    }
    if (schliessend == '>')
    {
        return oeffnend == '<';
    }
}

int wertVon(int schliessend)
{

    if (schliessend == ')')
    {
        return 3;
    }
    if (schliessend == ']')
    {
        return 57;
    }
    if (schliessend == '}')
    {
        return 1197;
    }
    if (schliessend == '>')
    {
        return 25137;
    }
}