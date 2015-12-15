//
// Created by Dcalsky on 15/12/7.
//

#ifndef MAOLANG_STACK_H
#define MAOLANG_STACK_H
#define PLUS_LEVEL 1
#define MINUS_LEVEL 1
#define MULTIPLY_LEVEL 2
#define DIVIDE_LEVEL 2


typedef struct _Stack {
    char alpha;
    struct _Stack *next;
} *Stack;

void unshift(Stack, char);
char shift(Stack);
Stack createStack();
char getTop(Stack);


#endif //MAOLANG_STACK_H
