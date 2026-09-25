#include <stdio.h>

int main()
{
    double revenue;
    double expenses;
    double balance;
    int departments;
    double payroll;
    double procurement;
    double assets;

    printf("MUNICIPAL BUDGET CALCULATOR\n");
    printf("----------------------------------------\n");

    printf("Enter total revenue: ");
    scanf("%lf", &revenue);

    printf("Enter total expenses: ");
    scanf("%lf", &expenses);

    printf("Enter number of departments: ");
    scanf("%d", &departments);

    printf("Enter total payroll: ");
    scanf("%lf", &payroll);

    printf("Enter total procurement: ");
    scanf("%lf", &procurement);

    printf("Enter total assets: ");
    scanf("%lf", &assets);

    balance = revenue - expenses;

    printf("\n========================================\n");
    printf("     MUNICIPAL FINANCIAL SUMMARY\n");
    printf("========================================\n");
    printf("Revenue       : %.2f\n", revenue);
    printf("Expenses      : %.2f\n", expenses);
    printf("Balance       : %.2f\n", balance);
    printf("Departments   : %d\n", departments);
    printf("Payroll       : %.2f\n", payroll);
    printf("Procurement   : %.2f\n", procurement);
    printf("Assets        : %.2f\n", assets);
    printf("========================================\n");

    if (balance > 0)
    {
        printf("Status        : Surplus of %.2f\n", balance);
    }
    else if (balance < 0)
    {
        printf("Status        : Deficit of %.2f\n", -balance);
    }
    else
    {
        printf("Status        : The budget is balanced.\n");
    }

    return 0;
}