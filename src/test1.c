#include <stdio.h>

int main(int argc, char *argv[9])
{
    printf("starting\n");
    for (int i = 10; i >= 0; i--)
    {
        for (int sp = 0; sp < i; sp++)
        {
            printf(" ");
        }
        int stars = 2 * (10 - i) + 1;
        for (int s = 0; s < stars; s++)
        {
            printf("*");
        }
        printf("\n");
    }
}
