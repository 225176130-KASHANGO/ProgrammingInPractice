/* utilities.c
 * Implements helper functions declared in utilities.h
 */

#include <stdio.h>
#include "utilities.h"

void printLine(void)
{
    printf("--------------------------------------------------\n");
}

void printHeader(const char *title)
{
    printLine();
    printf("  %s\n", title);
    printLine();
}

void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void pauseScreen(void)
{
    printf("\nPress Enter to continue...");
    clearInputBuffer();
}

int readInt(const char *prompt)
{
    int value;
    int result;

    while (1) {
        printf("%s", prompt);
        result = scanf("%d", &value);

        if (result == 1) {
            clearInputBuffer();
            return value;
        }

        printf("  Invalid input. Please enter a whole number.\n");
        clearInputBuffer();
    }
}

double readDouble(const char *prompt)
{
    double value;
    int result;

    while (1) {
        printf("%s", prompt);
        result = scanf("%lf", &value);

        if (result == 1) {
            clearInputBuffer();
            return value;
        }

        printf("  Invalid input. Please enter a number.\n");
        clearInputBuffer();
    }
}