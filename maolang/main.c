//
// Created by Dcalsky on 15/11/30.
//

#include "stdio.h"
#include "tree.h"
#include "parser.h"
#include "string.h"

int main(int argc, char *argv[]){
    char *str;
    printf("%s", argv[1]);
    Tree rootTree = createTree();
   /* while(gets(str)!=EOF){
        parser(rootTree, str);
    }*/
    return 0;
}
