#include <stdio.h>
#include "utilities.h"

int readInt(void)
{
    int value;

    printf("Enter an integer: ");
    scanf("%d", &value);

    return value;
}

double readDouble(void)
{
    double value;

    printf("Enter a number: ");
    scanf("%lf", &value);

    return value;
}

void pauseScreen(void)
{
    printf("\nPress Enter to continue...");

    getchar();
    getchar();
}