//
// Created by Dcalsky on 15/12/5.
//

#include "parser.h"
#include "string.h"
#include <ctype.h>
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

Parser parser(char *statement){
    int pos = -1;
    actionType type = getActionType(statement);
    switch (type){
        case INT_DECLARE:

            break;
        case DOUBLE_DECLARE:
            printf("double");
            break;
        case OUTPUT:
            break;
        case ASSIGN:
            break;
        default:
            break;
    }

}
