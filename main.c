#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

#define MAX_STR_LENGTH 128
#define MAX_CUSTOMERS 100
#define MAX_EMPLOYEE 100
#define BUFFER_SIZE 1024

#define RESET "\033[0m"
#define CYAN  "\033[36m" 
#define RED   "\033[31m" 
#define GREEN "\033[32m" 

int employee_count = 0;
int customer_count = 0;


void print_menu();
void employee_login();
void employee_login_page();
void employee_create_acc();
bool authenticate_employee_login(char username[], char password[]);
void retrieve_employee_acc();
bool find_employee(char username[]);
void add_employee_account(char username[], char password[]);
void retrieve_customer_acc();
void add_customer_acc(char username[], char password[]);
void customer_login_page();
bool authenticate_customer_login(char username[], char password[]);
void employee_page();
void create_customer_acc();
void set_current_customer(char username[]);
bool find_customer(char username[]);
void set_current_employee(char username[]);
void save_customers();
void account_management();

typedef struct {
    char account_id[MAX_STR_LENGTH];
    char username[MAX_STR_LENGTH];
    char password[MAX_STR_LENGTH];
    char first_name[MAX_STR_LENGTH];
    char last_name[MAX_STR_LENGTH];
    char full_name[MAX_STR_LENGTH];
    int age;
    char gender[MAX_STR_LENGTH];
    char address[MAX_STR_LENGTH];
    char occupation[MAX_STR_LENGTH];
    char nationality[MAX_STR_LENGTH];
    float height;
    float weight;
    char status[MAX_STR_LENGTH];
} Customer;

typedef struct {
    char username[MAX_STR_LENGTH];
    char password[MAX_STR_LENGTH];
} Employee;

Employee employees[MAX_EMPLOYEE];
Customer customers[MAX_CUSTOMERS];

Employee *current_employee;
Customer *current_customer;

int main()
{
    retrieve_employee_acc();
    retrieve_customer_acc();
    system("cls");
    char choice;
    bool main_on = true;
    while (main_on) 
    {
        printf("Banking Management System\n");
        print_menu();
        printf("Enter your choice: ");
        fflush(stdin);
        scanf("%c", &choice);

        switch (choice) 
        {
            case '1':
                system("cls");
                employee_login_page();
                break;
            case '2':
                customer_login_page();
                break;
            case '3':
                main_on = false;
                break;
            default:
                system("cls");
                printf(RED);
                printf("Invalid choice. Please try again.\n");
                printf(RESET);
        }
    }
    printf("%s\n", customers[1].username);
    printf("%d\n", customer_count);
    save_customers();
    return 0;
}

void print_menu() 
{
    printf("1 - Employee\n");
    printf("2 - Customer\n");
    printf("3 - Exit Application\n");
}

void employee_login_page()
{
    char choice;
    bool login_on = true;

    while (login_on)
    {
        printf("Employee Login Page\n");
        printf("1 - Login\n");
        printf("2 - Create Account\n");
        printf("3 - Back\n");
        printf("Enter your choice: ");
        fflush(stdin);
        scanf("%c", &choice);
        switch (choice)
        {
            case '1':
                login_on = false;
                employee_login();
                break;
            case '2':
                login_on = false;
                employee_create_acc();
                break;
            case '3':
                system("cls");
                login_on = false;
                return;
                break;
            default:
                system("cls");
                printf(RED);
                printf("Invalid Choice. Please try again\n");
                printf(RESET);
        }
    }
}

void employee_login()
{
    char username[MAX_STR_LENGTH];
    char password[MAX_STR_LENGTH];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    if (authenticate_employee_login(username, password))
    {
        system("cls");
        printf(GREEN);
        printf("ACCESS GRANTED\n");
        printf(RESET);
        set_current_employee(username);
        employee_page();
    }
    system("cls");
    printf(RED);
    printf("ACCESS DENIED\n");
    printf(RESET);

    employee_login_page();
}

bool authenticate_employee_login(char username[], char password[])
{
    for (int i = 0; i < employee_count; i++)
    {
        if (strcmp(username, employees[i].username) == 0 && strcmp(password, employees[i].password) == 0)
        {
            return true;
        }
    }
    return false;
}

void retrieve_employee_acc()
{
    employee_count = 0;
    FILE *file;
    char buffer[BUFFER_SIZE];
    int line = 0;

    file = fopen("./accounts/employee_acc.txt", "r");

    if (file == NULL) {
        printf("ERROR: Cannot open employee accounts\n");
        return;
    }

    while (fgets(buffer, BUFFER_SIZE, file) != NULL)
    {
        int len = strlen(buffer);
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

void employee_create_acc() 
{
    if (employee_count >= MAX_EMPLOYEE)
    {
        printf("EMPLOYEE ACCOUNT MAXED!\n");
        main();
    }

    char username[MAX_STR_LENGTH];
    char password[MAX_STR_LENGTH];

    printf("Employee Create Account Page\n");
    printf("Username: ");
    scanf("%s", username);
    if (find_employee(username))
    {
        system("cls");
        printf(RED);
        printf("Username already exists\n");
        printf(RESET);
        employee_login_page();
    }
    printf("Password: ");
    scanf("%s", password);
    add_employee_account(username, password);
    system("cls");
    printf(GREEN);
    printf("Account Creation Successful\n");
    printf(RESET);
    employee_login_page();
}

bool find_employee(char username[])
{
    for (int i = 0; i < employee_count; i++)
    {
        if (strcasecmp(username, employees[i].username) == 0)
        {
            return true;
        }
    }
    return false;
}

void add_employee_account(char username[], char password[])
{
    FILE *file;

    file = fopen("./accounts/employee_acc.txt", "a");

    if (file == NULL) {
        printf("ERROR: Cannot open employee accounts\n");
        return;
    }

    fprintf(file, "\n%s\n%s", username, password);

    fclose(file);
    retrieve_employee_acc();
    return;
}

void retrieve_customer_acc() 
{
    customer_count = 0;
    FILE *file;
    char buffer[BUFFER_SIZE];
    int line = 0;

    file = fopen("./accounts/customer_acc.txt", "r");

    if (file == NULL) {
        printf("ERROR: Cannot open customer accounts\n");
        return;
    }

    while (fgets(buffer, BUFFER_SIZE, file) != NULL)
    {
        int len = strlen(buffer);
        buffer[strcspn(buffer, "\n")] = '\0';

        if (line % 10 == 0)
        {
            strcpy(customers[customer_count].username, buffer);
        }
        if (line % 10 == 1)
        {
            strcpy(customers[customer_count].password, buffer);
        }
        if (line % 10 == 2)
        {
            strcpy(customers[customer_count].full_name, buffer);
        }
        if (line % 10 == 3)
        {
            customers[customer_count].age = atoi(buffer);
        }
        if (line % 10 == 4)
        {
            strcpy(customers[customer_count].gender, buffer);
        }
        if (line % 10 == 5)
        {
            strcpy(customers[customer_count].address, buffer);
        }
        if (line % 10 == 6)
        {
            strcpy(customers[customer_count].occupation, buffer);
        }
        if (line % 10 == 7)
        {
            customers[customer_count].height = atof(buffer);
        }
        if (line % 10 == 8)
        {
            customers[customer_count].weight = atof(buffer);
        }
        if (line % 10 == 9)
        {
            strcpy(customers[customer_count].status, buffer);
            customer_count++;
        }
        line++;
    }

    fclose(file);
}

void add_customer_acc(char username[], char password[])
{
    FILE *file;

    file = fopen("./accounts/customer_acc.txt", "a");

    if (file == NULL) {
        printf("ERROR: Cannot open customer accounts\n");
        return;
    }

    fprintf(file, "%s\n%s\n", username, password);
    fprintf(file, "%s\n"); // full_name
    fprintf(file, "\n"); // age
    fprintf(file, "\n"); // full_name
    fprintf(file, "\n"); // full_name
    fprintf(file, "\n"); // full_name
    fprintf(file, "\n"); // full_name
    fprintf(file, "\n"); // full_name
    fprintf(file, "\n"); // full_name

    fclose(file);
    retrieve_customer_acc();
    return;
}

void customer_login_page()
{
    char username[MAX_STR_LENGTH];
    char password[MAX_STR_LENGTH];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    if (authenticate_customer_login(username, password))
    {
        printf(GREEN);
        printf("ACCESS GRANTED\n");
        printf(RESET);
        set_current_customer(username);
        exit(0);
    }
    system("cls");
    printf(RED);
    printf("ACCESS DENIED\n");
    printf(RESET);
    return;
}

bool authenticate_customer_login(char username[], char password[])
{
    for (int i = 0; i < customer_count; i++)
    {
        if (strcmp(username, customers[i].username) == 0 && strcmp(password, customers[i].password) == 0)
        {
            return true;
        }
    }
    return false;
}

void employee_page()
{
    bool page_on = true;
    char choice;
    while (page_on)
    {
        printf("Employee Page: %s%s%s\n", CYAN, current_employee->username, RESET);
        printf("1 - User Registration and Login\n");
        printf("2 - Account Management\n");
        printf("3 - Transaction History\n");
        printf("4 - Transfer Money\n");
        printf("5 - Loan Management\n");
        printf("6 - Back to main menu\n");
        printf("7 - Exit application\n");
        printf("Enter your choice: ");
        fflush(stdin);
        scanf("%c", &choice);
        switch (choice)
        {
            case '1':
                create_customer_acc();
                break;
            case '2':
                account_management();
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                break;
            case '6':
                main();
                break;
            case '7':
                exit(0);
            default:
                system("cls");
                printf(RED);
                printf("Invalid Choice. Please try again\n");
                printf(RESET);
        }
    }
}

void create_customer_acc()
{
    if (customer_count >= MAX_CUSTOMERS)
    {
        printf("CUSTOMER ACCOUNTS MAXED!\n");
        main();
    }

    char username[MAX_STR_LENGTH];
    char password[MAX_STR_LENGTH];

    printf("Customer Create Account Page\n");
    printf("Username: ");
    scanf("%s", username);
    if (find_customer(username))
    {
        system("cls");
        printf(RED);
        printf("Username already exists\n");
        printf(RESET);
        return;
    }
    printf("Password: ");
    scanf("%s", password);
    add_customer_acc(username, password);
    system("cls");
    printf(GREEN);
    printf("Account Creation Successful\n");
    printf(RESET);

    retrieve_customer_acc();

    set_current_customer(username);
    return;
}

bool find_customer(char username[])
{
    for (int i = 0; i < customer_count; i++)
    {
        if (strcasecmp(username, customers[i].username) == 0)        
        {
            return true;
        }
    }
    return false;
}

void set_current_customer(char username[])
{
    for (int i = 0; i < customer_count; i++)
    {
        if (strcasecmp(username, customers[i].username) == 0)        
        {
            current_customer = &customers[i];
        }
    }
    return;
}

void set_current_employee(char username[])
{
    for (int i = 0; i < employee_count; i++)
    {
        if (strcasecmp(username, employees[i].username) == 0)        
        {
            current_employee = &employees[i];
        }
    }
    return;
}

void account_management()
{
    char username[MAX_STR_LENGTH];
    printf("Enter Customer Username: ");
    scanf("%s", username);
    if (!find_customer(username))
    {
        system("cls");
        printf(RED);
        printf("Username not found\n");
        printf(RESET);
        return;
    }
    set_current_customer(username);

    system("cls");
    printf("Managing Account: %s%s%s\n", CYAN, current_customer->username, RESET);
    printf("Full Name: ");
    fflush(stdin);
    scanf("%s", current_customer->full_name);
    printf("Age: ");
    fflush(stdin);
    scanf("%d", &current_customer->age);
    printf("Gender: ");
    fflush(stdin);
    scanf("%s", current_customer->gender);
    printf("Address: ");
    fflush(stdin);
    scanf("%s", current_customer->address);
    printf("Occupation: ");
    fflush(stdin);
    scanf("%s", current_customer->occupation);
    printf("Height (cm): ");
    fflush(stdin);
    scanf("%f", &current_customer->height);
    printf("Weight (kg): ");
    fflush(stdin);
    scanf("%f", &current_customer->weight);
    fflush(stdin);
    printf("Status: ");
    fflush(stdin);
    scanf("%s", current_customer->status);
    save_customers();
}

void save_customers()
{
    FILE *file;

    file = fopen("./accounts/customer_acc.txt", "w");

    if (file == NULL)
    {
        printf("ERROR: Could not create file");
        return;
    }

    for (int i = 0; i < customer_count; i++)
    {
        fprintf(file, "%s\n", customers[i].username);
        fprintf(file, "%s\n", customers[i].password);
        fprintf(file, "%s\n", customers[i].full_name);
        fprintf(file, "%d\n", customers[i].age);
        fprintf(file, "%s\n", customers[i].gender);
        fprintf(file, "%s\n", customers[i].address);
        fprintf(file, "%s\n", customers[i].occupation);
        fprintf(file, "%.2f\n", customers[i].height);
        fprintf(file, "%.2f\n", customers[i].weight);
        fprintf(file, "%s\n", customers[i].status);
    }
}
