//
// Created by Dcalsky on 15/12/7.
//

#include "stdarg.h"
#include "stack.h"


/* 更新并返回StackElement */
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
    switch (type){
        case DOUBLE:
            _stack->StackELe.dv = va_arg(ap, double);
            _stack->StackELe.type = DOUBLE;
            break;
        case INT:
            _stack->StackELe.iv = va_arg(ap, int);
            _stack->StackELe.type = INT;
            break;
        case OPERATOR:
            _stack->StackELe.op = va_arg(ap, char);
            _stack->StackELe.type = OPERATOR;
            break;
        case ALPHA:
            strcpy(_stack->StackELe.al, va_arg(ap, char*));
            _stack->StackELe.type = ALPHA;
            break;
    }
    _stack->next = stack->next;
    stack->next = _stack;
    va_end(ap);
}


/* 删除并返回栈的第一个元素 */
StackEle shift(Stack stack){
    Stack firstStack = stack->next;
    StackEle _e;
    if(firstStack == NULL){
        _e.type = DOUBLE;
        _e.dv = 0.0;
        return _e;
    }
    _e = firstStack->StackELe;
    stack->next = stack->next->next;
    free(firstStack);
    return _e;
}

void clearStack(Stack stack){
    Stack _stack = createStack();

}

StackEle getTop(Stack stack){
    Stack firstStack = stack->next;
    StackEle _e;
    _e = firstStack->StackELe;
    return _e;
}


int getOsp(char operator){
    switch (operator){
        case '#':
            return 0;
        case '(':
            return 8;
        case ')':
            return 1;
        case '*':
            return 5;
        case '/':
            return 5;
        case '+':
            return 3;
        case '-':
            return 3;
        case '=':
            return 7;
    }
}

int getIsp(char operator){
    switch (operator){
        case '#':
            return 0;
        case '(':
            return 1;
        case '*':
            return 6;
        case '/':
            return 6;
        case '+':
            return 4;
        case '-':
            return 4;
        case '=':
            return 2;
    }
}

bool isOperator(char chr, ...){
    va_list ap;
    va_start(ap, chr);
    return  !isnumber(va_arg(ap, char)) && (chr == '+' || chr == '-' || chr == '*' || chr == '/' || chr == '(' || chr == ')' || chr == '=' || chr == '#');
}

StackEle compute(char operator, StackEle e1, StackEle e2){
    fflush(stdout);
    DataType type1, type2;
    double val = 0;
    StackEle e;
    type1 = e1.type;
    type2 = e2.type;
    if(isOperator(operator)){
        switch(operator){
            case '+':
                val = (type1 == DOUBLE ? e1.dv : e1.iv) + (type2 == DOUBLE ? e2.dv : e2.iv);
                break;
            case '-':
                val = (type1 == DOUBLE ? e1.dv : e1.iv) - (type2 == DOUBLE ? e2.dv : e2.iv);
                break;
            case '*':
                val = (type1 == DOUBLE ? e1.dv : e1.iv) * (type2 == DOUBLE ? e2.dv : e2.iv);
                break;
            case '/':
                if((type2 == DOUBLE && e2.dv == 0) || type2 == INT && e2.iv == 0) {
                    handleException(1);
                }
                val = (type1 == DOUBLE ? e1.dv : e1.iv) / (type2 == DOUBLE ? e2.dv : e2.iv);
                break;
        }
        if(type1 == INT && type1 == type2){
            e.type = INT;
            e.iv = (int) val;
            // b = a = 3 + 7 * 2
        }else{
            e.type = DOUBLE;
            e.dv = val;
        }
    }
    return e;
}