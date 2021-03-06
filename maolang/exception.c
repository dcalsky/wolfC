/* Exception handling
 * only one argument of int is 'type'
 * 1 -> any of number is divided by zero (= .. =)
 * 2 -> lacking of semicolon to end statement (It's all right.)
 * 3 -> systematic keywords are assigned as var. (like print etc...)
 * 4 -> value of var is out range of available maximum. (You're freak ...)
 * 5 -> var is not be assigned.
 *
 * Unfortunately, many conditions not be considered.
 * Created by Dcalsky on 15/12/22.
 * */


#include "exception.h"
#include "stdio.h"
#include "stdlib.h"

void handleException(int type){
    switch (type){
        case EDBZ:
            printf("divided by ZERO");
            exit(1); // exit program.
        case ELS:
            break;
        case EAKW:
            break;
        case EOA:
            break;
        case ENA:
            //printf("some vars is not be assigned...\n");
            break;
        default:
            break;
    }
}