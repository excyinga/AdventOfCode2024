#include <stdio.h>
#include <stdlib.h>

#include "parser.h"

char * parser(void)
{
    FILE * fptr = fopen("./task3/test.txt", "rb");
    fseek(fptr, 0, SEEK_END);
    int array_size = ftell(fptr);
    char * array = malloc(sizeof(char) * (array_size += sizeof(int) - array_size % sizeof(int)));
    fseek(fptr, 0, SEEK_SET);
    int i = 0;
    for (int c; (c = fgetc(fptr)) != EOF;)
        array[i++] = c;
    array[i] = '\0';
    return array;
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
int numeralCount(char * array)
{
    int i = 0;
    for (; array[i] >= 48 && array[i] <= 57; i++);
    return i;
}