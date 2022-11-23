
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
void addElement(sortedList*, int);
int sizeOfList(sortedList *);
int listWertBei(sortedList*, int);