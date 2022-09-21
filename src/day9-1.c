//#include "common.h"
#include <stdlib.h>
#include <stdio.h>

#include "dynarray.h"
#include "arrayclass.h"

void parstxt(FILE *fp){};

int main(int argc, char *argv[])
{
    dynArray *array = erzeuge();
    ausgabe(array);
    wertRein(array, 0, 0, 1);
    //   ausgabe(array);
    wertRein(array, 1, 1, 2);
    wertRein(array, 0, 1, 3);
    wertRein(array, 1, 0, 4);
    ausgabe(array);

    wertRein(array, 2, 2, 5);
    ausgabe(array);
    wertRein(array, 1, 3, 6);
    ausgabe(array);
    wertRein(array, 3, 1, 7);
    ausgabe(array);
    // printf("werte: %d %d\n", wertbei(0, 0, array), wertbei(99, 99, array));
}


