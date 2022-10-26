#include "common.h"
#include <stdlib.h>
#include <stdio.h>

#include "dynarray.h"

typedef struct myStack
{
    dynArray *data;
    int topIndex;
} stack;

stack *newStack();
int peek(stack *);
void push(stack *, int);
int pop(stack *);
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

    push(theStack, 'c');
    if (pop(theStack) != 'c')
    {
        printf("fail pop c\n");
    }

    if (peek(theStack) != 'a')
    {
        printf("fail peek a\n");
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
    //stheStack->topIndex++;
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