#include "common.h"

int zaehleBuchstaben(FILE *fp);

int anzahl;

int main(int argc, char *argv[])
{

    read("realinput8.txt");
}

void parstxt(FILE *fp)
{
    int status = 0;
    int countNow = 0;
    int eins = 0;
    int vier = 0;
    int sieben = 0;
    int acht = 0;

    while (status != -1)
    {
        status = zaehleBuchstaben(fp);
        if (status == -2)
        {
            countNow = 1;
        }

        if (countNow == 1)
        {

            if (anzahl == 2)
            {
                eins++;
            }
            else if (anzahl == 4)
            {
                vier++;
            }
            else if (anzahl == 3)
            {
                sieben++;
            }
            else if (anzahl == 7)
            {
                acht++;
            }
        }
        if (status == -3)
        {
            countNow = 0;
        }
        //  printf("%d\n", anzahl);
    }

    printf("%d\n%d\n%d\n%d\n\n", eins, vier, sieben, acht);
    printf("%d\n\n",eins+vier+sieben+acht);
}

int zaehleBuchstaben(FILE *fp)
{
    int input = fgetc(fp);
    int blank = ' ';
    anzahl = 0;

    if (input == EOF)
    {
        return -1;
    }

    if (input == '|')
    {
        return -2;
    }

    while (input != blank)
    {
        anzahl += 1;
        input = fgetc(fp);

        if ((input == '\n') || (input == EOF))
        {
            return -3;
        }
    }

    return 1;
}