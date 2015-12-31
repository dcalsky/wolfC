/*
 * Binary tree
 * Because of reasons of time and ability, some functions are not achieved.
 * Including two important structures: Tree and Node. Node is a segment of Tree, which is used to store the data.
 *
 * How to judge the type of variable? It's a vital problem confuse me that I try to achieve generics, but I failed. So I \
 * add a extra type to record the type of a variable. That's "dataType" which is the structure including four type (You can \
 * see detailed content in utils.h). Ok, I know it's a bad idea to solve this problem.
 *
 * Created by Dcalsky on 15/12/4.
 * */

#ifndef MAOLANG_TREE_H
#define MAOLANG_TREE_H
#include "stdlib.h"
#include "stack.h"
#include "stdarg.h"

/* Define a binary tree to store, sort, get, delete the data */
/* find detail data based on node */

typedef struct Tree {
    struct Node *node;  //An point structure including some detailed data
    struct Tree *lchild; // left children tree
    struct Tree *rchild; // right children tree
} *Tree;


/* It's a structure to store data of double and int types. */
typedef struct Node {
    char varName[24];
    union {             // Anonymous union
        int iData;
        double dData;
    } data;
    DataType dataType;  // type of data (Declared in utils.h)
} *Node;

/* Create a new binary tree and return it */
Tree createTree();

/* Insert a variable with its name, type of data, and data into the tree. */
void insertVar(Tree,  char *, DataType, double);

/* Find a node according to its name in the tree. */
Node findNode(Tree, char *);

/* Update the value of the node in the tree. */
Node updateNode(Node , ...);

#endif //MAOLANG_TREE_H
