/* budget.c
 * Budget operations for the MFMS.
 */

#include <stdio.h>
#include <string.h>
#include "budget.h"

#define MAX_BUDGETS 100

static char   budDescriptions[MAX_BUDGETS][60];
static double budAmounts[MAX_BUDGETS];
static int    budTypes[MAX_BUDGETS];   /* 1 = income, 2 = expense */
static int    budCount = 0;

void addBudget(void)
{
    int type;

    if (budCount >= MAX_BUDGETS) {
        printf("Budget list is full.\n");
        return;
    }

    printf("\n--- Add Budget Entry ---\n");

    printf("Type (1 = Income, 2 = Expense): ");
    scanf("%d", &type);
    while (getchar() != '\n')
        ;

    if (type != 1 && type != 2) {
        printf("Invalid type. Entry cancelled.\n");
        return;
    }

    printf("Enter description: ");
    scanf("%59[^\n]", budDescriptions[budCount]);
    while (getchar() != '\n')
        ;

    printf("Enter amount: ");
    scanf("%lf", &budAmounts[budCount]);
    while (getchar() != '\n')
        ;

    budTypes[budCount] = type;
    budCount++;

    printf("Budget entry added.\n");
}

void listBudget(void)
{
    int i;

    printf("\n--- Budget Entries ---\n");

    if (budCount == 0) {
        printf("No budget entries yet.\n");
        return;
    }

    printf("%-10s %-30s %12s\n", "Type", "Description", "Amount");
    printf("----------------------------------------------------------------\n");

    for (i = 0; i < budCount; i++) {
        printf("%-10s %-30s %12.2f\n",
               (budTypes[i] == 1) ? "Income" : "Expense",
               budDescriptions[i],
               budAmounts[i]);
    }

    printf("----------------------------------------------------------------\n");
    printf("Balance: %.2f\n", calculateBudgetBalance());
}

double calculateBudgetBalance(void)
{
    int i;
    double balance = 0.0;

    for (i = 0; i < budCount; i++) {
        if (budTypes[i] == 1)
            balance += budAmounts[i];
        else
            balance -= budAmounts[i];
    }

    return balance;
}

int getBudgetCount(void)
{
    return budCount;
}

int getBudgetType(int index)
{
    if (index < 0 || index >= budCount)
        return 0;
    return budTypes[index];
}

const char *getBudgetDescription(int index)
{
    if (index < 0 || index >= budCount)
        return NULL;
    return budDescriptions[index];
}

double getBudgetAmount(int index)
{
    if (index < 0 || index >= budCount)
        return 0.0;
    return budAmounts[index];
}

void addBudgetRecord(int type, const char *description, double amount)
{
    if (budCount >= MAX_BUDGETS)
        return;

    budTypes[budCount] = type;

    strncpy(budDescriptions[budCount], description, 59);
    budDescriptions[budCount][59] = '\0';

    budAmounts[budCount] = amount;
    budCount++;
}

void resetBudget(void)
{
    budCount = 0;
}