//
// Created by Dcalsky on 15/11/30.
//

#include "stdio.h"
#include "tree.h"

int main(){
    Tree rootTree = createTree();
    Node tmpNode;
    insertVar(rootTree, 3.4, 1, 0, "a");
    tmpNode = findNode(rootTree, "a");
    if(tmpNode->dataType == 1){
        printf("%lf", tmpNode->dData);
    }else if(tmpNode->dataType == 0){
        printf("%d", tmpNode->iData);
    }else{
        printf("null");
    }
    return 0;
}
