#include <stdio.h>
#include "../include/colors.h"
#include "../include/capacity.h"


void print_red(char text[])
{
    printf(RED);
    printf("%s", text);
    printf(RESET);
}

void print_yellow(char text[])
{
    printf(YELLOW);
    printf("%s", text);
    printf(RESET);
}

void print_green(char text[])
{
    printf(GREEN);
    printf("%s", text);
    printf(RESET);
}

void print_cyan(char text[])
{
    printf(CYAN);
    printf("%s", text);
    printf(RESET);
}