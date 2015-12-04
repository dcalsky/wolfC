//
// Created by Dcalsky on 15/12/4.
//
#include "stdlib.h"
#ifndef MAOLANG_TREE_H
#define MAOLANG_TREE_H

/* Define a binary tree to store, sort, get, delete the data */
/* find detail data based on node */

typedef struct _Btree {
    struct _Node *node;
    struct _Btree *lchild;
    struct _Btree *rchild;
} *Tree;


/* node in tree, function to store the data */

typedef struct _Node {
    double dData ;
    int iData;
    int dataType;
    char varName[1001];
} *Node;

/* create a new tree to give service to us */

Tree createTree();

void insertVar(Tree tree, double dData, int iData, int dataType, char *varName);

Node findNode(Tree tree, char *varName);



#endif //MAOLANG_TREE_H
