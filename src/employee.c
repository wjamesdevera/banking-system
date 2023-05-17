#include "../include/employee.h"

int employee_count = 0;
employee employees[MAX_EMPLOYEES];

void create_employee(char username[], char password[])
{
    if (find_employee(username))
    {
        printf("Username Already Exists\n");
        return;
    }

    if (employee_count > MAX_EMPLOYEES)
    {
        printf("ERROR: Maximum employee capacity reached\n");
        return;
    }

    strcpy(employees[employee_count].username, username);
    strcpy(employees[employee_count].password, username);
    employee_count++;
}

bool find_employee(char username[])
{
    for (int i = 0; i < employee_count; i++)
    {
        if (strcasecmp(employees[i].username, username) == 0)
        {
            return true;
        }
    }
    return false;
}

void store_employee_data()
{
    FILE *file;

    file = fopen(EMPLOYEE_DATA_PATH, "w");

    if (file == NULL)
    {
        printf("ERROR: Storing employee data");
        return;
    }

    for (int i = 0; i < employee_count; i++)
    {
        fprintf(file, "%s\n", employees[i].username);
        fprintf(file, "%s\n", employees[i].password);
    }

    fclose(file);
}

void load_employee_data()
{
    FILE *file;

    file = fopen(EMPLOYEE_DATA_PATH, "r");

    if (file == NULL)
    {
        printf("ERROR: Loading employee data");
        return;
    }

    char buffer[BUFFER_SIZE];
    int line = 0;
    while(fgets(buffer, BUFFER_SIZE, file) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (line % 2 == 0)
        {
            strcpy(employees[employee_count].username, buffer);
        }
        if (line % 2 == 1)
        {
            strcpy(employees[employee_count].password, buffer);
            employee_count++;
        }
        line++;
    }
    fclose(file);
}