//
// Created by Dcalsky on 15/12/7.
//

#ifndef MAOLANG_STACK_H
#define MAOLANG_STACK_H
#define PLUS_LEVEL 1
#define MINUS_LEVEL 1
#define MULTIPLY_LEVEL 2
#define DIVIDE_LEVEL 2

#include "stdlib.h"
#include "ctype.h"
#include "stdio.h"
#include "stdbool.h"

typedef enum {INT, DOUBLE, OPERATOR} DataType;

typedef struct Stack{
    struct StackEle StackELe;
    DataType type;
    struct Stack *next;
} *Stack;

typedef struct StackEle {
    double dv;
    int iv;
    char op;
} StackEle;




#endif //MAOLANG_STACK_H
