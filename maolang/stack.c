//
// Created by Dcalsky on 15/12/7.
//

#include "stdarg.h"
#include "stack.h"

Stack createStack(){
    Stack stack = malloc(sizeof(struct Stack));
    stack->next = NULL;
    return stack;
}

/* 向栈的开头添加一个元素 */
void unshift(Stack stack, DataType type, ...){
    Stack _stack = createStack();
    va_list ap;
    va_start(ap, type);
    switch (type) {
        case DOUBLE:
            _stack->dv = va_arg(ap, double);
            _stack->type = DOUBLE;
            break;
        case INT:
            _stack->iv = va_arg(ap, int);
            _stack->type = INT;
            break;
        case OPERATOR:
            _stack->dv = va_arg(ap, char);
            _stack->type = OPERATOR;
            break;
    }
    va_end(ap);
    _stack->next = stack->next;
    stack->next = _stack;
}


/* 删除并返回栈的第一个元素 */
StackEle shift(Stack stack, DataType type){
    Stack firstStack = stack->next;
    StackEle stackEle;
    switch (type){
        case DOUBLE:
            stackEle.dv = firstStack->StackELe.dv;
            break;
        case INT:
            stackEle.iv = firstStack->StackELe.iv;
            break;
        case OPERATOR:
            stackEle.op = firstStack->StackELe.op;
            break;
    }
    stack->next = stack->next->next;
    free(firstStack);
    return stackEle;
}


char getTop(Stack stack){
    return stack->next->operator;
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
        printf("%lf %lf\n", val1, val2);
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