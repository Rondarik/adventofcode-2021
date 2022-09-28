typedef struct
{
    int maxX;
    int maxY;
    int **data;
} dynArray;

dynArray *erzeuge();
void wertRein(dynArray *array, int xPos, int yPos, int wert);
int getMaxX(dynArray *array);
int getMaxY(dynArray *array);
void vergroessere(dynArray *array, int neuesX, int neuesY);
int wertbei(dynArray *array, int x, int y);
void ausgabe(dynArray *);