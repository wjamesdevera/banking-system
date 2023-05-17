#include "../include/customer.h"
#include "../include/employee.h"
#include "../include/colors.h"
#include "../include/employee_login.h"
#include "pages.h"

void main_menu()
{
    bool page_on = true;
    char choice;

    print_cyan("== Banking System ==\n");
    printf("1 - Employee\n");
    printf("2 - Customer\n");
    printf("3 - Exit\n");
    printf("Enter your choice: ");
    while (page_on)
    {
        fflush(stdin);
        scanf("%c", &choice);
        switch (choice)
        {
            case '1':
                employee_login_page();
                print_main_menu();
                break;
            case '2':
                customer_login_page();
                print_main_menu();
                break;
            case '3':
                page_on = false;
                break;
            default:
                print_red("Invalid Input\n");
                printf("Enter your choice: ");
        }
    }
    return;
}

void print_main_menu()
{
    print_cyan("== Banking System ==\n");
    printf("1 - Employee\n");
    printf("2 - Customer\n");
    printf("3 - Exit\n");
    printf("Enter your choice: ");
}

void employee_login_page()
{
    bool page_on = true;
    system("cls");
    char choice;
    print_employee_login_menu();
    while (page_on)
    {
        fflush(stdin);
        scanf("%c", &choice);
        switch (choice)
        {
            case '1':
                employee_login();
                print_employee_login_menu();
                break;
            case '2':
                employee_create_account_page();
                print_employee_login_menu();
                break;
            case '3':
                page_on = false;
                break;
            default:
                print_red("Invalid Input\n");
                printf("Enter your choice: ");
        }
    }
    system("cls");
}

void print_employee_login_menu()
{
    print_cyan("== Employee Login Page ==\n");
    printf("1 - Login\n");
    printf("2 - Create New Account\n");
    printf("3 - Back\n");
    printf("Enter your choice: ");
}

void employee_login()
{
    char choice;
    char username[STR_MAX_LENGTH];
    char password[STR_MAX_LENGTH];
    system("cls");
    print_cyan("== Employee Login == \n");
    printf("Username: ");
    fflush(stdin);
    scanf("%s", username);
    printf("Password: ");
    fflush(stdin);
    scanf("%s", password);
    if (!authenticate_employee(username, password))
    {
        system("cls");
        print_red("ACCESS DENIED\n");
        return;
    }
    system("cls");
    print_green("ACCESS GRANTED\n");
    employee_dashboard();
    return;
}

void employee_create_account_page()
{
    char username[STR_MAX_LENGTH];
    char password[STR_MAX_LENGTH];
    system("cls");
    print_cyan("== Employee Create Account ==\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    if (find_employee(username))
    {
        system("cls");
        print_yellow("Username Already Exist\n");
        return;
    }

    create_employee(username, password);
    print_green("Account Creation Successful\n");
    employee_dashboard();
}

void employee_dashboard()
{
    bool page_on = true;
    char choice;
    print_employee_dashboard_menu();
    while (page_on)
    {
        fflush(stdin);
        scanf("%c", &choice);
        switch (choice)
        {
            case '1':
                create_customer_page();
                print_employee_dashboard_menu();
                break;

            case '2':
                account_management_page();
                print_employee_dashboard_menu();
                break;
            case '3':
                transaction_history();
                print_employee_dashboard_menu();
                break;
            case '4':
                transfer_money_page();
                print_employee_dashboard_menu();
                break;
            case '5':
                loan_management();
                print_employee_dashboard_menu();
                break;
            case '6':
                page_on = false;
                break;
            case '7':
                store_customer_data();
                store_employee_data();
                exit(0);
            default:
                system("cls");
                print_red("Invalid Input\n");
                print_employee_dashboard_menu();
        }    
    }
    system("cls");
}

void print_employee_dashboard_menu()
{
    print_cyan("== Employee Dashboard ==\n");
    printf("1 - User Registration and Login\n");
    printf("2 - Account Management\n");
    printf("3 - Transaction History\n");
    printf("4 - Transfer Money\n");
    printf("5 - Loan Mangement\n");
    printf("6 - Back\n");
    printf("7 - Exit Application\n");
    printf("Enter Choice: ");
}

void account_management_page()
{
    char choice;
    char username[STR_MAX_LENGTH];
    system("cls");
    print_cyan("== Account Management ==\n");

    printf("Customer Username: ");
    scanf("%s", username);
    if (!find_customer(username))
    {
        print_yellow("Username not found\n");
        return;
    }
    print_customer_details(username);
    printf("1 - Add\n");
    printf("2 - Back\n");
    printf("Enter your choice: ");
    fflush(stdin);
    scanf("%c", &choice);
    switch (choice)
    {
        case '1':
            break;
        case '2':
            system("cls");
            return;
        default:
            print_red("Invalid Input\n");
            return;
    }

    char full_name[STR_MAX_LENGTH];
    int age;
    char gender[STR_MAX_LENGTH];
    char address[STR_MAX_LENGTH];
    char occupation[STR_MAX_LENGTH];
    char nationality[STR_MAX_LENGTH];
    float height;
    float weight;
    char status[STR_MAX_LENGTH];

    printf("Full Name: ");
    fflush(stdin);
    scanf("%s", full_name);
    printf("Age : ");
    fflush(stdin);
    scanf("%d", &age);
    printf("Gender : ");
    fflush(stdin);
    scanf("%s", gender);
    printf("Address : ");
    fflush(stdin);
    scanf("%s", address);
    printf("Occupation : ");
    fflush(stdin);
    scanf("%s", occupation);
    printf("Nationality : ");
    fflush(stdin);
    scanf("%s", nationality);
    printf("Height (cm): ");
    fflush(stdin);
    scanf("%f", &height);
    printf("Weight (kg): ");
    fflush(stdin);
    scanf("%f", &weight);
    printf("Status : ");
    fflush(stdin);
    scanf("%s", status);

    set_customer_full_name(username, full_name);
    set_customer_age(username, age);
    set_customer_gender(username, gender);
    set_customer_address(username, address);
    set_customer_occupation(username, occupation);
    set_customer_nationality(username, nationality);
    set_customer_height(username, height);
    set_customer_weight(username, weight);
    set_customer_status(username, status);
    return;
}

void transaction_history()
{
    system("cls");
    char username[STR_MAX_LENGTH];
    print_cyan("== Transaction History == \n");
    printf("Cusomer username: ");
    scanf("%s", username);

    if (!find_customer(username))
    {
        system("cls");
        print_yellow("Username not found\n");
        return;
    }

    view_transaction_history(username);
    generate_transaction_reciept(username);
    print_green("Transaction Reciept Generated\n");
    printf("Continue...\n");
    getch();
    system("cls");
}

void transfer_money_page()
{
    system("cls");
    print_cyan("== Transfer Money Page == \n");
    print_red("PAGE WORK IN PROGRESS\n");
    getch();
    system("cls");
}

void loan_management()
{
    system("cls");
    print_cyan("== Transfer Money Page == \n");
    print_red("PAGE WORK IN PROGRESS\n");
    getch();
    system("cls");
}

/**
 * Customer Pages
*/

void customer_login_page()
{
    bool page_on = true;
    system("cls");
    char choice;
    print_customer_login_menu();
    while (page_on)
    {
        fflush(stdin);
        scanf("%c", &choice);
        switch (choice)
        {
            case '1':
                customer_login();
                print_customer_login_menu();
                break;
            case '2':
                create_customer_page();
                print_customer_login_menu();
                break;
            case '3':
                page_on = false;
                break;
            default:
                print_red("Invalid Input\n");
                printf("Enter your choice: ");
        }
    }
    system("cls");
}

void print_customer_login_menu()
{
    print_cyan("== Customer Login Page ==\n");
    printf("1 - Login\n");
    printf("2 - Create New Account\n");
    printf("3 - Back\n");
    printf("Enter your choice: ");
}

void create_customer_page()
{
    char username[STR_MAX_LENGTH];
    char password[STR_MAX_LENGTH];
    system("cls");
    print_cyan("== Customer Create Account ==\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    if (find_customer(username))
    {
        system("cls");
        print_yellow("Username Already Exist\n");
        return;
    }

    create_customer(username, password);
    print_green("Account Creation Successful\n");
    return;
}

void customer_login()
{
    char choice;
    char username[STR_MAX_LENGTH];
    char password[STR_MAX_LENGTH];
    system("cls");
    print_cyan("== Customer Login == \n");
    printf("Username: ");
    fflush(stdin);
    scanf("%s", username);
    printf("Password: ");
    fflush(stdin);
    scanf("%s", password);
    if (!authenticate_customer(username, password))
    {
        system("cls");
        print_red("ACCESS DENIED\n");
        return;
    }
    system("cls");
    print_green("ACCESS GRANTED\n");
    getch();
    return;
}
/**
 * Setters
*/
