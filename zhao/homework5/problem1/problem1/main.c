//
//  main.c
//  problem1
//
//  Created by Dcalsky on 15/10/31.
//  Copyright © 2015年 Dcalsky. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    double sum, reciprocals[5], num[5];
    int i;
    for(i = 0; i < 5; ++i){
        scanf("%lf", &num[i]);
        reciprocals[i] = 1.0 / num[i];
        sum += num[i];
        printf("NO.%d: %.2lf ", i, num[i]);
    }
    printf("\nsum: %.2lf", sum/5);
    return 0;
}
