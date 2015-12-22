//
// Created by Dcalsky on 15/12/22.
//

/* Exception handling
 * only one argument of int is 'type'
 * 1 -> any of number is divided by zero (= .. =)
 * 2 -> lacking of semicolon to end statement (It's all right.)
 * 3 -> systematic keywords are assigned as var. (like print etc...)
 * 4 -> value of var is out range of available maximum. (You're freak ...)
 * 5 -> Time out ...
 * */

#ifndef MAOLANG_EXCEPTION_H
#define MAOLANG_EXCEPTION_H
#define    EDBZ       1
#define    ELS        2
#define    EAK        3
#define    EOA        4
#define    ENA        5

void handleException(int);


#endif //MAOLANG_EXCEPTION_H
