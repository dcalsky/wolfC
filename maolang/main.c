//
// Created by Dcalsky on 15/11/30.
//

#include "stdio.h"
#include "tree.h"
#include "parser.h"

int main(){
    Tree rootTree = createTree();
    Node tmpNode;
    char *str = {"double a = 9;"};
    insertVar(rootTree, "ab", INT, -11);
    insertVar(rootTree, "ac", DOUBLE, 6.6);
    tmpNode = findNode(rootTree, "ac");

    if(tmpNode->dataType == 1){
        printf("%.6lf\n", tmpNode->data.dData);
    }else if(tmpNode->dataType == 0){
        printf("%d\n", tmpNode->data.iData);
    }else{
        printf("null");
    }
    parser(str);
    return 0;
}
