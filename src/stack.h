#include "dynarray.h"

typedef struct
{
    dynArray *data;
    int topIndex;
} stack;

stack *newStack();
int peek(stack *);
void push(stack *, int);
int pop(stack *);
int isEmpty(stack *);
void clearStack(stack *);
