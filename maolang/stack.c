//
// Created by Dcalsky on 15/12/7.
//

#include "stack.h"
#include "stdlib.h"


Stack createStack(){
    Stack stack = malloc(sizeof(struct _Stack));
    stack->next = NULL;
    return stack;
}

/* 向栈的开头添加一个元素 */
void unshift(Stack stack, char operator){
    Stack _stack = createStack();
    _stack->alpha = operator;
    _stack->next = stack->next;
    stack->next = _stack;
}

/* 删除并返回栈的第一个元素 */
char shift(Stack stack){
    Stack firstStack = stack->next;
    char result = firstStack->alpha;
    stack->next = stack->next->next;
    free(firstStack);
    return result;
}

char getTop(Stack stack){
    return stack->next->alpha;
}

