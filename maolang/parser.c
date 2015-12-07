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
    }else if(strstr(statement, "printf") != NULL){
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


char** spiltStatement(char *statement, char divider){
    size_t len = strlen(statement);
    size_t i, j = 0, startPosition = 0;
    char **strArray = malloc(sizeof(char *) * 1001);
    for(i = 0; i < len; ++i){
        if(statement[i] == divider){
            strArray[j++] = subStatement(statement, startPosition, i);
            startPosition = i + 1;
        }else if(statement[i] == ';'){
            strArray[j] = subStatement(statement, startPosition, len-1);
        }
    }
    return strArray;
}

Parser parser(Tree rootTree, char *statement){
    actionType type = getActionType(statement);
    char *_statement;
    char **strArrary;
    int i = 0;
    switch (type){
        case INT_DECLARE:
            _statement = removeSpace(statement) + 3;
            strArrary = spiltStatement(_statement, ',');
            while(strArrary[i] != NULL){
                declareVar(rootTree, strArrary[i], INT);
                ++i;
            }
            break;
        case DOUBLE_DECLARE:
            _statement = removeSpace(statement) + 6;
            strArrary = spiltStatement(_statement, ',');
            while(strArrary[i] != NULL){
                declareVar(rootTree, strArrary[i], DOUBLE);
                ++i;
            }
            break;
        case OUTPUT:
            break;
        case ASSIGN:

            break;
        default:
            break;
    }

}
