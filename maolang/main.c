//
// Created by Dcalsky on 15/11/30.
//

#include "stdio.h"
#include "tree.h"

int main(){
    Tree rootTree = createTree();
    Node tmpNode;
    insertVar(rootTree, 3.4, 1, 0, "ab");
    insertVar(rootTree, 6.6, 1, 1, "ac");
    insertVar(rootTree, 5.5, 1, 1, "aad");
    insertVar(rootTree, 3.1, 1, 1, "ae");
    tmpNode = findNode(rootTree, "ab");
    if(tmpNode->dataType == 1){
        printf("%lf\n", tmpNode->dData);
    }else if(tmpNode->dataType == 0){
        printf("%d\n", tmpNode->iData);
    }else{
        printf("null");
    }
    return 0;
}
