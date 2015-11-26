//
//  main.c
//  problem2
//
//  Created by Dcalsky on 15/11/26.
//  Copyright © 2015年 Dcalsky. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int num;
    int getSum(int);
    scanf("%d", &num);
    printf("%d", getSum(num));
    return 0;
}

int getSum(int num){
    if(num == 1 || num == 2){
        return 1;
    }else{
        return getSum(num - 1) + getSum(num - 2);
    }
}
