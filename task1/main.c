#include <stdio.h>
#include <stdlib.h>

#include "parser.h"

#define ARRAY_SIZE  1024
#define COUNTOF(x)  ((sizeof(x)) / sizeof(x[0]))

typedef enum bool bool;

enum bool {FALSE, TRUE};

#define F_SIGNATURE int array1[], int array2[], int size

int abs(int a);
void displayArray(int array1[], int array2[], int size);
void sortArray(int array[], int size);
int solutionOne(int array1[], int array2[], int size);
unsigned long int solutionTwo(F_SIGNATURE);

int main()
{
    int * array1 = malloc(sizeof(int) * ARRAY_SIZE);
    int * array2 = malloc(sizeof(int) * ARRAY_SIZE);
    int array_size = 1000;
    parser(array1, array2, array_size);
    printf("Sl1: Total distance:    %d\n", solutionOne(array1, array2, array_size));
    printf("Sl2: Total score:       %lu\n", solutionTwo(array1, array2, array_size));
    return 0;
}

int solutionOne(int array1[], int array2[], int size)
{
    int total_distance = 0;
    sortArray(array1, size);
    sortArray(array2, size);
    for (int i = 0; i < size; i++)
        total_distance += abs(array1[i] - array2[i]);
    return total_distance;
}
unsigned long int solutionTwo(F_SIGNATURE)
{
    unsigned long int total_score = 0;
    sortArray(array1, size);
    sortArray(array2, size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            if (array1[i] == array2[j])
                total_score += array1[i];
    } 
    return total_score;
}
void sortArray(int array[], int size)
{
    bool not_sorted = FALSE;
    int tmp;
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1 && not_sorted)
        {
            i = -1;
            not_sorted = FALSE;
        }
        else if (i != size - 1)
        {
            if (array[i] > array[i + 1])
            {
                tmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tmp;
                not_sorted = TRUE;
            }
        }
    }
    return;
}
void displayArray(int array1[], int array2[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d   %d\n", array1[i], array2[i]);
    return;
}
int abs(int a)
{
    return a < 0 ? a * -1 : a; 
}