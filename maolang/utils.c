//
// Created by Dcalsky on 15/12/7.
//

#include "utils.h"

/* Get a type of data of statement (It's pretty freak. */
DataType getEleType(char *str){
     DataType type;
    if(strchr(str, '.')){
        type = DOUBLE;
    }else{
        type = INT;
    };
    return type;
}

/* Append a notation into end of the statement for calculating easily :-) */
char* appendEndNotation(char *str){
    size_t len = strlen(str);
    if(str[len - 1] == ';'){
        str[len - 1] = '#';
    }else{
        str[len] = '#';
    }
    return str;
}

/* Judge whether statement is start with some words. */
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

/* remove spaces in the statement  Ps: strlen function do not to compute '\0' */
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


/* Drag a segment of the statement within defined limits. */
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

/* Judge whether a character is in the array  */
bool isChrInArray(char *array, char chr){
    int i = 0;
    for(i = 0; i < strlen(array); ++i){
        if(array[i] == chr){
            return true;
        }
    }
    return false;
}

/* Judge whether the character is an operator. */
bool isOperator(char chr, ...){
    va_list ap;
    va_start(ap, chr);
    return  !isnumber(va_arg(ap, char)) && (chr == '+' || chr == '-' || chr == '*' || chr == '/' || chr == '(' || chr == ')' || chr == '=' || chr == '#');
}


/* Set one or more character to split statement and return an array of string.
 * args: include -> Whether remove operators \
 *       isModeTransform -> Whether in the process of translation.
 * */
char** splitStatement(char *statement, char *dividers, bool include, bool isModeTransform){
    size_t len = strlen(statement);
    size_t i, j = 0, startPosition = 0;
    char **strArray = malloc(sizeof(char *) * 100);
    for(i = 0; i < len; ++i){
        if(isChrInArray(dividers, statement[i])){
            if(isModeTransform && statement[i] == '-' && isOperator(statement[i-1]) && isnumber(statement[i+1])){
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