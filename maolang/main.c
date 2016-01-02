/*
 * Main function to launch Maolang.
 *
 * Launching by command line is prior. And if function can not read some data from argv, it will read data from example text.
 *
 * Program will handle statement line by line.
 *
 * Created by Dcalsky on 15/11/30.
 *
 * */

#include "stdio.h"
#include "tree.h"
#include "parser.h"

//Begin
int main(int argc, char *argv[]){
    FILE *file;
    char str[1001], pos[200] = {"/Users/Dcalsky/c/maolang/test.mao"};
    Tree rootTree = createTree(); //Create a new tree through over whole the program.
    file = fopen(argv[1] ? argv[1] : pos, "r"); //If program can't read any data from outside, it will use data of test.
    while(fgets(str, 1001, file) != NULL){
        parser(rootTree, str); //Enter handle of parser.
    }
    fclose(file);
    return 0;
}