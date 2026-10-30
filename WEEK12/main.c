#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

typedef struct {
    int id;
    char name[30];
    double salary;
} Employee;

void basicPointerDemo(void);
void swapWrong(double a, double b);
void swapSalaries(double *a, double *b);
void swapEmployees(Employee *a, Employee *b);
double calculateAverage(const double salaries[], int n);
double findHighest(const double salaries[], int n);
void displaySalaries(const double salaries[], int n);
void giveRaise(double salaries[], int n, double percent);
void updateSalary(Employee *e, double newSalary);
Employee *findEmployee(Employee list[], int n, int id);
Employee *findHighestPaid(Employee list[], int n);
void sortEmployees(Employee list[], int n);

int main(void)
{
    Employee staff[MAX_EMPLOYEES] = {
        {1001, "Maria", 18500.50},
        {1002, "Simon", 17200.00},
        {1003, "Anna", 21000.75},
        {1004, "John", 15000.00}
    };
    int count = 4;
    int choice = 0;
    int id;
    double newSal;
    Employee *found;
    Employee *highest;

    basicPointerDemo();

    do {
        printf("\n===== WEEK 12 POINTERS MENU =====\n");
        printf("1. Display Employees & Salaries\n");
        printf("2. Update Employee Salary (Pointer to Struct)\n");
        printf("3. Give Raise to All (Array by Pointer)\n");
        printf("4. Find Highest Paid Employee\n");
        printf("5. Sort Employees by Salary (Swap)\n");
        printf("6. Test Swap Salaries (Value vs Address)\n");
        printf("7. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n%-6s %-15s %12s\n", "ID", "Name", "Salary");
                for (int i = 0; i < count; i++) {
                    printf("%-6d %-15s %12.2f\n", staff[i].id, staff[i].name, staff[i].salary);
                }
                break;

            case 2:
                printf("Enter Employee ID to update: ");
                scanf("%d", &id);
                found = findEmployee(staff, count, id);
                if (found != NULL) {
                    printf("Current salary for %s is N$%.2f\n", found->name, found->salary);
                    printf("Enter new salary: ");
                    scanf("%lf", &newSal);
                    updateSalary(found, newSal);
                    printf("Salary updated successfully.\n");
                } else {
                    printf("Employee not found.\n");
                }
                break;

            case 3:
                printf("Enter raise percentage (e.g., 10 for 10%%): ");
                scanf("%lf", &newSal);
                for (int i = 0; i < count; i++) {
                    giveRaise(&staff[i].salary, 1, newSal);
                }
                printf("Raise applied to all employees.\n");
                break;

            case 4:
                highest = findHighestPaid(staff, count);
                if (highest != NULL) {
                    printf("\nHighest paid: %s (N$%.2f)\n", highest->name, highest->salary);
                }
                break;

            case 5:
                sortEmployees(staff, count);
                printf("Employees sorted by salary (highest to lowest).\n");
                break;

            case 6: {
                double salA = 18500.50;
                double salB = 21000.75;
                printf("\nBefore swapWrong: A = %.2f, B = %.2f\n", salA, salB);
                swapWrong(salA, salB);
                printf("After swapWrong:  A = %.2f, B = %.2f (Did not work!)\n", salA, salB);
                
                swapSalaries(&salA, &salB);
                printf("After swapSalaries: A = %.2f, B = %.2f (Worked!)\n", salA, salB);
                break;
            }

            case 7:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}

void basicPointerDemo(void)
{
    int age = 25;
    int *p = &age;

    printf("--- Task A: Basic Pointer Warm-up ---\n");
    printf("age = %d\n", age);
    printf("&age = %p\n", (void*)&age);
    printf("*p = %d\n", *p);

    *p = 30;
    printf("After *p = 30, age = %d\n\n", age);
}

void swapWrong(double a, double b)
{
    double temp = a;
    a = b;
    b = temp;
}

void swapSalaries(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

void swapEmployees(Employee *a, Employee *b)
{
    Employee temp = *a;
    *a = *b;
    *b = temp;
}

double calculateAverage(const double salaries[], int n)
{
    double total = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        total += salaries[i];
    }
    return total / n;
}

double findHighest(const double salaries[], int n)
{
    double highest = salaries[0];
    int i;
    for (i = 1; i < n; i++) {
        if (salaries[i] > highest) {
            highest = salaries[i];
        }
    }
    return highest;
}

void displaySalaries(const double salaries[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("Employee %d: N$%.2f\n", i + 1, salaries[i]);
    }
}

void giveRaise(double salaries[], int n, double percent)
{
    int i;
    for (i = 0; i < n; i++) {
        salaries[i] = salaries[i] * (1 + percent / 100);
    }
}

void updateSalary(Employee *e, double newSalary)
{
    e->salary = newSalary;
}

Employee *findEmployee(Employee list[], int n, int id)
{
    int i;
    for (i = 0; i < n; i++) {
        if (list[i].id == id) {
            return &list[i];
        }
    }
    return NULL;
}

Employee *findHighestPaid(Employee list[], int n)
{
    int i;
    Employee *highest = &list[0];
    for (i = 1; i < n; i++) {
        if (list[i].salary > highest->salary) {
            highest = &list[i];
        }
    }
    return highest;
}

void sortEmployees(Employee list[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (list[j].salary < list[j + 1].salary) {
                swapEmployees(&list[j], &list[j + 1]);
            }
        }
    }
}