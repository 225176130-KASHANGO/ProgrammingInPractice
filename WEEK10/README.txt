MFMS - Week 10
==============

Modules
-------
main.c / main.h        - Program flow and menu
employees.c / .h       - Employee operations
budget.c / .h          - Budget operations
utilities.c / .h       - Input and printing helpers
reports.c / .h         - Reports
fileio.c / fileio.h    - File save/load (Week 10)

Data files
----------
data/employees.txt     - Text employee records (pipe-separated)
data/budget.txt        - Text budget records
data/employees.dat     - Binary employee records
data/budget.dat        - Binary budget records

Text format
-----------
1001|Maria|18500.50
1002|Simon|17200.00

Build
-----
gcc -std=c99 -Wall -Wextra -pedantic -c main.c
gcc -std=c99 -Wall -Wextra -pedantic -c employees.c
gcc -std=c99 -Wall -Wextra -pedantic -c budget.c
gcc -std=c99 -Wall -Wextra -pedantic -c utilities.c
gcc -std=c99 -Wall -Wextra -pedantic -c reports.c
gcc -std=c99 -Wall -Wextra -pedantic -c fileio.c

gcc main.o employees.o budget.o utilities.o reports.o fileio.o -o mfms

Run
---
./mfms