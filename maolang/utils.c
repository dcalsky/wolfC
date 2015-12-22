//
// Created by Dcalsky on 15/12/7.
//

#include "utils.h"
#include "string.h"

bool isMatch(char *str1, char *str2){
    size_t len = strlen(str1) - strlen(str2);
    if(len == 0 && strncasecmp(str1, str2, len > 0 ? strlen(str1) : strlen(str2) ) == 0){
        return true;
    }else{
        return false;
    }
}

ValType parseStringType(char *str){
     ValType valType;
    if(strchr(str, '.')){
        valType = DOUBLE;
    }else{
        valType = INT;
    };
    return valType;
}