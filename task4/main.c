#include <stdio.h>

#include "parser.h"

#define FALSE   0
#define TRUE    1

typedef unsigned char bool;

int solutionOne(char * array);
int solutionTwo(char * array);
int verifyExprs(char * array, int x, int y);

int main()
{
    char * array = parser();
    int var = solutionOne(array);
    /* printf("Sl1: %d\n", var); */
    printf("Sl2: %d\n", solutionTwo(array));
    return 0;
}

/* TODO: Rewrite the task */

int solutionOne(char * array)
{
    int ret = 0;
    for (int y = 0; y < array_height; y++)
    {
        for (int x = 0; x < array_width; x++)
        {
            if (array[y * array_width + x] == 'X')
            {
                ret += verifyExprs(array + y * array_width + x, x, y);
            }
        }
    }
    return ret;
}
int solutionTwo(char * array)
{
    int ret = 0;
    bool is_x = FALSE;
    for (int y = 0; y < array_height; y++)
    {
        for (int x = 0; x < array_width; x++)
        {
            if (array[y * array_width + x] == 'A')
            {
                is_x = FALSE;
                if (x > 0 && x < array_width - 1 && y > 0 && y < array_height - 1)
                {
                    is_x = TRUE;
                    char mxmy = array[(y - 1) * array_width + x - 1];
                    char pxmy = array[(y - 1) * array_width + x + 1];
                    char mxpy = array[(y + 1) * array_width + x - 1];
                    char pxpy = array[(y + 1) * array_width + x + 1];
                    if ((mxmy == 'M' || mxmy == 'S') && (pxmy == 'M' || pxmy == 'S') && (mxpy == 'M' || mxpy == 'S') && (pxpy == 'M' || pxpy == 'S'))
                    {
                        if (mxmy == 'M' && pxpy != 'S' || mxmy == 'S' && pxpy != 'M')
                            is_x = FALSE;
                        else if (pxmy == 'M' && mxpy != 'S' || pxmy == 'S' && mxpy != 'M')
                            is_x = FALSE;
                    }
                    else
                    {
                        is_x = FALSE;
                    }
                }
                if (is_x)
                    ret++;
            }
        }
    }
    return ret;
}
int verifyExprs(char * array, int x, int y)
{
    char template[] = {'X', 'M', 'A', 'S'};
    int true_l_r, true_r_l = true_l_r = 0;
    int t_mxmy = 0, t_pxmy = 0, t_mxpy = 0, t_pxpy = 0;
    int true_d_u = 0, true_u_d = 0;
    int var_amount = 0;
    bool x_p3 = FALSE, x_m3 = FALSE, y_p3 = FALSE, y_m3 = FALSE;
    for (int j = 0; j < 4; j++)
    {
        {if (x + 3 < array_width)
        {       
            x_p3 = TRUE;
            if (array[j] == template[j])
                true_l_r++;
        }
        if (x - 3 >= 0)
        {
            x_m3 = TRUE;
            if (array[-j] == template[j])            
                true_r_l++;
        }} /* hor */
        {if (y - 3 >= 0)
        {
            y_m3 = TRUE;
            if (array[-(j * array_width)] == template[j])
                true_u_d++;
        }
        if (y + 3 < array_height)
        {
            y_p3 = TRUE;
            if (array[j * array_width] == template[j])
                true_d_u++;
        }} /* vert */
        {
            if (x_m3 && y_m3)
            {
                if (array[-(j * array_width) - j] == template[j])
                    t_mxmy++;
            }
            if (x_p3 && y_m3)
            {
                if (array[-(j * array_width) + j] == template[j])
                    t_pxmy++;
            }   
            if (x_m3 && y_p3)
            {
                if (array[(j * array_width) - j] == template[j])
                    t_mxpy++;
            }
            if (x_p3 && y_p3)
            {
                if (array[(j * array_width) + j] == template[j])
                    t_pxpy++;
            }
        } /* dia */
        if (true_l_r == 4) var_amount++;
        if (true_r_l == 4) var_amount++;
        if (true_u_d == 4) var_amount++;
        if (true_d_u == 4) var_amount++;
        if (t_mxmy == 4) var_amount++;
        if (t_pxmy == 4) var_amount++;
        if (t_mxpy == 4) var_amount++;
        if (t_pxpy == 4) var_amount++;
    }
    return var_amount;
}