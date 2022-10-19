#include "common.h"
#include <stdlib.h>
#include <stdio.h>

#include "dynarray.h"

typedef struct myStack 
{
    dynArray *data;
    int topIndex;
}stack;


char peek(stack*);
void push(stack *, char);
char pop(stack *);
int isEmpty(stack *);

void parstxt(FILE *fp) {}

int main(int argc, char *argv[])
{

    stack *theStack = newStack();

    // Datei oeffnen
    // FILE *fp = fopen("input10.txt", "r");

    if (!isEmpty(theStack))
    {
        printf("fail empty\n");
    }

    push(theStack, 'a');

    if (isEmpty(theStack))
    {
        printf("fail push\n");
    }

    push(theStack, 'b');

    if (peek(theStack) != 'b')
    {
        printf("fail peek\n");
    }
    if (pop(theStack) != 'b')
    {
        printf("fail pop b\n");
    }
    if (pop(theStack) != 'a')
    {
        printf("fail pop a\n");
    }
    if (!isEmpty(theStack))
    {
        printf("fail pop empty\n");
    }
}

stack *newStack(){

    stack *ergebnis = (stack*)malloc(sizeof(stack));
    ergebnis->data = erzeuge();
    ergebnis->topIndex = -1;

    return ergebnis;
}

char peek(stack *theStack)
{

    return wertbei(theStack, getMaxX(theStack), 0);
}

void push(stack *theStack, char c)
{

    wertRein(theStack, groesseX(theStack), 0, c);
}

char pop(stack *theStack)
{

    return wertbei(theStack, getMaxX(theStack), 0);
    
}

int isEmpty(stack *theStack)
{
    if (groesseX(theStack) == 0)
    {
        return 1;
    }

    return 0;
}