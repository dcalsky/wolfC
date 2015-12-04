//
// Created by Dcalsky on 15/11/30.
//

#include "stdio.h"
#include "tree.h"

int main(){
    Tree rootTree = createTree();
    insertVar(rootTree, 3.4, 1, 1, "a");
    //printf("%lf", findNode(rootTree, "a")->dData);
    return 0;
}
