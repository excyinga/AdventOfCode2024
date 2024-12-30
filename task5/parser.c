#include <stdio.h>
#include <stdlib.h>

#include "parser.h"

char * parser(void)
{
    FILE * fptr = fopen("./task5/test.txt", "rb");
    fseek(fptr, 0, SEEK_SET);
    char array[2];
    int i = 0;
    list.left = malloc(sizeof(int) * PAGE_NUMBER_LIST);
    list.right = malloc(sizeof(int) * PAGE_NUMBER_LIST);
    for (int k = 0; k < PAGES_AMOUNT; k++)
    {
        rule.n_page[k] = malloc(sizeof(int) * PAGE_LENGTH);
        for (int j = 0; j < PAGE_LENGTH; j++)
            rule.n_page[k][j] = 0;
    }
    char prev_c = 0;
    int current_n = 0;
    i = 0;
    while (TRUE)
    {
        char c = fgetc(fptr);
        if (c == '\n' && prev_c == '\n')
        {
            current_n = 0;
            break;
        }
        else if (c >= '0' && c <= '9')
        {
            current_n = current_n * 10 + c - '0';
        }   
        else
        {
            if (c == '|')
                list.left[i] = current_n;
            else
            {
                list.right[i] = current_n;
                i++;
            }
            current_n = 0;
        }
        prev_c = c;
    }
    i = 0;
    int j = 0;
    while (TRUE)
    {
        char c = fgetc(fptr);
        if (c >= '0' && c <= '9')
        {
            current_n = current_n * 10 + c - '0';
        }
        else
        {
            rule.n_page[i][j] = current_n;
            if (c == ',')
            {
                j++;
            }
            else
            {
                i++;
                j = 0;
            }
            current_n = 0;
        }
        if (c == EOF)
        {
            break;
        }
    }
    return NULL;
}
int intToString(char str[], int array_size)
{
    int value = 0;
    for (int i = 0; i < array_size; i++)
        value = value * 10 + str[i] - '0';
    return value;
}
int power(int base, int n)
{
    if (n == 0)
        return 1;
    return base * power(base, n - 1);
}
