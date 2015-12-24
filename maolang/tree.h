//
// Created by Dcalsky on 15/12/4.
//

#ifndef MAOLANG_TREE_H
#define MAOLANG_TREE_H
#include "stdlib.h"
#include "stack.h"
#include "stdarg.h"

/* Define a binary tree to store, sort, get, delete the data */
/* find detail data based on node */

typedef struct _Btree {
    struct _Node *node;
    struct _Btree *lchild;
    struct _Btree *rchild;
} *Tree;


/* node in tree, function to store the data */

typedef struct _Node {
    char varName[24];
    union {
        int iData;
        double dData;
    } data;
    DataType dataType;
} *Node;

/* create a new tree to give service to us */

Tree createTree();

void insertVar(Tree,  char *, DataType, double);

Node findNode(Tree, char *);

Node updateNode(Node , ...);

#endif //MAOLANG_TREE_H
