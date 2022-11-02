#include <stdlib.h>
#include <stdio.h>

#include "stack.h"


stack *newStack()
{

    stack *ergebnis = (stack *)malloc(sizeof(stack));
    ergebnis->topElement = NULL;
    return ergebnis;
}

int peek(stack *theStack)
{
    return theStack->topElement->wert;
}

void push(stack *theStack, int c)
{
    element *temp = theStack->topElement;
    theStack->topElement = (element *)malloc(sizeof(element));

    theStack->topElement->wert = c;
    theStack->topElement->preElement = temp;
}

int pop(stack *theStack)
{

    int temp = theStack->topElement->wert;
    element *oldTop = theStack->topElement;
    theStack->topElement = theStack->topElement->preElement;
    free(oldTop);

    return temp;
}

int isEmpty(stack *theStack)
{
    if (theStack->topElement == NULL)
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