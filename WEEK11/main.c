#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int id;
    char name[30];
    char department[20];
    double salary;
} Employee;

typedef struct {
    int id;
    char name[40];
    char email[40];
    char phone[15];
    char town[20];
} Supplier;

typedef struct {
    int id;
    char description[40];
    double value;
    Date acquired;
} Asset;

typedef struct {
    char department[20];
    double allocated;
    double spent;
} Budget;

typedef struct {
    int id;
    char title[40];
    double budget;
    Date startDate;
    Date endDate;
} Project;

int  addEmployee(Employee employees[], int count);
void displayEmployees(Employee employees[], int count);

int  addSupplier(Supplier suppliers[], int count);
void displaySuppliers(Supplier suppliers[], int count);

int  addAsset(Asset assets[], int count);
void displayAssets(Asset assets[], int count);

int  addBudget(Budget budgets[], int count);
void displayBudgets(Budget budgets[], int count);

int  addProject(Project projects[], int count);
void displayProjects(Project projects[], int count);

void saveEmployees(Employee employees[], int count);
int  loadEmployees(Employee employees[]);

int main(void)
{
    Employee employees[MAX_RECORDS];
    Supplier suppliers[MAX_RECORDS];
    Asset    assets[MAX_RECORDS];
    Budget   budgets[MAX_RECORDS];
    Project  projects[MAX_RECORDS];

    int employeeCount = 0;
    int supplierCount = 0;
    int assetCount    = 0;
    int budgetCount   = 0;
    int projectCount  = 0;

    int choice = 0;

    employeeCount = loadEmployees(employees);
    if (employeeCount > 0) {
        printf("%d employee(s) loaded from employees.dat.\n", employeeCount);
    }

    do {
        printf("\n===== MFMS MENU =====\n");
        printf("1.  Add Employee\n");
        printf("2.  Display Employees\n");
        printf("3.  Add Supplier\n");
        printf("4.  Display Suppliers\n");
        printf("5.  Add Asset\n");
        printf("6.  Display Assets\n");
        printf("7.  Add Budget\n");
        printf("8.  Display Budgets\n");
        printf("9.  Add Project\n");
        printf("10. Display Projects\n");
        printf("11. Save Employees to File\n");
        printf("12. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  employeeCount = addEmployee(employees, employeeCount); break;
            case 2:  displayEmployees(employees, employeeCount);            break;
            case 3:  supplierCount = addSupplier(suppliers, supplierCount); break;
            case 4:  displaySuppliers(suppliers, supplierCount);            break;
            case 5:  assetCount = addAsset(assets, assetCount);             break;
            case 6:  displayAssets(assets, assetCount);                     break;
            case 7:  budgetCount = addBudget(budgets, budgetCount);         break;
            case 8:  displayBudgets(budgets, budgetCount);                  break;
            case 9:  projectCount = addProject(projects, projectCount);     break;
            case 10: displayProjects(projects, projectCount);               break;
            case 11: saveEmployees(employees, employeeCount);               break;
            case 12: printf("Goodbye.\n");                                  break;
            default: printf("Invalid choice, try again.\n");
        }
    } while (choice != 12);

    return 0;
}

int addEmployee(Employee employees[], int count)
{
    if (count >= MAX_RECORDS) {
        printf("Employee list is full!\n");
        return count;
    }

    printf("Enter ID: ");
    scanf("%d", &employees[count].id);
    printf("Enter name: ");
    scanf("%29s", employees[count].name);
    printf("Enter department: ");
    scanf("%19s", employees[count].department);
    printf("Enter salary: ");
    scanf("%lf", &employees[count].salary);

    count++;
    printf("Employee added.\n");
    return count;
}

void displayEmployees(Employee employees[], int count)
{
    int i;

    if (count == 0) {
        printf("No employees to display.\n");
        return;
    }

    printf("\n%-6s %-15s %-15s %12s\n", "ID", "Name", "Department", "Salary");
    for (i = 0; i < count; i++) {
        printf("%-6d %-15s %-15s %12.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].department,
               employees[i].salary);
    }
}

int addSupplier(Supplier suppliers[], int count)
{
    if (count >= MAX_RECORDS) {
        printf("Supplier list is full!\n");
        return count;
    }

    printf("Enter ID: ");
    scanf("%d", &suppliers[count].id);
    printf("Enter name: ");
    scanf("%39s", suppliers[count].name);
    printf("Enter email: ");
    scanf("%39s", suppliers[count].email);
    printf("Enter phone: ");
    scanf("%14s", suppliers[count].phone);
    printf("Enter town: ");
    scanf("%19s", suppliers[count].town);

    count++;
    printf("Supplier added.\n");
    return count;
}

void displaySuppliers(Supplier suppliers[], int count)
{
    int i;

    if (count == 0) {
        printf("No suppliers to display.\n");
        return;
    }

    printf("\n%-6s %-15s %-25s %-15s %-15s\n",
           "ID", "Name", "Email", "Phone", "Town");
    for (i = 0; i < count; i++) {
        printf("%-6d %-15s %-25s %-15s %-15s\n",
               suppliers[i].id,
               suppliers[i].name,
               suppliers[i].email,
               suppliers[i].phone,
               suppliers[i].town);
    }
}

int addAsset(Asset assets[], int count)
{
    if (count >= MAX_RECORDS) {
        printf("Asset list is full!\n");
        return count;
    }

    printf("Enter ID: ");
    scanf("%d", &assets[count].id);
    printf("Enter description: ");
    scanf("%39s", assets[count].description);
    printf("Enter value: ");
    scanf("%lf", &assets[count].value);
    printf("Enter acquired date (day month year): ");
    scanf("%d %d %d",
          &assets[count].acquired.day,
          &assets[count].acquired.month,
          &assets[count].acquired.year);

    count++;
    printf("Asset added.\n");
    return count;
}

void displayAssets(Asset assets[], int count)
{
    int i;

    if (count == 0) {
        printf("No assets to display.\n");
        return;
    }

    printf("\n%-6s %-20s %12s %15s\n", "ID", "Description", "Value", "Acquired");
    for (i = 0; i < count; i++) {
        printf("%-6d %-20s %12.2f  %02d/%02d/%04d\n",
               assets[i].id,
               assets[i].description,
               assets[i].value,
               assets[i].acquired.day,
               assets[i].acquired.month,
               assets[i].acquired.year);
    }
}

int addBudget(Budget budgets[], int count)
{
    if (count >= MAX_RECORDS) {
        printf("Budget list is full!\n");
        return count;
    }

    printf("Enter department: ");
    scanf("%19s", budgets[count].department);
    printf("Enter allocated amount: ");
    scanf("%lf", &budgets[count].allocated);
    printf("Enter spent amount: ");
    scanf("%lf", &budgets[count].spent);

    count++;
    printf("Budget added.\n");
    return count;
}

void displayBudgets(Budget budgets[], int count)
{
    int i;

    if (count == 0) {
        printf("No budgets to display.\n");
        return;
    }

    printf("\n%-15s %12s %12s %12s\n",
           "Department", "Allocated", "Spent", "Balance");
    for (i = 0; i < count; i++) {
        printf("%-15s %12.2f %12.2f %12.2f\n",
               budgets[i].department,
               budgets[i].allocated,
               budgets[i].spent,
               budgets[i].allocated - budgets[i].spent);

        if (budgets[i].spent > budgets[i].allocated) {
            printf("  WARNING: %s is over budget!\n", budgets[i].department);
        }
    }
}

int addProject(Project projects[], int count)
{
    if (count >= MAX_RECORDS) {
        printf("Project list is full!\n");
        return count;
    }

    printf("Enter ID: ");
    scanf("%d", &projects[count].id);
    printf("Enter title: ");
    scanf("%39s", projects[count].title);
    printf("Enter budget: ");
    scanf("%lf", &projects[count].budget);
    printf("Enter start date (day month year): ");
    scanf("%d %d %d",
          &projects[count].startDate.day,
          &projects[count].startDate.month,
          &projects[count].startDate.year);
    printf("Enter end date (day month year): ");
    scanf("%d %d %d",
          &projects[count].endDate.day,
          &projects[count].endDate.month,
          &projects[count].endDate.year);

    count++;
    printf("Project added.\n");
    return count;
}

void displayProjects(Project projects[], int count)
{
    int i;

    if (count == 0) {
        printf("No projects to display.\n");
        return;
    }

    printf("\n%-6s %-20s %12s %15s %15s\n",
           "ID", "Title", "Budget", "Start", "End");
    for (i = 0; i < count; i++) {
        printf("%-6d %-20s %12.2f  %02d/%02d/%04d     %02d/%02d/%04d\n",
               projects[i].id,
               projects[i].title,
               projects[i].budget,
               projects[i].startDate.day,
               projects[i].startDate.month,
               projects[i].startDate.year,
               projects[i].endDate.day,
               projects[i].endDate.month,
               projects[i].endDate.year);
    }
}

void saveEmployees(Employee employees[], int count)
{
    FILE *fp = fopen("employees.dat", "wb");

    if (fp == NULL) {
        perror("employees.dat");
        return;
    }

    fwrite(employees, sizeof(Employee), count, fp);
    fclose(fp);
    printf("%d employee(s) saved to employees.dat.\n", count);
}

int loadEmployees(Employee employees[])
{
    FILE *fp = fopen("employees.dat", "rb");
    int count;

    if (fp == NULL) {
        return 0;
    }

    count = (int)fread(employees, sizeof(Employee), MAX_RECORDS, fp);
    fclose(fp);
    return count;
}