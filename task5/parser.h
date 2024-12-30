#ifndef __PARSER_H__
#define __PARSER_H__

#define FALSE               0
#define TRUE                1
#define PAGE_NUMBER_LIST    1176
#define PAGES_AMOUNT        194
#define PAGE_LENGTH         23

typedef unsigned char   bool;
typedef int             *pages[PAGES_AMOUNT];

typedef struct ListOfPages ListOfPages;
typedef struct Rules Rules;

struct ListOfPages
{
    int * left;
    int * right;
};
struct Rules
{
    pages n_page;
    bool n_pages_bool[PAGES_AMOUNT];
};

extern char * parser(void);
extern int intToString(char str[], int array_size);
extern int power(int base, int n);

extern ListOfPages  list;
extern Rules        rule;

#endif