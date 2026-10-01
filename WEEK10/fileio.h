/* fileio.h
 * File input/output for the MFMS.
 * Text and binary save/load using fopen, fprintf, fscanf, fwrite, fread.
 */

#ifndef FILEIO_H
#define FILEIO_H

/* Text file operations */
int saveEmployeesText(void);
int loadEmployeesText(void);
int saveBudgetText(void);
int loadBudgetText(void);

/* Binary file operations */
int saveEmployeesBinary(void);
int loadEmployeesBinary(void);
int saveBudgetBinary(void);
int loadBudgetBinary(void);

#endif