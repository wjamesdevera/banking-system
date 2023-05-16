#include <stdio.h>
#include <string.h>

int main()
{
    char filepath[] = "./customer_accounts/";
    char file_txt[] = ".txt";
    char file_name[] = "win";
    strcat(file_name, file_txt);
    strcat(filepath, file_name);
}