#include <stdio.h>

#include "employees.h"
#include "budget.h"
#include "utilities.h"
#include "reports.h"

int main(void)
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("====================================\n");

        printf("1. Add Employee\n");
        printf("2. List Employees\n");
        printf("3. Search Employee\n");
        printf("4. Add Budget\n");
        printf("5. Employee Report\n");
        printf("6. Budget Report\n");
        printf("7. Calculate Payroll Total\n");
        printf("8. Calculate Budget Balance\n");
        printf("0. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                listEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                addBudget();
                break;

            case 5:
                employeeReport();
                break;

            case 6:
                budgetReport();
                break;

            case 7:
                printf("Payroll Total: %.2f\n",
                       calculatePayrollTotal());
                break;

            case 8:
                printf("Budget Balance: %.2f\n",
                       calculateBudgetBalance());
                break;

            case 0:
                printf("\nExiting the system...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}