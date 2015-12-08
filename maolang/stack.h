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


typedef struct _Stack_operator {
    char operator;
    struct _Stack_operator *next;
} *Stack_operator;

typedef struct _Stack_number {
    double number;
    struct _Stack_number *next;
} *Stack_number;

void unshift_operator(Stack_operator, char);
char shift_operator(Stack_operator);
Stack_operator createStack_operator();
char getTop_operator(Stack_operator);

void unshift_number(Stack_number, double);
double shift_number(Stack_number);
Stack_number createStack_number();
double getTop_number(Stack_number);
int getIsp(char);
int getOsp(char);
bool isOperator(char *);
double compute(char, double, double);


#endif //MAOLANG_STACK_H
