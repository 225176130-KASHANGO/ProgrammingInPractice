#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[30];
    double salary;
} Employee;

int main(void)
{
    int capacity = 2;
    int count = 0;
    int i;
    int searchId;
    int found;
    Employee *employees = NULL;
    Employee *bigger = NULL;
    Employee e;

    employees = malloc(capacity * sizeof(Employee));
    if (employees == NULL) {
        printf("Out of memory!\n");
        return 1;
    }

    printf("Employee ID (0 to stop): ");
    scanf("%d", &e.id);

    while (e.id != 0) {
        printf("Name (one word): ");
        scanf("%29s", e.name);
        printf("Salary: ");
        scanf("%lf", &e.salary);

        if (count == capacity) {
            capacity = capacity * 2;
            bigger = realloc(employees, capacity * sizeof(Employee));
            if (bigger == NULL) {
                printf("Out of memory!\n");
                free(employees);
                return 1;
            }
            employees = bigger;
            printf("(grown to %d slots)\n", capacity);
        }

        employees[count] = e;
        count++;

        printf("Employee ID (0 to stop): ");
        scanf("%d", &e.id);
    }

    printf("\n");
    for (i = 0; i < count; i++) {
        printf("%d %s N$%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
    printf("Employees: %d | Capacity: %d\n", count, capacity);

    printf("\nSearch Employee by ID (0 to skip): ");
    scanf("%d", &searchId);

    while (searchId != 0) {
        found = 0;
        for (i = 0; i < count; i++) {
            if (employees[i].id == searchId) {
                printf("Found: %d %s N$%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
                found = 1;
                break;
            }
        }
        if (found == 0) {
            printf("Employee not found.\n");
        }
        printf("Search Employee by ID (0 to skip): ");
        scanf("%d", &searchId);
    }

    free(employees);
    employees = NULL;

    return 0;
}