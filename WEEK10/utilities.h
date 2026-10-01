/* utilities.h
 * Reusable helper functions for the MFMS.
 */

#ifndef UTILITIES_H
#define UTILITIES_H

void   printLine(void);
void   printHeader(const char *title);
void   pauseScreen(void);
void   clearInputBuffer(void);
int    readInt(const char *prompt);
double readDouble(const char *prompt);

#endif