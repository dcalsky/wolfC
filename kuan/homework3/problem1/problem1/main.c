//
//  main.c
//  problem1
//
//  Created by Dcalsky on 15/11/2.
//  Copyright © 2015年 Dcalsky. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    long int x, y;
    void exchange(long int *x, long int *y);
    scanf("%ld %ld", &x, &y);
    exchange(&x, &y);
    printf("%ld %ld", x, y);
    return 0;
}

void exchange(long int *x, long int *y){
    long int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}
