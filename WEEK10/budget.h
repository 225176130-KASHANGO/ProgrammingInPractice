/* budget.h
 * Public interface for the budget module.
 */

#ifndef BUDGET_H
#define BUDGET_H

void   addBudget(void);
void   listBudget(void);
double calculateBudgetBalance(void);
int    getBudgetCount(void);

int         getBudgetType(int index);
const char *getBudgetDescription(int index);
double      getBudgetAmount(int index);

/* used by fileio.c */
void addBudgetRecord(int type, const char *description, double amount);
void resetBudget(void);

#endif