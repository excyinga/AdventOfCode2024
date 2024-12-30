#pragma once

typedef struct Node Node;

struct Node
{
    Node *  prev;
    Node *  next;
    int value;
    long : 0;
};

Node * createNewNode(int value);
void * addToNode(Node * node, int value);