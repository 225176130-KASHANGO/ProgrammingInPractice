/* employees.c
 * Employee operations for the MFMS.
 */

#include <stdio.h>
#include <string.h>
#include "employees.h"

#define MAX_EMPLOYEES 100

static int    empIds[MAX_EMPLOYEES];
static char   empNames[MAX_EMPLOYEES][50];
static double empSalaries[MAX_EMPLOYEES];
static int    empCount = 0;

void addEmployee(void)
{
    if (empCount >= MAX_EMPLOYEES) {
        printf("Employee list is full.\n");
        return;
    }

    printf("\n--- Add Employee ---\n");

    printf("Enter employee ID: ");
    scanf("%d", &empIds[empCount]);
    while (getchar() != '\n')
        ;

    printf("Enter employee name: ");
    scanf("%49s", empNames[empCount]);
    while (getchar() != '\n')
        ;

    printf("Enter monthly salary: ");
    scanf("%lf", &empSalaries[empCount]);
    while (getchar() != '\n')
        ;

    empCount++;
    printf("Employee added successfully.\n");
}

void listEmployees(void)
{
    int i;

    printf("\n--- Employee List ---\n");

    if (empCount == 0) {
        printf("No employees stored yet.\n");
        return;
    }

    printf("%-8s %-20s %12s\n", "ID", "Name", "Salary");
    printf("----------------------------------------------\n");

    for (i = 0; i < empCount; i++) {
        printf("%-8d %-20s %12.2f\n",
               empIds[i], empNames[i], empSalaries[i]);
    }

    printf("----------------------------------------------\n");
    printf("Total: %d employee(s)\n", empCount);
}

double calculatePayrollTotal(void)
{
    int i;
    double total = 0.0;

    for (i = 0; i < empCount; i++) {
        total += empSalaries[i];
    }

    return total;
}

int getEmployeeCount(void)
{
    return empCount;
}

const char *getEmployeeName(int index)
{
    if (index < 0 || index >= empCount)
        return NULL;
    return empNames[index];
}

int getEmployeeId(int index)
{
    if (index < 0 || index >= empCount)
        return -1;
    return empIds[index];
}

double getEmployeeSalary(int index)
{
    if (index < 0 || index >= empCount)
        return 0.0;
    return empSalaries[index];
}

void addEmployeeRecord(int id, const char *name, double salary)
{
    if (empCount >= MAX_EMPLOYEES)
        return;

    empIds[empCount] = id;

    strncpy(empNames[empCount], name, 49);
    empNames[empCount][49] = '\0';

    empSalaries[empCount] = salary;
    empCount++;
}

void resetEmployees(void)
{
    empCount = 0;
}