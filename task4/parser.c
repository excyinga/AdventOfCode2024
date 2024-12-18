#include <stdio.h>
#include <stdlib.h>

#include "parser.h"

int array_width = 0;
int array_height;

char * parser(void)
{
    FILE * fptr = fopen("./task4/test.txt", "rb");
    fseek(fptr, 0, SEEK_END);
    int array_size = ftell(fptr);
    char * array = malloc(sizeof(char) * array_size + sizeof(int) - array_size % sizeof(int));
    fseek(fptr, 0, SEEK_SET);
    int i = 0;
    for (int c; (c = fgetc(fptr)) != EOF;)
    {
        if (c == '\n')
        {
            if (!array_width)
                array_width = i;
        }
        else
            array[i++] = c;
    }
    array_height = i / array_width;
    array[i] = '\0';
    return array;
}