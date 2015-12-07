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
    for(i = 0; i < strlen(array); ++i){
        if(array[i] == chr){
            return true;
        }
    }
    return false;
}

//设置一个或者多个字符来分割字符串, 返回一个字符串数组(是否包括分隔符可选)
char** splitStatement(char *statement, char *dividers, bool include){
    size_t len = strlen(statement);
    size_t i, j = 0, startPosition = 0;
    char **strArray = malloc(sizeof(char *) * 1001);
    for(i = 0; i < len; ++i){
        if(isChrInArray(dividers, statement[i])){
            strArray[j++] = subStatement(statement, startPosition, i);
            if(include){
                strArray[j++] = subStatement(&statement[i], 0, 1);
            }
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
    size_t i = 0;
}



void parser(Tree rootTree, char *statement){
    actionType type = getActionType(statement);
    char *_statement, **varName, **strArrary;
    Stack stack = createStack();
    Node node;
    varName = malloc(sizeof(char *) * 1001);
    int i = 0, j = 0;
    switch (type){
        case INT_DECLARE:
            _statement = removeSpace(statement) + 3;
            strArrary = splitStatement(_statement, ",", false);
            while(strArrary[i] != NULL){
                declareVar(rootTree, strArrary[i], INT);
                ++i;
            }
            break;
        case DOUBLE_DECLARE:
            _statement = removeSpace(statement) + 6;
            strArrary = splitStatement(_statement, ",", false);
            while(strArrary[i] != NULL){
                declareVar(rootTree, strArrary[i], DOUBLE);
                ++i;
            }
            break;
        case OUTPUT:
            _statement = removeSpace(statement);
            varName[0] = subStatement(_statement, 6, strlen(_statement) - 1);
            node = findNode(rootTree, varName[0]);
            if(node->dataType == DOUBLE){
                printf("%.6lf", node->data.dData);
            }else{
                printf("%d", node->data.iData);
            }
            break;
        case ASSIGN:;
            strArrary = splitStatement(removeSpace(statement), "=", true);
            while(strArrary[i] != NULL){
                if(strcmp(strArrary[i+1], "=")){
                    varName[j] = strArrary[i];
                }else{
                    _statement = strArrary[i+1];
                }
                ++i;
            }
            printf("%s", varName[0]);
            break;
        default:
            break;
    }
}
