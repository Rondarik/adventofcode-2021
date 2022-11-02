#include <stdlib.h>
#include <stdio.h>

#include "stack.h"


stack *newStack()
{
    stack *superStack = (stack *)malloc(sizeof(stack));
    *superStack = NULL;
    return superStack;
}

int peek(stack *theStack)
{
    return (*theStack)->wert;
}

void push(stack *theStack, int c)
{
    element *temp = *theStack;
    
    *theStack = (element *)malloc(sizeof(element));

    (*theStack)->wert = c;
    (*theStack)->preElement = temp;
}

int pop(stack *theStack)
{
    int temp = (*theStack)->wert;
    element *oldTop = *theStack;
    *theStack = (*theStack)->preElement;
    free(oldTop);

    return temp;
}

int isEmpty(stack *theStack)
{
    if (*theStack == NULL)
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