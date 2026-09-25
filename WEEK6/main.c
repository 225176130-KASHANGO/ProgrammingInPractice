#include <stdio.h>

int main()
{
    float salaries[50];
    float budgets[10];
    char registrations[20][20];

    float totalSalary = 0;
    float averageSalary;
    float highestSalary;
    float lowestSalary;

    float totalBudget = 0;
    float averageBudget;
    float temp;

    int searchIndex;
    int found;

    printf("MUNICIPAL INFORMATION MANAGEMENT SYSTEM\n");
    printf("========================================\n\n");

    printf("SECTION A: EMPLOYEE SALARIES\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < 50; i++)
    {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);

        totalSalary = totalSalary + salaries[i];

        if (i == 0)
        {
            highestSalary = salaries[i];
            lowestSalary = salaries[i];
        }

        if (salaries[i] > highestSalary)
        {
            highestSalary = salaries[i];
        }

        if (salaries[i] < lowestSalary)
        {
            lowestSalary = salaries[i];
        }
    }

    averageSalary = totalSalary / 50;

    printf("\nAll Salaries:\n");
    for (int i = 0; i < 50; i++)
    {
        printf("%.2f\n", salaries[i]);
    }

    printf("\nSalary Report\n");
    printf("Total   : %.2f\n", totalSalary);
    printf("Average : %.2f\n", averageSalary);
    printf("Highest : %.2f\n", highestSalary);
    printf("Lowest  : %.2f\n", lowestSalary);

    printf("\nSearch for a salary: ");
    scanf("%f", &temp);
    found = 0;
    for (int i = 0; i < 50; i++)
    {
        if (salaries[i] == temp)
        {
            printf("Salary found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Salary not found.\n");
    }

    printf("\n========================================\n");
    printf("SECTION B: DEPARTMENT BUDGETS\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < 10; i++)
    {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);
        totalBudget = totalBudget + budgets[i];
    }

    averageBudget = totalBudget / 10;

    printf("\nAll Budgets:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%.2f\n", budgets[i]);
    }

    printf("\nBudget Report\n");
    printf("Total   : %.2f\n", totalBudget);
    printf("Average : %.2f\n", averageBudget);

    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - i - 1; j++)
        {
            if (budgets[j] > budgets[j + 1])
            {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("\nBudgets Sorted (Lowest to Highest):\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%.2f\n", budgets[i]);
    }

    printf("\n========================================\n");
    printf("SECTION C: VEHICLE REGISTRATIONS\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < 20; i++)
    {
        printf("Enter vehicle registration %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }

    printf("\nAll Vehicle Registrations:\n");
    for (int i = 0; i < 20; i++)
    {
        printf("%s\n", registrations[i]);
    }

    printf("\nSearch for a registration number: ");
    scanf("%19s", registrations[19]);
    found = 0;
    for (int i = 0; i < 20; i++)
    {
        int j = 0;
        int match = 1;
        while (registrations[i][j] != '\0' || registrations[19][j] != '\0')
        {
            if (registrations[i][j] != registrations[19][j])
            {
                match = 0;
                break;
            }
            j++;
        }
        if (match)
        {
            printf("Registration found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Registration not found.\n");
    }

    printf("\n========================================\n");
    printf("End of Municipal Information Report\n");
    printf("========================================\n");

    return 0;
}