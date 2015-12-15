//
//  main.c
//  problem3
//
//  Created by Dcalsky on 15/11/12.
//  Copyright © 2015年 Dcalsky. All rights reserved.
//  Ugly program I think ..
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    long long int a, b, c, d, i = -1;
    scanf("%lld %lld", &a, &b);
    c = a;
    d = b;
    if(a < b){
        a = b;
        b = c;
    }
    while (1) {
        i = a % b;
        if(i == 0){
            break;
        }
        a = b;
        b = i;
    }
    printf("%lld\n%lld", b, c*d/b);
    return 0;
}
