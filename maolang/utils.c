//
// Created by Dcalsky on 15/12/7.
//

#include "utils.h"
#include "string.h"

bool isMatch(char *str1, char *str2){
    if(strncasecmp(str1, str2, 6) == 0){
        return true;
    }else{
        return false;
    }
}