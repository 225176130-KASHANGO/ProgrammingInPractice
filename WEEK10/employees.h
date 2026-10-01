/* employees.h
 * Public interface for the employees module.
 */

#ifndef EMPLOYEES_H
#define EMPLOYEES_H

void   addEmployee(void);
void   listEmployees(void);
double calculatePayrollTotal(void);
int    getEmployeeCount(void);

const char *getEmployeeName(int index);
int         getEmployeeId(int index);
double      getEmployeeSalary(int index);

/* used by fileio.c */
void addEmployeeRecord(int id, const char *name, double salary);
void resetEmployees(void);

#endif