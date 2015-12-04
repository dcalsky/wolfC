//
// Created by Dcalsky on 15/12/4.
//
#include "string.h"
#include "stdio.h"
#include "tree.h"


Tree createTree(){
    Tree tree = malloc(sizeof(struct _Btree));
//    tree->node->dData = 0.0;
//    tree->node->iData = 0;
//    tree->node->dataType = 0;
    tree->node = NULL;
    tree->lchild = NULL;
    tree->rchild = NULL;
    return tree;
}

/* 定义tmpRootTree为前一树节点, tmpTree为后一节点 */
/* 如果后一节点的为空,则跳出 */
void insertVar(Tree rootTree, double dData, int iData, int dataType, char *varName){
    Tree tmpTree, parentTree;
    Node newNode = malloc(sizeof(struct _Node));
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
    if(dataType == 0){
        newNode->iData = iData;
        newNode->dataType = 0;
    }else{
        newNode->dData = dData;
        newNode->dataType = 1;
    }
    strcpy(newNode->varName, varName);
}

Node findNode(Tree rootTree, char *varName){
    Tree tmpTree, parentTree;
    tmpTree = parentTree = rootTree;
    while(tmpTree != NULL){
        parentTree = tmpTree;
        if(strcmp(parentTree->node->varName, varName) == 0){
            return parentTree->node;
        }
        tmpTree = strcmp(parentTree->node->varName, varName) >= 0 ? parentTree->lchild : parentTree->rchild;
    }
    return NULL;
}

