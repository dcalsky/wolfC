//
// Created by Dcalsky on 15/12/5.
//
#ifndef MAOLANG_PARSER_H
#define MAOLANG_PARSER_H

#include "tree.h"
#include "tree.h"
#include "stdbool.h"

typedef enum {DOUBLE_DECLARE, INT_DECLARE, OUTPUT, ASSIGN} actionType;

typedef struct _Parser{
    union {
        int iData;
        double dData;
    } data;

} Parser;

void declareVar(Tree, char *, DataType);
char* removeSpace(char *);
bool isStartWith(char *, char *);
Parser parser(Tree, char *statement);
char** spiltStatement(char *statement, char divider);
char* subStatement(char *statement, size_t startPosition, size_t endPosition);


#endif //MAOLANG_PARSER_H
