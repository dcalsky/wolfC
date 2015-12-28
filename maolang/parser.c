//
// Created by Dcalsky on 15/12/5.
//

#include "parser.h"
#include "stdio.h"

/* Action type is a enum to judge which action is used while declaring. */
typedef enum  ActionType {DOUBLE_DECLARE, INT_DECLARE, OUTPUT, ASSIGN, UNRECOGNIZE} ActionType;

void declareVar(Tree rootTree, char *varName, DataType dataType){
    if(strcmp(varName, "print")){
        handleException(3); // "print" is a only key word in Maolang;
    }
    if(dataType == INT){
        insertVar(rootTree, varName, INT, 0);
    }else{
        insertVar(rootTree, varName, DOUBLE, 0.0);
    }
}

/* Four actions: declare int type, declare double type, assigning and output the value of variable */
ActionType getActionType(char *statement){
    ActionType type;
    if(isStartWith(statement, "int ")){
        type = INT_DECLARE;
    }else if(isStartWith(statement, "double ")){
        type = DOUBLE_DECLARE;
    }else if(strchr(statement, '=') != NULL){
        type = ASSIGN;
    }else if(strstr(statement, "print") != NULL){
        type = OUTPUT;
    }else{
        type = UNRECOGNIZE;
    }
    return type;
}

/* Compute a statement and output its result. */
// TODO 代码太凌乱
StackEle transform(Tree rootTree, char *statement){
    char **strArrary;
    size_t i = 0, j;
    Node node;
    Stack stack_operator, stack_number, stack_alpha;
    char op;
    StackEle e, e1, e2;
    stack_alpha = createStack();
    stack_operator = createStack();
    stack_number = createStack();
    bool isSign = false, isAl = true;
    strArrary = splitStatement(statement, "+-*/()=#", true, true);
    unshift(stack_operator, OPERATOR,'#');
    while(strArrary[i] != NULL){
        if(isOperator(strArrary[i][0], strArrary[i][1])){
            if(isSign && (strArrary[i][0] == '+' || strArrary[i][0] == '-')){
                e = shift(stack_operator);
                unshift(stack_operator, OPERATOR, strArrary[i][0]);
                unshift(stack_operator, OPERATOR, e.op);
                ++i;
                continue;
            }
            isSign = true;
            if(getIsp(getTop(stack_operator).op) < getOsp(strArrary[i][0])){
                unshift(stack_operator, OPERATOR, strArrary[i][0]);
                ++i; //++
            }else if(getIsp(getTop(stack_operator).op) > getOsp(strArrary[i][0])){
                if(getTop(stack_operator).op == '='){
                    node = findNode(rootTree, shift(stack_alpha).al);
                    e = getTop(stack_number);
                    if(e.type == DOUBLE){
                        if(node->dataType == DOUBLE){
                            updateNode(node, e.dv);
                        }else{
                            updateNode(node, (int) e.dv);
                        }
                    }else{
                        if(node->dataType == DOUBLE){
                            updateNode(node, (double) e.iv);
                        }else{
                            updateNode(node, e.iv);
                        }
                    }
                    shift(stack_operator);
                }else{
                    e2 = shift(stack_number);
                    e1 = shift(stack_number);
                    op = shift(stack_operator).op;
                    e = compute(op, e1, e2);
                    if(e.type == DOUBLE){
                        unshift(stack_number, DOUBLE, e.dv);
                    }else{
                        unshift(stack_number, INT, e.iv);
                    }
                }
            }else{
                shift(stack_operator);
                ++i; //++
            }
        }else if(!isOperator(strArrary[i][0], strArrary[i][1])){
            isSign = false;
            if(isalpha(strArrary[i][0])){
                j = 1;
                while(strArrary[i+j][0] != '='){
                    if(strArrary[i+j][0] != ')'){
                        isAl = false;
                        break;
                    }
                    ++j;
                }
                if(strArrary[i+1][0] == '=') isAl = true;
                if(!isAl){
                    node = findNode(rootTree, strArrary[i]);
                    if(node->dataType == DOUBLE){
                        unshift(stack_number, DOUBLE, node->data.dData);
                    }else{
                        unshift(stack_number, INT, node->data.iData);
                    }
                }else{
                    unshift(stack_alpha, ALPHA, strArrary[i]);
                }
                ++i;
            }else{
                if(getEleType(strArrary[i]) == INT){
                    unshift(stack_number, INT, atoi(strArrary[i++]));
                }else{
                    unshift(stack_number, DOUBLE, atof(strArrary[i++]));
                }
            }

        }
    }
    e = getTop(stack_number);
    return e;
}


/* parse a statement and handle it by four different actions. */
void parser(Tree rootTree, char *statement){
    Node node;
    ActionType type = getActionType(statement);
    char *_statement, **strArrary, varName[201];
    DataType dataType;
    int i = 0, j = 0;
    switch (type){
        case INT_DECLARE:
            _statement = removeSpace(statement) + 3;
            strArrary = splitStatement(_statement, ",", false, false);
            while(strArrary[i] != NULL){
                declareVar(rootTree, strArrary[i], INT);
                ++i;
            }
            break;
        case DOUBLE_DECLARE:
            _statement = removeSpace(statement) + 6;
            strArrary = splitStatement(_statement, ",", false, false);
            while(strArrary[i] != NULL){
                declareVar(rootTree, strArrary[i], DOUBLE);
                ++i;
            }
            break;
        case OUTPUT:
            _statement = removeSpace(statement) + 5;
            strcpy(varName, splitStatement(_statement, "()", false, false)[1]);
            if(isnumber(varName[0])){
                dataType = getEleType(varName);
                if(dataType == DOUBLE){
                    printf("%.6lf\n", atof(varName));
                }else{
                    printf("%d\n", atoi(varName));
                }
            }
            node = findNode(rootTree, splitStatement(_statement, "()", false, false)[1]);
            if(node == NULL){
                handleException(5);
                break;
            }
            if(node->dataType == DOUBLE){
                printf("%.6lf\n", node->data.dData);
            }else{
                printf("%d\n", node->data.iData);
            }
            break;
        case ASSIGN:
            _statement = appendEndNotation(removeSpace(statement));
            transform(rootTree, _statement);
            break;
        case UNRECOGNIZE:
            // printf("unrecognizable statement.\n");  An useless output statement.
            break;
    }
}
