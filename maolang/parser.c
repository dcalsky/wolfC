/*
 * Maolang's Parser component
 *
 * It's important component is designed to parse the statement. And it will handle three actions: declare variable, output \
 * the value of the variable and assign data to the variable.
 *
 * Although it's embarrassed, some functions to handle exception have already designed for Maolang.
 * Created by Dcalsky on 15/12/5.
*/

#include "parser.h"
#include "stdio.h"

/* Action type is a enum to judge which action is used while declaring. */
typedef enum  ActionType {DOUBLE_DECLARE, INT_DECLARE, OUTPUT, ASSIGN, UNRECOGNIZE} ActionType;

/* Insert a variable(node) into tree */
void declareVar(Tree rootTree, char *varName, DataType dataType){
    if(strcmp(varName, "print")){
        handleException(3); // "print" is a only key word in Maolang;
    }
    if(dataType == INT){
        insertVar(rootTree, varName, INT, 0);
    }else{
        insertVar(rootTree, varName, DOUBLE, 0.0);
    }
}

/* Four actions: declare int type, declare double type, assigning and output the value of variable */
ActionType getActionType(char *statement){
    ActionType type;
    if(isStartWith(statement, "int ")){
        type = INT_DECLARE;
    }else if(isStartWith(statement, "double ")){
        type = DOUBLE_DECLARE;
    }else if(strchr(statement, '=') != NULL){
        type = ASSIGN;
    }else if(strstr(statement, "print") != NULL){
        type = OUTPUT;
    }else{
        type = UNRECOGNIZE;
    }
    return type;
}

/* Compute a statement and output its result. */
StackEle transform(Tree rootTree, char *statement){
    char **strArray;
    size_t i = 0, j;
    Node node;
    Stack stack_operator, stack_number, stack_alpha;
    char op;
    StackEle e, e1, e2;
    stack_alpha = createStack();
    stack_operator = createStack();
    stack_number = createStack();
    bool isSign = false, isAl = true;
    strArray = splitStatement(statement, "+-*/()=#", true, true);
    unshift(stack_operator, OPERATOR,'#');
    while(strArray[i] != NULL){
        if(isOperator(strArray[i][0], strArray[i][1])){
            // Judge whether the number has the sign which is a computed result of other numbers
            if(isSign && (strArray[i][0] == '+' || strArray[i][0] == '-')){
                e = shift(stack_operator);
                unshift(stack_operator, OPERATOR, strArray[i][0]);
                unshift(stack_operator, OPERATOR, e.op);
                ++i;
                continue;
            }
            //isSign = true then change positions of two operators at top of stack.
            isSign = true;
            //If the priority of operator at top of stack is less than the handling operator, then adding this operator into stack_operator.
            if(getIsp(getTop(stack_operator).op) < getOsp(strArray[i][0])){
                unshift(stack_operator, OPERATOR, strArray[i][0]);
                ++i; //++
            }else if(getIsp(getTop(stack_operator).op) > getOsp(strArray[i][0])){
                //If the priority of operator at top of stack is greater than the handling operator, then computing two numbers.
                //Ps. variable I keep original value.(Only here)
                if(getTop(stack_operator).op == '='){
                    //If operator is '=', meaning it's an assign handle.
                    node = findNode(rootTree, shift(stack_alpha).al);
                    e = getTop(stack_number);
                    if(e.type == DOUBLE){
                        if(node->dataType == DOUBLE){
                            updateNode(node, e.dv);
                        }else{
                            updateNode(node, (int) e.dv);
                        }
                    }else{ // e.type == INT
                        if(node->dataType == DOUBLE){
                            updateNode(node, (double) e.iv);
                        }else{
                            updateNode(node, e.iv);
                        }
                    }
                    shift(stack_operator);
                }else{
                    //If not, compute two numbers
                    e2 = shift(stack_number);
                    e1 = shift(stack_number);
                    op = shift(stack_operator).op;
                    e = compute(op, e1, e2);
                    if(e.type == DOUBLE){
                        unshift(stack_number, DOUBLE, e.dv);
                    }else{
                        unshift(stack_number, INT, e.iv);
                    }
                }
            }else{
                shift(stack_operator);
                ++i; //++
            }
        }else if(!isOperator(strArray[i][0], strArray[i][1])){
            isSign = false;
            //Well, there are some letter between brackets are waiting for being assigned. Because of pretty ugly, I hate them.
            if(isalpha(strArray[i][0])){
                j = 1;
                while(strArray[i+j][0] != '='){
                    if(strArray[i+j][0] != ')'){
                        isAl = false;
                        break;
                    }
                    ++j;
                }
                if(strArray[i+1][0] == '=') isAl = true;
                if(!isAl){
                    //If isAl is false, my program will think this letter will take part in process of computing.
                    node = findNode(rootTree, strArray[i]);
                    if(node->dataType == DOUBLE){
                        unshift(stack_number, DOUBLE, node->data.dData);
                    }else{
                        unshift(stack_number, INT, node->data.iData);
                    }
                }else{
                    //If isAl is true, my program will take this letter into top of stack_alpha(store some letters will be assigned).
                    unshift(stack_alpha, ALPHA, strArray[i]);
                }
                ++i;
            }else{
                if(getEleType(strArray[i]) == INT){
                    unshift(stack_number, INT, atoi(strArray[i++]));
                }else{
                    unshift(stack_number, DOUBLE, atof(strArray[i++]));
                }
            }

        }
    }
    //That's all, we get an element including data;
    e = getTop(stack_number);
    return e;
}


/* parse a statement and handle it by four different actions. */
void parser(Tree rootTree, char *statement){
    Node node;
    ActionType type = getActionType(statement);
    char *_statement, **strArray, varName[201];
    DataType dataType;
    int i = 0, j = 0;
    switch (type){
        case INT_DECLARE:
            //Pattern: int a,b,ccc;
            _statement = removeSpace(statement) + 3; //Ignore "int"
            strArray = splitStatement(_statement, ",", false, false);
            while(strArray[i] != NULL){
                declareVar(rootTree, strArray[i], INT);
                ++i;
            }
            break;
        case DOUBLE_DECLARE:
            //Pattern: double a,b,ccc;
            _statement = removeSpace(statement) + 6; //Ignore "double"
            strArray = splitStatement(_statement, ",", false, false);
            while(strArray[i] != NULL){
                declareVar(rootTree, strArray[i], DOUBLE);
                ++i;
            }
            break;
        case OUTPUT:
            //Pattern: print(variableName);
            _statement = removeSpace(statement) + 5; //Ignore "print"
            strcpy(varName, splitStatement(_statement, "()", false, false)[1]);
            if(isnumber(varName[0])){
                dataType = getEleType(varName);
                if(dataType == DOUBLE){
                    printf("%.6lf\n", atof(varName)); // Calculate to six decimal places
                }else{
                    printf("%d\n", atoi(varName));
                }
            }
            node = findNode(rootTree, splitStatement(_statement, "()", false, false)[1]);
            if(node == NULL){
                handleException(5);
                break;
            }
            if(node->dataType == DOUBLE){
                printf("%.6lf\n", node->data.dData); // Calculate to six decimal places
            }else{
                printf("%d\n", node->data.iData);
            }
            break;
        case ASSIGN:
            //Pattern: a = c+1;
            _statement = appendEndNotation(removeSpace(statement)); //Add '#' at end of statement.
            transform(rootTree, _statement); // handle every statements !
            break;
        case UNRECOGNIZE:
            // poor robustness :-(
            // printf("unrecognizable statement.\n");
            break;
    }
}
