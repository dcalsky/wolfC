//
//  main.c
//  problem2
//
//  Created by Dcalsky on 15/10/28.
//  Copyright © 2015年 Dcalsky. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n, i;
    long int total=1;
    scanf("%d", &n);
    if(n > 1 && n < 100){
        for(i = 1; i<=n; ++i){
            total *= i;
        }
        printf("%ld\n", total);
    }else{
        return 1;
    }
    return 0;
}
