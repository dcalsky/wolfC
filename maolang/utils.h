/*
 * Including lots of function to handle statement
 *
 * Created by Dcalsky on 15/12/7.
 *
 * */


#ifndef MAOLANG_UTILS_H
#define MAOLANG_UTILS_H

#include "stdbool.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

/* An important structure of date type in Maolang. Including four types: double, int, operator, letter */
typedef enum DataType {DOUBLE, INT, OPERATOR, ALPHA} DataType;

/* Get a type of data of statement (It's pretty freak. */
DataType getEleType(char *str);


/* Judge whether statement is start with some words. */
bool isStartWith(char *statement, char *des);

/* remove spaces in the statement  Ps: strlen function do not to compute '\0' */
char* removeSpace(char *statement);

/* Set one or more character to split statement and return an array of string.
 * args: include -> Whether remove operators \
 *       isModeTransform -> Whether in the process of translation.
 * */
char** splitStatement(char *statement, char *dividers, bool include, bool isModeTransform);

/* Append a notation into end of the statement for calculating easily :-) */
char* appendEndNotation(char *str);

#endif //MAOLANG_UTILS_H
