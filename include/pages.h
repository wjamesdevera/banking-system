#ifndef PAGES_H
#define PAGES_H

#include "employee.h"
#include "customer.h"
#include <conio.h>

void main_menu();
void print_main_menu();

void employee_login_page();
void print_employee_login_menu();
void employee_login();
void employee_create_account_page();

void employee_dashboard();
void print_employee_dashboard_menu();
void account_management_page();
void transaction_history();
void transfer_money_page();
void loan_management();

void customer_login_page();
void print_customer_login_menu();
void create_customer_page();
void customer_login();


extern customer *current_customer;
extern employee *current_employee;

#endif