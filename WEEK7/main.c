#include <stdio.h>
#include <string.h>

int main()
{
    char supplierName[100];
    char email[100];
    char phone[30];
    char town[50];
    char backup[100];
    char description[300];
    char searchName[100];
    char supplier1[] = "ABC Office Supplies";
    char supplier2[] = "Namibia Stationery";

    printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("Supplier Management Module\n");
    printf("========================================\n\n");

    printf("Enter supplier name: ");
    fgets(supplierName, sizeof(supplierName), stdin);
    supplierName[strcspn(supplierName, "\n")] = '\0';

    printf("Enter email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Enter phone: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = '\0';

    printf("Enter town: ");
    fgets(town, sizeof(town), stdin);
    town[strcspn(town, "\n")] = '\0';

    printf("\n========================================\n");
    printf("           SUPPLIER DETAILS\n");
    printf("========================================\n");
    printf("Name  : %s\n", supplierName);
    printf("Email : %s\n", email);
    printf("Phone : %s\n", phone);
    printf("Town  : %s\n", town);

    printf("\n----------------------------------------\n");
    printf("           STRING LENGTHS\n");
    printf("----------------------------------------\n");
    printf("Supplier name length : %zu\n", strlen(supplierName));
    printf("Email length         : %zu\n", strlen(email));
    printf("Phone length         : %zu\n", strlen(phone));
    printf("Town length          : %zu\n", strlen(town));

    strcpy(backup, supplierName);
    printf("\n----------------------------------------\n");
    printf("           COPY OF SUPPLIER NAME\n");
    printf("----------------------------------------\n");
    printf("Original : %s\n", supplierName);
    printf("Backup   : %s\n", backup);

    strcpy(description, supplierName);
    strcat(description, " operates in ");
    strcat(description, town);
    strcat(description, ".");

    printf("\n----------------------------------------\n");
    printf("           SUPPLIER DESCRIPTION\n");
    printf("----------------------------------------\n");
    printf("%s\n", description);

    printf("\n----------------------------------------\n");
    printf("           SUPPLIER SEARCH\n");
    printf("----------------------------------------\n");
    printf("Enter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    if (strcmp(supplier1, searchName) == 0)
    {
        printf("Supplier found: %s\n", supplier1);
    }
    else if (strcmp(supplier2, searchName) == 0)
    {
        printf("Supplier found: %s\n", supplier2);
    }
    else
    {
        printf("Supplier not found.\n");
    }

    printf("\n========================================\n");

    return 0;
}