//
//  main.c
//  problem3
//
//  Created by Dcalsky on 15/10/28.
//  Copyright © 2015年 Dcalsky. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    float denominator=2, numerator=1;
    float sum;
    int n, i;
    scanf("%d", &n);
    if(n < 1){
        return 1;
    }
    for (i = 0; i < n; ++i){
        sum += (denominator + i)/(numerator + i);
    }
    printf("%.2f", sum);
    return 0;
}
