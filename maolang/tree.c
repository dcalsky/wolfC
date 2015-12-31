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

#include "tree.h"

/* Create a new binary tree and return it */
Tree createTree(){
    Tree tree = malloc(sizeof(struct Tree));
    tree->node = NULL;
    tree->lchild = NULL;
    tree->rchild = NULL;
    return tree;
}

/* Insert a variable with its name, type of data, and data into the tree. */
void insertVar(Tree rootTree, char *varName, DataType dataType, double data){
    Tree tmpTree, parentTree;
    Node newNode = malloc(sizeof(struct Node));
    tmpTree = parentTree = rootTree;
    Tree newTree = createTree();
    while(tmpTree != NULL){
        parentTree = tmpTree;
        if(parentTree->node == NULL){
            break;
        }
        tmpTree = strcmp(parentTree->node->varName, varName) >= 0 ? parentTree->lchild : parentTree->rchild;
    }
    if(tmpTree == NULL){
        if(strcmp(parentTree->node->varName, varName) >= 0){
            parentTree->lchild = newTree;
        }else{
            parentTree->rchild = newTree;
        }
        newTree->node = newNode;
    }else if(parentTree->node == NULL){
        parentTree->node = newNode;
    }
    if(dataType == INT){
        newNode->data.iData = (int)data;
        newNode->dataType = INT;
    }else{
        newNode->data.dData = data;
        newNode->dataType = DOUBLE;
    }
    strcpy(newNode->varName, varName);
}

/* Update the value of the node in the tree. */
Node updateNode(Node node, ...){
    va_list ap;
    va_start(ap, node);
    if(node->dataType == DOUBLE){
        node->data.dData = va_arg(ap, double);
    }else if(node->dataType == INT){
        node->data.iData = va_arg(ap, int);
    }
    va_end(ap);
    return node;
}

/* Find a node according to its name in the tree. */
Node findNode(Tree rootTree, char *varName){
    Tree tmpTree, parentTree;
    tmpTree = parentTree = rootTree;
    while(tmpTree != NULL && tmpTree->node != NULL){
        parentTree = tmpTree;
        if(strcmp(parentTree->node->varName, varName) == 0){
            return parentTree->node;
        }
        tmpTree = strcmp(parentTree->node->varName, varName) >= 0 ? parentTree->lchild : parentTree->rchild;
    }
    return NULL;
}

