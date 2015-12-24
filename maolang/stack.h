//
// Created by Dcalsky on 15/12/7.
//

#ifndef MAOLANG_STACK_H
#define MAOLANG_STACK_H
#include "ctype.h"
#include "stdio.h"
#include "stdbool.h"
#include "exception.h"
#include "stdlib.h"
#include "utils.h"

typedef struct StackEle {
    union {
        double dv;
        int iv;
        char op;
        char al[101];
    };
    DataType type;
} StackEle;

typedef struct Stack{
    struct StackEle StackELe;
    struct Stack *next;
} *Stack;

int getOsp(char);
int getIsp(char);
StackEle getTop(Stack);
StackEle shift(Stack);
void unshift(Stack stack, DataType type, ...);
Stack createStack();
StackEle compute(char operator, StackEle e1, StackEle e2);
bool isOperator(char, ...);



#endif //MAOLANG_STACK_H
