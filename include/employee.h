#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#define MAX_EMPLOYEES 100
#define EMPLOYEE_DATA_PATH "./accounts/employee_record.txt"

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../include/capacity.h"

void create_employee(char username[], char password[]);
bool find_employee(char username[]);
void store_employee_data();
void load_employee_data();

typedef struct
{
    char username[STR_MAX_LENGTH];
    char password[STR_MAX_LENGTH];
} employee;

extern int employee_count;
extern employee employees[MAX_EMPLOYEES];

#endif