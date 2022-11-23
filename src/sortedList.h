#ifndef _SORTEDLIST_H_

#define _SORTEDLIST_H_

typedef struct listElements
{
    int wert;
    void *nextElement;
} listElement;

typedef struct listpointer
{
    listElement *firstElement;
} sortedList;

sortedList *newList();
void addElement(sortedList*, int);
int sizeOfList(sortedList *);
int listWertBei(sortedList*, int);

#endif