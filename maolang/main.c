//
// Created by Dcalsky on 15/11/30.
//

#include "stdio.h"
#include "tree.h"
#include "parser.h"


int main(int argc, char *argv[]){
    char str[1001];
    Tree rootTree = createTree();
    while(gets(str) != EOF){
        parser(rootTree, str);
    }
    return 0;
}
