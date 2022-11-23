#include <stdlib.h>
#include <stdio.h>

#include "sortedList.h"

sortedList *newList()
{

    sortedList *ergebnis = (sortedList *)malloc(sizeof(sortedList));
    ergebnis->firstElement = NULL;
    return ergebnis;
}

void addElement(sortedList *list, int wert)
{
    element *newElement = (element *)malloc(sizeof(element));
    newElement->wert = wert;

    // An leere Liste anfuegen
    if (list->firstElement == NULL)
    {
        list->firstElement = newElement;
        return;
    }
    // Am Anfang anfuegen
    if (list->firstElement->wert > newElement->wert)
    {
        newElement->nextElement = list->firstElement;
        list->firstElement = newElement;
        return;
    }
    // Zwischen einfuegen
    element *horst = list->firstElement;
    element *vorHorst;
    while (horst->wert < wert)
    {

        // Am Ende anfuegen
        if (horst->nextElement == NULL)
        {
            horst->nextElement = newElement;
            return;
        }

        vorHorst = horst;
        horst = horst->nextElement;
    }
    vorHorst->nextElement = newElement;
    newElement->nextElement = horst;
    
}

int sizeOfList(sortedList *list)
{
    
    if (list->firstElement == NULL)
    {
        return 0;
    }
    
    int anzahl = 1;
    element *horst = list->firstElement;
    while (horst->nextElement != NULL)
    {
        horst = horst->nextElement;
        anzahl++;
    }
    
    return anzahl;
}

// index muss < sizeOfList(list) sein
int listWertBei(sortedList *list, int index)
{
    element *horst = list->firstElement;
    for (int i = 0; i < index; i++)
    {
        horst = horst->nextElement;

    }
    
    return horst->wert;
}