#include <stdlib.h>

#include "parser.h"
#include "dll.h"

Node * createNewNode(int value)
{
    void * ptr = malloc(sizeof(Node));
    ((Node *) ptr)->value = value;
    return ptr;
}