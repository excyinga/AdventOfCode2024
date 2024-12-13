#include <stdio.h>
 
#include "parser.h"

void parser(int array[1000][8], int array_size)
{
    char str[2];
    char str_arr_len = 0;
    int i, j = i = 0;
    FILE * fptr = fopen("task2/test.txt", "r");
    for (char c; 1;)
    {
        c = fgetc(fptr);
        switch(c)
        {
            case ' ':
            {
                array[i][j++] = intToString(str, str_arr_len);
                str_arr_len = 0;
                break;
            }
            case '\n':
            {
                array[i++][j] = intToString(str, str_arr_len);
                str_arr_len = 0;
                j = 0;
                break;
            }
            case EOF:
            {
                array[i][j] = intToString(str, str_arr_len);
                str_arr_len = 0;
                break;
            }
            default:
            {
                str[str_arr_len++] = c;
                break;
            }
        }
        if (c == EOF)
            break;
    }
    fclose(fptr);
    return;
}
int intToString(char str[], int array_size)
{
    int value = 0;
    for (int i = 0; i < array_size; i++)
        value += (str[i] - 48) * power(10, array_size - 1 - i);
    return value;
}
int power(int base, int n)
{
    if (n == 0)
        return 1;
    return base * power(base, n - 1);
}