/*
 * Maolang's Stack component
 *
 * First of all, I wanna say: every data will be packed in the structure named StackEle while transferring.
 * Why I choose this way to transfer data? Because I find it's difficult to achieve common type to store the data, and it will \
 * produce some mistake in computing value of double and int type.
 * Admitting it's a ugly way to pack many types of data whichever name of variable or member of structure. But I try my best \
 * to solve this problem, fortunately, I made it.
 *
 * By the way, it often use two stacks(stack_number and stack_operator) in the process of calculation.
 *
 * Created by Dcalsky on 15/12/7.
 *
 * */

#ifndef MAOLANG_STACK_H
#define MAOLANG_STACK_H
#include "ctype.h"
#include "stdbool.h"
#include "exception.h"
#include "stdlib.h"
#include "utils.h"
#include "stdarg.h"

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


/* Get the priority of the operator which is out of the operator's stack. */
int getOsp(char);

/* Get the priority of the operator which is in the operator's stack. */
int getIsp(char);

/* Get the element at top of the stack. */
StackEle getTop(Stack);

/* Delete a element of top of the stack and return it. */
StackEle shift(Stack);

/* Add a special element to top of the stack. Nothing will be returned .*/
void unshift(Stack stack, DataType type, ...);

/* Create a new stack and return it. */
Stack createStack();

/* Compute two elements according to the operator and return the result(StackEle). */
StackEle compute(char operator, StackEle e1, StackEle e2);

/* Judge whether the character is an operator. */
bool isOperator(char, ...);



#endif //MAOLANG_STACK_H
