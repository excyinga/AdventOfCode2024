#include <stdio.h>
#include <stdlib.h>

#include "dll.h"
#include "parser.h"

int solutionOne();
int solutionTwo();
bool findRuleInTheList(int left, int right);
void fixRuleInTheList(int left, int right, int position, int * array);

ListOfPages list;
Rules rule;
int new_page[PAGE_LENGTH];
/* Node head; */
int debug_i;

int main()
{   
    char * array = parser();
    /* printf("Sl1: %d\n", solutionOne()); */
    printf("Sl2: %d\n", solutionTwo());
    return 0;
}
 
/* TODO: Rewrite the task */

int solutionOne()
{
    bool is_good;
    int return_value = 0;
    for (int i = 0; i < PAGES_AMOUNT; i++)
    {
        rule.n_pages_bool[i] = TRUE;
        for (int j = 0;; j++)
        {
            if (!rule.n_pages_bool[i] || j == PAGE_LENGTH - 1 || rule.n_page[i][j + 1] == 0)
            {
                if (rule.n_pages_bool[i])
                    return_value += rule.n_page[i][j / 2];
                break;
            }
            rule.n_pages_bool[i] = findRuleInTheList(rule.n_page[i][j], rule.n_page[i][j + 1]);
        }
    }
    return return_value;
}
int solutionTwo()
{
    bool is_good;
    int return_value = 0;
    for (int i = 0; i < PAGES_AMOUNT; i++)
    {
        if (rule.n_pages_bool[i] == FALSE)
        {
            for (int j = 0;;)
            {
                if (j == PAGE_LENGTH - 1 || rule.n_page[i][j + 1] == 0)
                {
                    if (rule.n_pages_bool[i])
                        return_value += rule.n_page[i][j / 2];
                    break;
                }
                if (!findRuleInTheList(rule.n_page[i][j], rule.n_page[i][j + 1]))
                {
                    if (rule.n_pages_bool[i] = findRuleInTheList(rule.n_page[i][j + 1], rule.n_page[i][j]))
                    {
                        fixRuleInTheList(rule.n_page[i][j + 1], rule.n_page[i][j], j, rule.n_page[i] + j);
                        j = 0;
                    }
                    else
                        j++;
                }
                else
                    j++;
            }
            /* Rewrite this part */
        }
    }
    return return_value;
}
bool findRuleInTheList(int left, int right)
{
    int i = 0;
    for (; i < PAGE_NUMBER_LIST; i++)
    {
        if (list.left[i] == left && list.right[i] == right)
            return TRUE;
    }  
    return FALSE;
}
void fixRuleInTheList(int left, int right, int position, int * array)
{
    array[0] = left;
    array[1] = right;
    return;
}