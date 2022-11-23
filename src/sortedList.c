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

    element *horst = list->firstElement;
    element *vorHorst = NULL;
    while (horst != NULL // nicht Ende der Liste (oder leere Liste)
           && horst->wert < wert)  // nicht vor horst einsortieren
    {
        vorHorst = horst;
        horst = horst->nextElement;
    }
    if (vorHorst == NULL) // kein kleineres Element gefunden
    {
        // An Anfang
        list->firstElement = newElement;
    }
    else
    {
        // in die Liste einreihen
        vorHorst->nextElement = newElement;
    }
    // Rest der Liste anhängen
    newElement->nextElement = horst;
}

int sizeOfList(sortedList *list)
{
    int anzahl = 0;
    element *horst = list->firstElement;
    while (horst != NULL)
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