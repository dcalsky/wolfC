//
// Created by Dcalsky on 15/11/30.
//

#include "stdio.h"
#include "tree.h"
#include "parser.h"
#include "string.h"

int main(){
    Tree rootTree = createTree();
    Node tmpNode;
    char *str = {"    int a, bb   , ccc;"};
    insertVar(rootTree, "ab", INT, -11);
    insertVar(rootTree, "ac", DOUBLE, 6.6);

    //printf("%lu", strlen(spiltStatement(removeSpace(str), ',')[1]));
    parser(rootTree, str);
    tmpNode = findNode(rootTree, "a");
    updateNode(tmpNode, 3.5);
    if(tmpNode->dataType == 1){
        printf("%.6lf\n", tmpNode->data.dData);
    }else if(tmpNode->dataType == 0){
        printf("%d\n", tmpNode->data.iData);
    }else{
        printf("null");
    }
    return 0;
}
