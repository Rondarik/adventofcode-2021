#include <stdlib.h>
#include <stdio.h>

#include "sortedList.h"


sortedList *newList()
{

    sortedList *ergebnis = (sortedList *)malloc(sizeof(sortedList));
    ergebnis->firstElement = NULL;
    return ergebnis;
}

void addElement(sortedList* list, int wert)
{
    element* newElement = (element *)malloc(sizeof(element));
    newElement->wert = wert;

    //An leere Liste anfuehgen
    if (list->firstElement == NULL)
    {
        list->firstElement = newElement;
    }
    //Am Anfang anfuehgen
    if (list->firstElement->wert > newElement->wert)
    {
        newElement->nextElement = list->firstElement;
        list->firstElement = newElement;
    }
    //Zwischen einfuehgen
    
    // Bei welchem Next.Wert muss die while aufhören damit ich das neue 
    // Elementeinfuehgen kann ohne das vorherige oder das aktuelle Element zu verlieren ??
    element* horst = list->firstElement->nextElement;
    while (horst->wert < wert)
    {
        horst = horst->nextElement;
        break;
    }
    
    

    //Am Ende anfuehgen
    if (/* condition */)
    {
        /* code */
    }
    
    




    list->firstElement
}

int sizeOfList(sortedList* list)
{

}

int listWertBei(int index)
{

}