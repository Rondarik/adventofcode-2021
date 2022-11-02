
typedef struct elements
{
    int wert;
    void *preElement;
} element;

typedef struct stackpointer
{
    element *topElement;
} stack;

stack *newStack();
int peek(stack *);
void push(stack *, int);
int pop(stack *);
int isEmpty(stack *);
void clearStack(stack *);
