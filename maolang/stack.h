//
// Created by Dcalsky on 15/12/7.
//

#ifndef MAOLANG_STACK_H
#define MAOLANG_STACK_H
#define PLUS_LEVEL 1
#define MINUS_LEVEL 1
#define MULTIPLY_LEVEL 2
#define DIVIDE_LEVEL 2

#include "stdbool.h"

typedef enum {INT, DOUBLE, OPERATOR} DataType;

typedef struct Stack{
    union {
        double data1;
        int data2;
        char operator;
    };
    DataType type;
    struct _Stack_number *next;
} *Stack;



#endif //MAOLANG_STACK_H
