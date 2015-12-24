//
// Created by Dcalsky on 15/12/7.
//

#ifndef MAOLANG_UTILS_H
#define MAOLANG_UTILS_H

#include "stdbool.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

typedef enum DataType {DOUBLE, INT, OPERATOR, ALPHA} DataType;

DataType getEleType(char *str);
bool isStartWith(char *statement, char *des);
bool isStartWith(char *statement, char *des);
char* removeSpace(char *statement);
char** splitStatement(char *statement, char *dividers, bool include, bool isModeTransform);
char* append(char *str, char chr);

#endif //MAOLANG_UTILS_H
