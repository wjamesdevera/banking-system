#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "capacity.h"

#define MAX_CUSTOMERS 100
#define CUSTOMER_DATA_PATH "./accounts/customer_records.txt"

bool find_customer(char username[]);
void create_customer(char username[], char password[]);
bool find_customer(char username[]);
void store_customer_data();
void load_customer_data();

void set_customer_full_name(char username[], char full_name[]);
void set_customer_age(char username[], int age);
void set_customer_gender(char username[], char gender[]);
void set_customer_address(char username[], char address[]);
void set_customer_occupation(char username[], char occupation[]);
void set_customer_nationality(char username[], char nationality[]);
void set_customer_height(char username[], float height);
void set_customer_weight(char username[], float weight);
void set_customer_status(char username[], char status[]);
void print_customer_details(char username[]);

void create_transaction_records(char username[]);
void write_trasanction_logs(char type[], char username[], float amount);
void generate_transaction_reciept(char username[]);
void view_transaction_history(char username[]);

bool authenticate_customer(char username[], char password[]);
// Declaration
typedef struct 
{
    char username[STR_MAX_LENGTH];
    char password[STR_MAX_LENGTH];
    char full_name[STR_MAX_LENGTH];
    int age;
    char gender[STR_MAX_LENGTH];
    char address[STR_MAX_LENGTH];
    char occupation[STR_MAX_LENGTH];
    char nationality[STR_MAX_LENGTH];
    float height;
    float weight;
    char status[STR_MAX_LENGTH];
} customer;

extern int customer_count;
extern customer customers[MAX_CUSTOMERS];

#endif