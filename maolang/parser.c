//
// Created by Dcalsky on 15/12/5.
//

#include "parser.h"
#include "tree.h"

typedef enum  ActionType {DOUBLE_DECLARE, INT_DECLARE, OUTPUT, ASSIGN, UNRECOGNIZE} ActionType;

void declareVar(Tree rootTree, char *varName, DataType dataType){
    if(dataType == INT){
        insertVar(rootTree, varName, INT, 0);
    }else{
        insertVar(rootTree, varName, DOUBLE, 0.0);
    }
}

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

/* 中缀转前缀 */
StackEle transform(Tree rootTree, char *statement){
    char **strArrary;
    size_t i = 0;
    Node node;
    Stack stack_operator, stack_number, stack_alpha;
    bool hadAddnotation = false;
    char op;
    StackEle e, e1, e2;
    stack_alpha = createStack();
    stack_operator = createStack();
    stack_number = createStack();
    strArrary = splitStatement(statement, "+-*/()=#", true, true);
    unshift(stack_operator, OPERATOR,'#');
    while(strArrary[i] != NULL){
        printf("chr: %s\n", strArrary[i]);
        /*if(!hadAddnotation && strArrary[i+1] == NULL){
            strArrary[i+1] = malloc(sizeof(char*));
            strcpy(strArrary[i+1], "#");
            hadAddnotation = true;
        }*/
        if(isOperator(strArrary[i][0], strArrary[i][1])){
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
            if(isalpha(strArrary[i][0])){
                if(strArrary[i+1][0] != '='){
                    node = findNode(rootTree, strArrary[i]);
                    if(node->dataType == DOUBLE){
                        unshift(stack_number, DOUBLE, node->data.dData);
                    }else{
                        unshift(stack_number, INT, node->data.iData);
                    }
                }else{
                    unshift(stack_alpha, ALPHA, strArrary[i]);
                }
                ++i; // ++
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

void parser(Tree rootTree, char *statement){
    Node node;
    ActionType type = getActionType(statement);
    char *_statement, **strArrary;
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
            /*strArrary = splitStatement(removeSpace(statement), "=", true, false);*/
/*            while(strArrary[i] != NULL){
                if(strArrary[i+1] != NULL && strcmp(strArrary[i+1], "=") == 0){
                    varName[j++] = strArrary[i];
                }else if(strArrary[i+1] == NULL){
                    _statement = strArrary[i];
                }
                ++i;
            }*/
            /* y=(d=1+1)+(d=2+2) */
            _statement = append(removeSpace(statement), '#');
            transform(rootTree, _statement);
/*            while(varName[i] != NULL){
                node = findNode(rootTree, varName[i++]);
                if(node != NULL){
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
                    *//*
                    updateNode(node, e.type == DOUBLE ? e.dv : e.iv);*//*
                }else{
                    handleException(5);
                    break;
                }
            }*/
            break;
        case UNRECOGNIZE:
            /*printf("unrecognizable statement.\n");*/
            break;
    }
}
