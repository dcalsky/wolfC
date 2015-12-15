//
// Created by Dcalsky on 15/12/5.
//

#include "parser.h"
#include "string.h"
#include "ctype.h"
#include "stdio.h"



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
    while(1){
        if(array[i++] == chr){
            return true;
        }
        ++i;
    }
    return false;
}

//设置一个或者多个字符来分割字符串, 返回一个字符串数组
char** splitStatement(char *statement, char *dividers){
    size_t len = strlen(statement);
    size_t i, j = 0, startPosition = 0;
    char **strArray = malloc(sizeof(char *) * 1001);
    for(i = 0; i < len; ++i){
        if(isChrInArray(dividers, statement[i])){
            strArray[j++] = subStatement(statement, startPosition, i);
            startPosition = i + 1;
        }else if(statement[i] == ';'){
            strArray[j] = subStatement(statement, startPosition, len-1);
        }
    }
    return strArray;
}

bool isOperator(char chr){
    return chr == '+' || chr == '-' || chr == '*' || chr == '/';
}

int getOperatorLevel(char chr){
    switch(chr){
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        default:
            return -1;
    }
}

/* 中缀转后缀 */
void transform(Stack stack, char *statement){
    size_t len = strlen(statement);
    size_t i;
    for(i = 0; i < len; ++i){
        if(isOperator(statement[i])){
            if(getOperatorLevel(statement[i]) < getOperatorLevel(getTop(stack))){

            }
        }else if(isnumber(statement[i])){
            if()
        }
    }
}



void parser(Tree rootTree, char *statement){
    actionType type = getActionType(statement);
    char *_statement, *varName;
    char **strArrary;
    Stack stack = createStack();
    Node node;
    int i = 0;
    switch (type){
        case INT_DECLARE:
            _statement = removeSpace(statement) + 3;
            strArrary = splitStatement(_statement, ',');
            while(strArrary[i] != NULL){
                declareVar(rootTree, strArrary[i], INT);
                ++i;
            }
            break;
        case DOUBLE_DECLARE:
            _statement = removeSpace(statement) + 6;
            strArrary = splitStatement(_statement, ',');
            while(strArrary[i] != NULL){
                declareVar(rootTree, strArrary[i], DOUBLE);
                ++i;
            }
            break;
        case OUTPUT:
            _statement = removeSpace(statement);
            varName = subStatement(_statement, 6, strlen(_statement) - 1);
            node = findNode(rootTree, varName);
            if(node->dataType == DOUBLE){
                printf("%.6lf", node->data.dData);
            }else{
                printf("%d", node->data.iData);
            }
            break;
        case ASSIGN:;
            strArrary = splitStatement(removeSpace(statement), '=');
            varName = strArrary[0];
            _statement = strArrary[1];
            transform(stack, _statement);
            break;
        default:
            break;
    }
}
