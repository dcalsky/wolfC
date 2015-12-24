//
// Created by Dcalsky on 15/11/30.
//

#include "stdio.h"
#include "tree.h"
#include "parser.h"



int main(int argc, char *argv[]){
    char str[1001], pos[200] = {"/Users/Dcalsky/c/maolang/test.mao"};
    FILE *file;
    Tree rootTree = createTree();
    file = fopen(argv[1] ? argv[1] : pos, "r");
    while(fgets(str, 1001, file) != NULL){
        parser(rootTree, str);
    }
    return 0;
}
