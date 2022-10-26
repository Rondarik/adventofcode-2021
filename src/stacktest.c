#include <stdio.h>
#include "stack.h"


int main(int argc, char *argv[])
{

    stack *theStack = newStack();

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
