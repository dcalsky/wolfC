//
// Created by Dcalsky on 15/12/5.
//

#include "parser.h"
#include "string.h"
#include "ctype.h"
#include "stdio.h"
#include "exception.h"

void declareVar(Tree rootTree, char *varName, DataType dataType){
    if(dataType == INT){
        insertVar(rootTree, varName, INT, 0);
    }else{
        insertVar(rootTree, varName, DOUBLE, 0.0);
    }
}

actionType getActionType(char *statement){
    actionType type;
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


/* remove space in statement  Ps: strlen function do not to compute '\0' */
char* removeSpace(char *statement){
    size_t i, j;
    size_t len = strlen(statement);
    char *_statement = malloc((len+1) * sizeof(char));
    for(i = j = 0; i < len; ++i){
        if(!isspace(statement[i])){
            _statement[j++] = statement[i];
        }
    }
    _statement[j] = '\0';  // So add '\0' in the end of _statement
    return _statement;
}

bool isStartWith(char *statement, char *des){
    size_t statement_len = strlen(statement);
    size_t des_len = strlen(des);
    char *_statement;
    bool result = true;
    int j, i = 0;
    if(statement_len < des_len){
        result = false;
    }else{
        while(isspace(statement[i++])); // 去掉左侧空格
        _statement = statement + (--i);
        for(j = 0; j < des_len; ++j){
            if(des[j] != _statement[j]){
                result = false;
                break;
            }
        }
    }
    return result;
}


char* subStatement(char *statement, size_t startPosition, size_t endPosition){
    if(endPosition <= startPosition){
        return NULL;
    }
    char *_statement = malloc(sizeof(char) * endPosition - startPosition + 1);
    size_t i, j;
    for(i = startPosition, j = 0; i < endPosition; ++i){
        _statement[j++] = statement[i];
    }
    _statement[j] = '\0';
    return _statement;
}

bool isChrInArray(char *array, char chr){
    int i = 0;
    for(i = 0; i < strlen(array); ++i){
        if(array[i] == chr){
            return true;
        }
    }
    return false;
}

bool __isOperator(char chr){
    return chr == '+' || chr == '-' || chr == '*' || chr == '/' || chr == '(' || chr == ')';
}

//设置一个或者多个字符来分割字符串, 返回一个字符串数组(是否包括分隔符可选)
char** splitStatement(char *statement, char *dividers, bool include, bool isModeTransform){
    size_t len = strlen(statement);
    size_t i, j = 0, startPosition = 0;
    char **strArray = malloc(sizeof(char *) * 1001);
    for(i = 0; i < len; ++i){
        if(isChrInArray(dividers, statement[i])){
            if(isModeTransform && statement[i] == '-' && __isOperator(statement[i-1]) && isnumber(statement[i+1])){
                continue;
            }
            strArray[j++] = subStatement(statement, startPosition, i);
            if(include && strArray[j-1] != NULL){
                strArray[j++] = subStatement(&statement[i], 0, 1);
            }else if(include && strArray[j-1] == NULL){
                strArray[j-1] = subStatement(&statement[i], 0, 1);
            }
            startPosition = i + 1;
        }else if(statement[i] == ';'){
            strArray[j] = subStatement(statement, startPosition, len-1);
        }else if(i == len - 1){
            strArray[j] = subStatement(statement, startPosition, len);
        }
    }
    return strArray;
}


/* 中缀转前缀 */
double transform(Tree rootTree, Stack_operator stack_operator, Stack_number stack_number, char *statement){
    char **strArrary, **_strArrary;
    size_t len = strlen(statement);
    size_t i = 0;
    Node node;
    bool hadAddnotation = false;
    char operator;
    double value = 0.0, val1 = 0.0, val2 = 0.0;
    strArrary = splitStatement(statement, "+-*/()", true, true);
    unshift_operator(stack_operator, '#');
    while(strArrary[i] != NULL){
        if(!hadAddnotation && strArrary[i+1] == NULL){
            strArrary[i+1] = malloc(sizeof(char*));
            strcpy(strArrary[i+1], "#");
            hadAddnotation = true;
        }
        if(isOperator(strArrary[i])){
            if(getIsp(getTop_operator(stack_operator)) < getOsp(strArrary[i][0])){
                unshift_operator(stack_operator, strArrary[i++][0]);
            }else if(getIsp(getTop_operator(stack_operator)) > getOsp(strArrary[i][0])){
                val2 = shift_number(stack_number);
                val1 = shift_number(stack_number);
                operator = shift_operator(stack_operator);
                if(operator == '/' && val2 == 0){
                    handleException(1);
                }
                value = compute(operator, val1, val2);
                unshift_number(stack_number, value);
            }else{
                shift_operator(stack_operator);
                ++i;
            }
        }else if(!isOperator(strArrary[i])){
            if(isalpha(strArrary[i][0])){
                  node = findNode(rootTree, strArrary[i++]);
                  value = node->dataType == DOUBLE ? node->data.dData : node->data.iData;
            }else{
                value = atof(strArrary[i++]);
            }
            unshift_number(stack_number, value);
        }
    }
    value = getTop_number(stack_number);
    return value;
}

void parser(Tree rootTree, char *statement){
    actionType type = getActionType(statement);
    char *_statement, **varName, **strArrary;
    Stack_operator stack_operator = createStack_operator();
    Stack_number stack_number = createStack_number();
    Node node;
    double value = 0.0;
    varName = malloc(sizeof(char *) * 1001);
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
            strArrary = splitStatement(removeSpace(statement), "=", true, false);
            while(strArrary[i] != NULL){
                if(strArrary[i+1] != NULL && strcmp(strArrary[i+1], "=") == 0){
                    varName[j++] = strArrary[i];
                }else if(strArrary[i+1] == NULL){
                    _statement = strArrary[i];
                }
                ++i;
            }
            i = 0;
            value = transform(rootTree, stack_operator, stack_number, _statement);
            while(varName[i] != NULL){
                node = findNode(rootTree, varName[i++]);
                if(node != NULL){
                    updateNode(node, value);
                }else{
                    handleException(5);
                    break;
                }
            }
            break;
        case UNRECOGNIZE:
            printf("unrecognizable statement.\n");
            break;
    }
}
