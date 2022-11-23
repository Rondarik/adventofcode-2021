
typedef struct elements
{
    int wert;
    void *nextElement;
} element;

typedef struct listpointer
{
    element *firstElement;
} sortedList;

sortedList *newList();
void addElement();
int sizeOfList();
int listWertBei();