#include <stdio.h>

#include "parser.h"

int parser(int arr1[], int arr2[], int arr_size)
{
    char buffer[16];
    FILE * fptr = fopen("task1/test.txt", "rb");
    if (fptr == NULL) 
    {
        printf("Error opening the file.\n");
        return 1;  
    }
    for (int i = 0; i < 1000; i++)
    {
        fgets(buffer, 14, fptr);
        if (!feof(fptr))
            fseek(fptr, 1, SEEK_CUR);
        arr1[i] = intToString(buffer, 5);
        arr2[i] = intToString(buffer + 8, 5);
    }
    fclose(fptr);
    return 1;
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
