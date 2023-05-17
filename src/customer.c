#include "../include/customer.h"
#include "../include/colors.h"

int customer_count = 0;
customer customers[MAX_CUSTOMERS];

void create_customer(char username[], char password[])
{
    if (find_customer(username))
    {
        printf("Username Already Exists\n");
        return;
    }

    if (customer_count >= MAX_CUSTOMERS)
    {
        printf("ERROR: Maxed Customer Reached\n");
        return;
    }
    strcpy(customers[customer_count].username, username);
    strcpy(customers[customer_count].password, password);
    create_transaction_records(username);
    customer_count++;
}

bool find_customer(char username[])
{
    for (int i = 0; i < customer_count; i++)
    {
        if (strcasecmp(customers[i].username, username) == 0)
        {
            return true;
        }
    }
    return false;
}

void store_customer_data()
{
    FILE *file;

    file = fopen(CUSTOMER_DATA_PATH, "w");

    if (file == NULL)
    {
        printf("ERROR: Storing customer data");
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
        fprintf(file, "%s\n", customers[i].nationality);
        fprintf(file, "%.2f\n", customers[i].height);
        fprintf(file, "%.2f\n", customers[i].weight);
        fprintf(file, "%s\n", customers[i].status);
    }

    fclose(file);
}

void load_customer_data()
{
    FILE *file;

    file = fopen(CUSTOMER_DATA_PATH, "r");

    if (file == NULL)
    {
        printf("ERROR: Loading customer data\n");
        return;
    }

    char buffer[BUFFER_SIZE];
    int line = 0;
    while(fgets(buffer, BUFFER_SIZE, file) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (line % 11 == 0)
        {
            strcpy(customers[customer_count].username, buffer);
        }
        if (line % 11 == 1)
        {
            strcpy(customers[customer_count].password, buffer);
        }
        if (line % 11 == 2)
        {
            strcpy(customers[customer_count].full_name, buffer);
        }
        if (line % 11 == 3)
        {
            customers[customer_count].age = atoi(buffer);
        }
        if (line % 11 == 4)
        {
            strcpy(customers[customer_count].gender, buffer);
        }
        if (line % 11 == 5)
        {
            strcpy(customers[customer_count].address, buffer);
        }
        if (line % 11 == 6)
        {
            strcpy(customers[customer_count].occupation, buffer);
        }
        if (line % 11 == 7)
        {
            strcpy(customers[customer_count].nationality, buffer);
        }
        if (line % 11 == 8)
        {
            customers[customer_count].height = atof(buffer);
        }
        if (line % 11 == 9)
        {
            customers[customer_count].weight = atof(buffer);
        }
        if (line % 11 == 10)
        {
            strcpy(customers[customer_count].status, buffer);
            customer_count++;
        }
        line++;
    }
    fclose(file);
}

void set_customer_full_name(char username[], char full_name[])
{
    for (int i = 0; i < customer_count; i++)
    {
        if (strcasecmp(customers[i].username, username) == 0)
        {
            strcpy(customers[i].full_name, full_name);
        }
    }
}

void set_customer_age(char username[], int age)
{
    for (int i = 0; i < customer_count; i++)
    {
        if (strcasecmp(customers[i].username, username) == 0)
        {
            customers[i].age = age;
        }
    }
}

void set_customer_gender(char username[], char gender[])
{
    for (int i = 0; i < customer_count; i++)
    {
        if (strcasecmp(customers[i].username, username) == 0)
        {
            strcpy(customers[i].gender, gender);
        }
    }
}

void set_customer_address(char username[], char address[])
{
    for (int i = 0; i < customer_count; i++)
    {
        if (strcasecmp(customers[i].username, username) == 0)
        {
            strcpy(customers[i].address, address);
        }
    }
}

void set_customer_occupation(char username[], char occupation[])
{
    for (int i = 0; i < customer_count; i++)
    {
        if (strcasecmp(customers[i].username, username) == 0)
        {
            strcpy(customers[i].occupation, occupation);
        }
    }
}

void set_customer_nationality(char username[], char nationality[])
{
    for (int i = 0; i < customer_count; i++)
    {
        if (strcasecmp(customers[i].username, username) == 0)
        {
            strcpy(customers[i].nationality, nationality);
        }
    }
}

void set_customer_height(char username[], float height)
{
    for (int i = 0; i < customer_count; i++)
    {
        if (strcasecmp(customers[i].username, username) == 0)
        {
            customers[i].height = height;
        }
    }
}

void set_customer_weight(char username[], float weight)
{
    for (int i = 0; i < customer_count; i++)
    {
        if (strcasecmp(customers[i].username, username) == 0)
        {
            customers[i].weight = weight;
        }
    }
}

void set_customer_status(char username[], char status[])
{
    for (int i = 0; i < customer_count; i++)
    {
        if (strcasecmp(customers[i].username, username) == 0)
        {
            strcpy(customers[i].status, status);
        }
    }
}

void print_customer_details(char username[])
{
    for (int i = 0; i < customer_count; i++)
    {
        if (strcasecmp(customers[i].username, username) == 0)
        {
            printf("Full Name: %s\n", customers[i].full_name);
            printf("Age: %d\n", customers[i].age);
            printf("Gender: %s\n", customers[i].gender);
            printf("Address: %s\n", customers[i].address);
            printf("Occupation: %s\n", customers[i].occupation);
            printf("Nationality: %s\n", customers[i].nationality);
            printf("Height: %.2f cm\n", customers[i].height);
            printf("Weight: %.2f kg\n", customers[i].weight);
            printf("Status: %s\n", customers[i].status);
        }
    }
}

void create_transaction_records(char username[])
{
    FILE *file;

    char file_path[STR_MAX_LENGTH] = "./customer_accounts/";
    char file_name[STR_MAX_LENGTH];
    char file_ext[STR_MAX_LENGTH] = ".txt";

    strcpy(file_name, username);
    strcat(file_name, file_ext);
    strcat(file_path, file_name);

    file = fopen(file_path, "w");

    if (file == NULL)
    {
        printf("Creating File Trasaction Failed");
        return;
    }

    fprintf(file, "USERNAME=%s\t", username);

    for (int i = 0; i < customer_count; i++)
    {
        if (strcasecmp(customers[i].username, username) == 0)
        {
            fprintf(file, "FULL_NAME=%s\n\n", customers[i].full_name);
        }
    }
    fclose(file);
}

void write_trasanction_logs(char type[], char username[], float amount)
{
    FILE *file;

    char file_path[STR_MAX_LENGTH] = "./customer_accounts/";
    char file_name[STR_MAX_LENGTH];
    char file_ext[STR_MAX_LENGTH] = ".txt";

    strcpy(file_name, username);
    strcat(file_name, file_ext);
    strcat(file_path, file_name);

    file = fopen(file_path, "a");

    if (file == NULL)
    {
        printf("Creating File Trasaction Failed");
        return;
    }

    for (int i = 0; i < customer_count; i++)
    {
        if (strcasecmp(customers[i].username, username) == 0)
        {
            fprintf(file, "FULL_NAME=%s\n", customers[i].full_name);
        }
    }
    fprintf(file, "TYPE : %s\n", type);
    fprintf(file, "AMOUNT : %.2f\n", amount);

    fclose(file);
}

void generate_transaction_reciept(char username[])
{
    FILE *file;
    FILE *reciept;

    char file_path[STR_MAX_LENGTH] = "./customer_accounts/";
    char file_name[STR_MAX_LENGTH];
    char file_ext[STR_MAX_LENGTH] = ".txt";
    char reciept_path[STR_MAX_LENGTH] = "./";

    strcpy(file_name, username);
    strcat(file_name, file_ext);
    strcat(file_path, file_name);

    strcat(reciept_path, "reciept-");
    strcat(reciept_path, file_name);

    file = fopen(file_path, "r");

    if (file == NULL)
    {
        printf("Creating File Trasaction Failed");
        return;
    }

    reciept = fopen(reciept_path, "w");

    if (reciept == NULL)
    {
        printf("Creating File Trasaction Failed");
        return;
    }

    fprintf(reciept, "======= TRANSACTION RECIEPT =======\n");
    int line = 0;
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (line > 1)
        {
            fprintf(reciept, "%s\n", buffer);
        }
        if (line % 4 == 0)
        {
            fprintf(reciept, "\n");
        }
        line++;
    }

    fprintf(reciept, "\n===================================\n");

    fclose(file);
    fclose(reciept);
}

void view_transaction_history(char username[])
{
    FILE *file;

    char file_path[STR_MAX_LENGTH] = "./customer_accounts/";
    char file_name[STR_MAX_LENGTH];
    char file_ext[STR_MAX_LENGTH] = ".txt";

    strcpy(file_name, username);
    strcat(file_name, file_ext);
    strcat(file_path, file_name);

    file = fopen(file_path, "r");

    if (file == NULL)
    {
        printf("Creating File Trasaction Failed");
        return;
    }
    int line = 0;
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (line > 1)
        {
            printf("%s\n", buffer);
        }
        if (line % 4 == 0)
        {
            printf("\n");
        }
        line++;
    }

    fclose(file);
}


bool authenticate_customer(char username[], char password[])
{
    for (int i = 0; i < customer_count; i++)
    {
        if (strcasecmp(customers[i].username, username) == 0 && strcmp(customers[i].password, password) == 0)
        {
            return true;
        }
    }
    return false;
}