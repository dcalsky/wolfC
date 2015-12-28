/*
 * Maolang's Parser component
 *
 * It's important component is designed to parse the statement. And it will handle three actions: declare variable, output \
 * the value of the variable and assign data to the variable.
 *
 * Although it's embarrassed, some functions to handle exception have already designed for Maolang.
 * Created by Dcalsky on 15/12/5.
*/
#ifndef MAOLANG_PARSER_H
#define MAOLANG_PARSER_H

#include "tree.h"
#include "stack.h"
#include "stdbool.h"
#include "string.h"
#include "exception.h"
#include "utils.h"

/* parse a statement and handle it by four different actions. */
void parser(Tree, char*);


#endif //MAOLANG_PARSER_H
