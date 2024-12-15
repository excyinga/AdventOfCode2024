#include <stdio.h>

#include "parser.h"

typedef enum Bool               Bool;
typedef enum CreaseDirection    CreaseDirection;
typedef struct Reports          Reports; 
typedef unsigned char           uint_8;

enum Bool {FALSE, TRUE};
enum CreaseDirection {ERROR, INCREASING, DECREASING};

#define UNSAFE  FALSE
#define SAFE    TRUE

struct Reports
{
    uint_8 crease : 2, safe : 1;
} reports;

void displayArray(int array[][8], int row, int column);
int solutionOne(int row, int column);
int solutionTwo(int row, int column);
Bool reportVerify(int array[][8], int i, int column);
void copyArray(int arr1[], int arr2[], int arr_length);

static int array1[1000][8];
static int sl2_array[8];
static int sl2_error_index;
static Bool sl2_bool = TRUE;

int main()
{
    parser(array1, 1000);
    printf("Sl1: Safe reports: %d\n", solutionOne(1000, 8));
    printf("Sl2: Safe reports: %d\n", solutionTwo(1000, 8));
    return 0;
}
int solutionOne(int row, int column) 
{
    extern int array1[1000][8];
    int safe_reports = 0; 
    for (int i = 0; i < row; i++)
    {   
        if (reportVerify(array1, i, column))
        {
            safe_reports++;
        }
    }
    return safe_reports;
}
int solutionTwo(int row, int column)
{
    extern int array1[][8];
    sl2_error_index = 0;
    int safe_reports = 0; 
    int edge = 2;
    for (int i = 0; i < row; i++)
    {   
        Bool safe_report;
        sl2_bool = TRUE;
        if (!reportVerify(array1, i, column))
        {
            if (sl2_error_index != 0)
            {
                edge++;
                sl2_error_index--;
            }
            for (int k = 0; k < edge; k++)
            {
                for (int j = 0; j < column; j++)
                    sl2_array[j] = 0;
                copyArray((int *) ((int (*)[8]) array1 + i), sl2_array, 8);
                if (reportVerify((int (*)[8]) sl2_array, 0, column))
                {
                    safe_report = TRUE;
                    safe_reports++;
                    break;
                }
                else
                {
                    sl2_error_index++;
                }
            }
        }
        else
        {
            safe_report = TRUE;
            safe_reports++;
        }
    }
    return safe_reports;
}
Bool reportVerify(int array[1000][8], int i, int column)
{
    int j = 0;
    reports.crease = array[i][j] == array[i][j + 1] ? ERROR : (array[i][j] < array[i][j + 1] ? INCREASING : DECREASING);
    reports.safe = TRUE;
    for (; j < column - 1; j++)
    {
        if (array[i][j + 1] == 0 || reports.crease == ERROR)
        { 
            if (reports.crease == ERROR)
            {
                reports.safe = FALSE;
            }
            break;
        }
        if (array[i][j] >= array[i][j + 1] && reports.crease == INCREASING || array[i][j] <= array[i][j + 1] && reports.crease == DECREASING)
        {    
            reports.safe = FALSE;
            break;
        }
        if (reports.crease == DECREASING)
        {
            if (array[i][j + 1] < array[i][j] - 3)
            {
                reports.safe = FALSE;
                break;
            }
        }
        else
        {
            if (array[i][j + 1] > array[i][j] + 3)
            {    
                reports.safe = FALSE;
                break;
            }
        }
    }
    if (reports.safe == FALSE && sl2_bool)
    {
        sl2_error_index = j;
        sl2_bool = !sl2_bool;
    }
    return reports.safe;
}

void copyArray(int arr_from[], int arr_to[], int arr_length)
{
    extern int sl2_error_index;
    for (int from_i = 0, to_i = 0; from_i != arr_length; from_i++)
    {
        if (arr_from[from_i] == 0)
            break;
        if (from_i == sl2_error_index)
            continue;
        arr_to[to_i++] = arr_from[from_i];
    }
    return;
}
void displayArray(int array[][8], int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; array[i][j] != 0 && j < column; j++)
        {
            printf("%d", array[i][j]);
            if (j != column - 1 && array[i][j + 1] != 0)
                putchar(' ');
        }
        putchar('\n');
    }
    return;
}

