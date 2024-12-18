#include <stdio.h>
#include <stdlib.h>

#include "parser.h"

#define FALSE   0
#define TRUE    1
/* #define DONT    FALSE
#define DO      TRUE */

/* typedef union Mul       Mul; */
typedef unsigned char   bool;
/* 
union Mul
{
    bool mul_instr;
    struct 
    {
        bool    m   : 1,
                u   : 1,
                l   : 1,
                lrb : 1,
                lop : 1,
                cm  : 1,
                rop : 1,
                rrb : 1;
    };
} mul;
 */
int solutionOne(void);
int solutionTwo(void);

static char * array;
static bool do_ = TRUE;

int main()
{
    array = parser(); 
    printf("Sl1: %d\n", solutionOne());
    printf("Sl2: %d\n", solutionTwo());
    free(array);
    return 0;
}

/* TODO: Rewrite the task */

int solutionOne(void)
{
    /* extern Mul mul; */
    extern char * array;
    int ret = 0, numeral_count1, numeral_count2;
    #define SHIFT   4
    #define SHIFT_C 1 
    for (int i = 0; array[i] != '\0'; i++)
    {   
        if (array[i] == 'm' && array[i + 1] == 'u' && array[i + 2] == 'l' && array[i + 3] == '(')
        {
            numeral_count1 = numeralCount(array + i + SHIFT);
            if (numeral_count1 && numeral_count1 < 4 && array[i + SHIFT + numeral_count1] == ',')
            {
                numeral_count2 = numeralCount(array + i + SHIFT + numeral_count1 + SHIFT_C);
                if (numeral_count2 && numeral_count2 < 4 && array[i + SHIFT + numeral_count1 + SHIFT_C + numeral_count2] == ')')
                {
                    int val1 = intToString(array + i + SHIFT, numeral_count1);
                    int val2 = intToString(array + i + SHIFT + numeral_count1 + SHIFT_C, numeral_count2);
                    ret += val1 * val2;
                }   
            }
        }
    }
    #undef SHIFT
    #undef SHIFT_C
    return ret;
}
int solutionTwo(void)
{
    extern char * array;
    int ret = 0, numeral_count1, numeral_count2;
    #define SHIFT   4
    #define SHIFT_C 1 
    for (int i = 0; array[i] != '\0'; i++)
    {   
        if (array[i] == 'd' && array[i + 1] == 'o' && array[i + 2] == '(' && array[i + 3] == ')')
            do_ = TRUE;
        else if (array[i] == 'd' && array[i + 1] == 'o' && array[i + 2] == 'n' && array[i + 3] == '\'' && array[i + 4] == 't' && array[i + 5] == '(' && array[i + 6] == ')')
            do_ = FALSE;
        if (array[i] == 'm' && array[i + 1] == 'u' && array[i + 2] == 'l' && array[i + 3] == '(')
        {
            if (do_)
            {
                numeral_count1 = numeralCount(array + i + SHIFT);
                if (numeral_count1 && numeral_count1 < 4 && array[i + SHIFT + numeral_count1] == ',')
                {
                    numeral_count2 = numeralCount(array + i + SHIFT + numeral_count1 + SHIFT_C);
                    if (numeral_count2 && numeral_count2 < 4 && array[i + SHIFT + numeral_count1 + SHIFT_C + numeral_count2] == ')')
                    {
                        int val1 = intToString(array + i + SHIFT, numeral_count1);
                        int val2 = intToString(array + i + SHIFT + numeral_count1 + SHIFT_C, numeral_count2);
                        ret += val1 * val2;
                    }   
                }
            }
        }
    }
    #undef SHIFT
    #undef SHIFT_C
    return ret;
}
