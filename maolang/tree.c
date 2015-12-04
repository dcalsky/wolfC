//
// Created by Dcalsky on 15/12/4.
//
#include "string.h"
#include "stdio.h"
#include "tree.h"


Tree createTree(){
    Tree tree = malloc(sizeof(struct _Btree));
    printf("created!");
    tree->node = NULL;
    tree->lchild = NULL;
    tree->rchild = NULL;
    return tree;
}

void insertVar(Tree rootTree, double dData, int iData, int dataType, char *varName){
    Tree tmpTree = rootTree;
    Node baseNode = rootTree->node;
    while(baseNode != NULL){
        tmpTree = strcmp(baseNode->varName, varName) >= 0 ? tmpTree->lchild : tmpTree->rchild;
        baseNode = tmpTree->node;
    }
    printf("%s", varName);
    fflush(stdout);
    strcpy(baseNode->varName, varName);
    /*
    if(dataType == 1){

        baseNode->dData = dData;
    }else{
        baseNode->iData = iData;
    }
     */


}

Node findNode(Tree rootTree, char *varName){
    Tree tmpTree = rootTree;
    Node baseNode = rootTree->node;
    while(strcmp(baseNode->varName, varName) != 0){
        tmpTree = strcmp(baseNode->varName, varName) >= 0 ? tmpTree->lchild : tmpTree->rchild;
        baseNode = tmpTree->node;
    }
    return baseNode;
}

