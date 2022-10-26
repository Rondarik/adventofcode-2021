#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

stack *newStack()
{

    stack *ergebnis = (stack *)malloc(sizeof(stack));
    ergebnis->data = erzeuge();
    ergebnis->topIndex = -1;

    return ergebnis;
}

int peek(stack *theStack)
{

    return wertbei(theStack->data, theStack->topIndex, 0);
}

void push(stack *theStack, int c)
{
    // stheStack->topIndex++;
    wertRein(theStack->data, ++theStack->topIndex, 0, c);
}

int pop(stack *theStack)
{
    int temp = wertbei(theStack->data, theStack->topIndex--, 0);

    return temp;
}

int isEmpty(stack *theStack)
{
    if (theStack->topIndex == -1)
    {
        return 1;
    }

    return 0;
}

void clearStack(stack *theStack)
{
    while (!isEmpty(theStack))
    {
        pop(theStack);
    }
    

}