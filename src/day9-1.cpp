//#include "common.h"
#include <stdlib.h>
#include <stdio.h>

#include "dynarray.h"
#include "arrayclass.h"

void parstxt(FILE *fp){};

int main(int argc, char *argv[])
{
    DynArray myArray;
    myArray.wertRein(0, 0, 1);
    myArray.ausgabe();
    myArray.wertRein(1, 1, 2);
    myArray.wertRein(0, 1, 3);
    myArray.wertRein(1, 0, 4);
    myArray.ausgabe();

    myArray.wertRein(2, 2, 5);
    myArray.ausgabe();
    myArray.wertRein(1, 3, 6);
    myArray.ausgabe();
    myArray.wertRein(3, 1, 7);
    myArray.ausgabe();
}


