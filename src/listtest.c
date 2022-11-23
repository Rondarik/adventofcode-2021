#include <stdio.h>
#include "sortedList.h"

void addAndCheck(sortedList *list, int add, int expectedIndex, int expectedLength);
void checkLength(sortedList *list, int expectedLength);

int main(int argc, char *argv[])
{
    sortedList *list = newList();
    
    checkLength(list, 0);

    addAndCheck(list, 2, 0, 1);
    addAndCheck(list, 1, 0, 2);
    addAndCheck(list, 5, 2, 3);
    addAndCheck(list, 3, 2, 4);
    addAndCheck(list, -2, 0, 5);

    if (listWertBei(list, 0) != -2 || listWertBei(list, 1) != 1 || listWertBei(list, 2) != 2 || listWertBei(list, 3) != 3 || listWertBei(list, 3) != 5)
    {
        printf("reihenfolge falsch\n");
    }
}

void addAndCheck(sortedList *list, int add, int expectedIndex, int expectedLength)
{
    addElement(list, add);
    int wert = listWertBei(list, expectedIndex);
    if (wert != add)
    {
        printf("%d nicht richtig eingefügt, enthält %d\n", add, wert);
    }
    checkLength(list, expectedLength);
}
void checkLength(sortedList *list, int expectedLength)
{
    int length = sizeOfList(list);
    if (length != expectedLength)
    {
        printf("Länge falsch: sollte %d, ist %d\n", expectedLength, length);
    }
}