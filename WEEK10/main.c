/* main.c
 * Entry point and coordinator for the MFMS.
 * Week 10 adds Save/Load menu options using the fileio module.
 */

#include <stdio.h>
#include "main.h"
#include "employees.h"
#include "budget.h"
#include "reports.h"
#include "utilities.h"
#include "fileio.h"

int displayMainMenu(void)
{
    int choice;

    printHeader(APP_NAME);
    printf("  Version %s\n", APP_VERSION);
    printLine();
    printf("  1. Add Employee\n");
    printf("  2. List Employees\n");
    printf("  3. Add Budget Entry\n");
    printf("  4. List Budget Entries\n");
    printf("  5. Employee Report\n");
    printf("  6. Budget Report\n");
    printLine();
    printf("  7. Save Data (text)\n");
    printf("  8. Load Data (text)\n");
    printf("  9. Save Data (binary)\n");
    printf(" 10. Load Data (binary)\n");
    printLine();
    printf("  0. Exit\n");
    printLine();

    choice = readInt("Enter your choice: ");
    return choice;
}

int main(void)
{
    int running = 1;
    int choice;

    printf("Welcome to the %s\n\n", APP_NAME);

    while (running) {
        choice = displayMainMenu();

        switch (choice) {
            case 1:  addEmployee();    pauseScreen(); break;
            case 2:  listEmployees();  pauseScreen(); break;
            case 3:  addBudget();      pauseScreen(); break;
            case 4:  listBudget();     pauseScreen(); break;
            case 5:  employeeReport(); pauseScreen(); break;
            case 6:  budgetReport();   pauseScreen(); break;

            case 7:
                saveEmployeesText();
                saveBudgetText();
                pauseScreen();
                break;

            case 8:
                loadEmployeesText();
                loadBudgetText();
                pauseScreen();
                break;

            case 9:
                saveEmployeesBinary();
                saveBudgetBinary();
                pauseScreen();
                break;

            case 10:
                loadEmployeesBinary();
                loadBudgetBinary();
                pauseScreen();
                break;

            case 0:
                printf("\nGoodbye.\n");
                running = 0;
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
                pauseScreen();
                break;
        }
    }

    return 0;
}