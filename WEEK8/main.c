#include <stdio.h>
#include <string.h>

void displayWelcome();
void displayMenu();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int searchEmployee(int id, int ids[], int size);

int main()
{
    int choice;
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int size = 5;

    displayWelcome();

    do
    {
        displayMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                float amount;
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("VAT: %.2f\n", calculateVAT(amount));
                break;
            }
            case 2:
            {
                float basic, housing, transport;
                printf("Enter basic salary: ");
                scanf("%f", &basic);
                printf("Enter housing allowance: ");
                scanf("%f", &housing);
                printf("Enter transport allowance: ");
                scanf("%f", &transport);
                printf("Gross salary: %.2f\n",
                       calculateSalary(basic, housing, transport));
                break;
            }
            case 3:
            {
                float revenue, expenses, balance;
                printf("Enter total revenue: ");
                scanf("%f", &revenue);
                printf("Enter total expenses: ");
                scanf("%f", &expenses);
                balance = calculateBudget(revenue, expenses);
                printf("Budget balance: %.2f\n", balance);

                if (balance > 0)
                {
                    printf("Status: SURPLUS\n");
                }
                else if (balance < 0)
                {
                    printf("Status: DEFICIT\n");
                }
                else
                {
                    printf("Status: BALANCED\n");
                }
                break;
            }
            case 4:
            {
                int id, position;
                printf("Enter employee ID: ");
                scanf("%d", &id);
                position = searchEmployee(id, employeeIDs, size);

                if (position == -1)
                {
                    printf("Employee not found.\n");
                }
                else
                {
                    printf("Employee found at position %d.\n", position);
                }
                break;
            }
            case 5:
            {
                printf("Goodbye.\n");
                break;
            }
            default:
            {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }

    } while (choice != 5);

    return 0;
}

void displayWelcome()
{
    printf("========================================\n");
    printf("  MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
}

void displayMenu()
{
    printf("\n----------------------------------------\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Exit\n");
    printf("----------------------------------------\n");
}

float calculateVAT(float amount)
{
    return amount * 0.15;
}

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

int searchEmployee(int id, int ids[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (ids[i] == id)
        {
            return i;
        }
    }
    return -1;
}