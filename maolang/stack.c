//
// Created by Dcalsky on 15/12/7.
//

#include "stack.h"
#include "stdlib.h"
#include "ctype.h"


Stack_operator createStack_operator(){
    Stack_operator stack = malloc(sizeof(struct _Stack_operator));
    stack->next = NULL;
    return stack;
}
Stack_number createStack_number(){
    Stack_number stack = malloc(sizeof(struct _Stack_number));
    stack->next = NULL;
    return stack;
}

/* 向栈的开头添加一个元素 */
void unshift_operator(Stack_operator stack, char operator){
    Stack_operator _stack = createStack_operator();
    _stack->operator = operator;
    _stack->next = stack->next;
    stack->next = _stack;
}

/* 向栈的开头添加一个元素 */
void unshift_number(Stack_number stack, double number){
    Stack_number _stack = createStack_number();
    _stack->number = number;
    _stack->next = stack->next;
    stack->next = _stack;
}

/* 删除并返回栈的第一个元素 */
char shift_operator(Stack_operator stack){
    Stack_operator firstStack = stack->next;
    char result = firstStack->operator;
    stack->next = stack->next->next;
    free(firstStack);
    return result;
}


/* 删除并返回栈的第一个元素 */
double shift_number(Stack_number stack){
    Stack_number firstStack = stack->next;
    double result = firstStack->number;
    stack->next = stack->next->next;
    free(firstStack);
    return result;
}

char getTop_operator(Stack_operator stack){
    return stack->next->operator;
}


double getTop_number(Stack_number stack){
    return stack->next->number;
}


int getOsp(char operator){
    switch (operator){
        case '#':
            return 0;
        case '(':
            return 6;
        case ')':
            return 1;
        case '*':
            return 4;
        case '/':
            return 4;
        case '+':
            return 2;
        case '-':
            return 2;
        default:
            return 0;
    }
}

int getIsp(char operator){
    switch (operator){
        case '#':
            return 0;
        case '*':
            return 5;
        case '(':
            return 1;
        case '/':
            return 5;
        case '+':
            return 3;
        case '-':
            return 3;
        default:
            return 0;
    }
}

bool isOperator(char *chr){
    char _chr = chr[0];
    return  !isnumber(chr[1]) && (_chr == '+' || _chr == '-' || _chr == '*' || _chr == '/' || _chr == '(' || _chr == ')' || _chr == '#');
}

bool _isOperator(char _chr){
    return  _chr == '+' || _chr == '-' || _chr == '*' || _chr == '/' || _chr == '(' || _chr == ')' || _chr == '#' ;
}

double compute(char operator, double val1, double val2){
    if(_isOperator(operator)){
        switch(operator){
            case '+':
                return val1 + val2;
            case '-':
                return val1 - val2;
            case '*':
                return val1 * val2;
            case '/':
                return val1 / val2;
            default:
                return 0.0;
        }
    }else{
        return 0.0;
    }
}