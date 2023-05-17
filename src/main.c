#include "../include/customer.h"
#include "../include/employee.h"
#include "../include/colors.h"
#include "../include/employee_login.h"
#include "../include/pages.h"

int main()
{
    load_employee_data();
    load_customer_data();

    main_menu();

    store_employee_data();
    store_customer_data();
    return 0;
}