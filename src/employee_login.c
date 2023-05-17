#include "../include/employee_login.h"
#include "../include/employee.h"

bool authenticate_employee(char username[], char password[])
{
    for (int i = 0; i < employee_count; i++)
    {
        if (strcasecmp(employees[i].username, username) == 0 && strcmp(employees[i].password, password) == 0)
        {
            return true;
        }
    }
    return false;
}