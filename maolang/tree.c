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
    Node newNode;
    tmpTree = parentTree = rootTree;
    Tree newTree = createTree();
    //newTree->node = malloc(sizeof(struct _Node));
    while(tmpTree != NULL){
        parentTree = tmpTree;
        if(parentTree->node == NULL){
            break;
        }
        tmpTree = strcmp(parentTree->node->varName, varName) >= 0 ? parentTree->lchild : parentTree->rchild;
    }
    if(tmpTree == NULL){
        tmpTree = newTree;
        newNode = tmpTree->node = malloc(sizeof(struct _Node));
    }else if(parentTree->node == NULL){
        newNode = parentTree->node = malloc(sizeof(struct _Node));
    }
    if(dataType == 0){
        newNode->iData = iData;
        newNode->dataType = 0;
    }else{
        newNode->dData = dData;
        newNode->dataType = 1;
    }
    strcpy(newNode->varName, varName);
    /*
    while(tmpTree != NULL){
        parentTree = tmpTree;
        if(strcmp(parentTree->node->varName, "") != 0){
            break;
        }
        tmpTree = strcmp(parentTree->node->varName, varName) >= 0 ? parentTree->lchild : parentTree->rchild;
    }
    printf("123");
    if(strcmp(parentTree->node->varName, varName) >= 0){
        parentTree->lchild = newTree;

    }else{
        parentTree->rchild = newTree;
    }
    strcpy(newTree->node->varName, varName);
    if(dataType == 1){
        newTree->node->dData = dData;
    }else{
        newTree->node->iData = iData;
    }



    if(tmpTree == NULL){
        tmpTree = newTree;
        tmpTree->node->
    }else if(tmpTree->node == NULL){

    }


    if(tmpTree->node == NULL){
        tmpRootTree
    }else{
        while(tmpTree != NULL){
            tmpRootTree = tmpTree;
            tmpTree = strcmp(tmpTree->node->varName, varName) >= 0 ? tmpTree->lchild : tmpTree->rchild;
        }
    }
    if(strcmp(tmpRootTree->node->varName, varName) >= 0){
        tmpRootTree->lchild = newTree;
    }else{
        tmpRootTree->rchild = newTree;
    }
    strcpy(newNode->varName, varName);
    if(dataType == 1){
        newNode->dData = dData;
    }else{
        newNode->iData = iData;
    }
     */


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
    /*
    while(strcmp(baseNode->varName, varName) != 0){
        tmpTree = strcmp(baseNode->varName, varName) >= 0 ? tmpTree->lchild : tmpTree->rchild;
        if(tmpTree == NULL){
            break;
        }
        baseNode = tmpTree->node;
    }
    return baseNode;
     */
}

