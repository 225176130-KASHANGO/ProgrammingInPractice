/* fileio.c
 * Implements save/load for employees and budget.
 * Text   -> data/x.txt (human readable, uses fprintf/fscanf)
 * Binary -> data/x.dat (raw bytes, uses fwrite/fread)
 */
#include <stdio.h>
#include <string.h>
#include "fileio.h"
#include "employees.h"
#include "budget.h"

#define EMP_TEXT  "data/employees.txt"
#define BUD_TEXT  "data/budget.txt"
#define EMP_BIN   "data/employees.dat"
#define BUD_BIN   "data/budget.dat"

/* ---------- TEXT ---------- */

int saveEmployeesText(void)
{
    FILE *fp;
    int i;
    int count = getEmployeeCount();

    fp = fopen(EMP_TEXT, "w");
    if (fp == NULL) {
        perror("Could not open employees.txt for writing");
        return 0;
    }

    for (i = 0; i < count; i++) {
        fprintf(fp, "%d|%s|%.2f\n",
                getEmployeeId(i),
                getEmployeeName(i),
                getEmployeeSalary(i));
    }

    fclose(fp);
    printf("Saved %d employee(s) to %s\n", count, EMP_TEXT);
    return 1;
}

int loadEmployeesText(void)
{
    FILE *fp;
    int id;
    char name[50];
    double salary;
    int loaded = 0;

    fp = fopen(EMP_TEXT, "r");
    if (fp == NULL) {
        perror("Could not open employees.txt for reading");
        return 0;
    }

    resetEmployees();

    while (fscanf(fp, "%d|%49[^|]|%lf\n", &id, name, &salary) == 3) {
        addEmployeeRecord(id, name, salary);
        loaded++;
    }

    fclose(fp);
    printf("Loaded %d employee(s) from %s\n", loaded, EMP_TEXT);
    return loaded;
}

int saveBudgetText(void)
{
    FILE *fp;
    int i;
    int count = getBudgetCount();

    fp = fopen(BUD_TEXT, "w");
    if (fp == NULL) {
        perror("Could not open budget.txt for writing");
        return 0;
    }

    for (i = 0; i < count; i++) {
        fprintf(fp, "%d|%s|%.2f\n",
                getBudgetType(i),
                getBudgetDescription(i),
                getBudgetAmount(i));
    }

    fclose(fp);
    printf("Saved %d budget entry(ies) to %s\n", count, BUD_TEXT);
    return 1;
}

int loadBudgetText(void)
{
    FILE *fp;
    int type;
    char desc[60];
    double amount;
    int loaded = 0;

    fp = fopen(BUD_TEXT, "r");
    if (fp == NULL) {
        perror("Could not open budget.txt for reading");
        return 0;
    }

    resetBudget();

    while (fscanf(fp, "%d|%59[^|]|%lf\n", &type, desc, &amount) == 3) {
        addBudgetRecord(type, desc, amount);
        loaded++;
    }

    fclose(fp);
    printf("Loaded %d budget entry(ies) from %s\n", loaded, BUD_TEXT);
    return loaded;
}

/* ---------- BINARY ---------- */

typedef struct {
    int    id;
    char   name[50];
    double salary;
} EmployeeRecord;

typedef struct {
    int    type;
    char   description[60];
    double amount;
} BudgetRecord;

int saveEmployeesBinary(void)
{
    FILE *fp;
    int i;
    int count = getEmployeeCount();
    EmployeeRecord rec;

    fp = fopen(EMP_BIN, "wb");
    if (fp == NULL) {
        perror("Could not open employees.dat for writing");
        return 0;
    }

    for (i = 0; i < count; i++) {
        rec.id = getEmployeeId(i);
        strncpy(rec.name, getEmployeeName(i), 49);
        rec.name[49] = '\0';
        rec.salary = getEmployeeSalary(i);

        if (fwrite(&rec, sizeof rec, 1, fp) != 1) {
            perror("Error writing employee record");
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    printf("Saved %d employee(s) to %s (binary)\n", count, EMP_BIN);
    return 1;
}

int loadEmployeesBinary(void)
{
    FILE *fp;
    EmployeeRecord rec;
    int loaded = 0;

    fp = fopen(EMP_BIN, "rb");
    if (fp == NULL) {
        perror("Could not open employees.dat for reading");
        return 0;
    }

    resetEmployees();

    while (fread(&rec, sizeof rec, 1, fp) == 1) {
        addEmployeeRecord(rec.id, rec.name, rec.salary);
        loaded++;
    }

    fclose(fp);
    printf("Loaded %d employee(s) from %s (binary)\n", loaded, EMP_BIN);
    return loaded;
}

int saveBudgetBinary(void)
{
    FILE *fp;
    int i;
    int count = getBudgetCount();
    BudgetRecord rec;

    fp = fopen(BUD_BIN, "wb");
    if (fp == NULL) {
        perror("Could not open budget.dat for writing");
        return 0;
    }

    for (i = 0; i < count; i++) {
        rec.type = getBudgetType(i);
        strncpy(rec.description, getBudgetDescription(i), 59);
        rec.description[59] = '\0';
        rec.amount = getBudgetAmount(i);

        if (fwrite(&rec, sizeof rec, 1, fp) != 1) {
            perror("Error writing budget record");
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    printf("Saved %d budget entry(ies) to %s (binary)\n", count, BUD_BIN);
    return 1;
}

int loadBudgetBinary(void)
{
    FILE *fp;
    BudgetRecord rec;
    int loaded = 0;

    fp = fopen(BUD_BIN, "rb");
    if (fp == NULL) {
        perror("Could not open budget.dat for reading");
        return 0;
    }

    resetBudget();

    while (fread(&rec, sizeof rec, 1, fp) == 1) {
        addBudgetRecord(rec.type, rec.description, rec.amount);
        loaded++;
    }

    fclose(fp);
    printf("Loaded %d budget entry(ies) from %s (binary)\n", loaded, BUD_BIN);
    return loaded;
}