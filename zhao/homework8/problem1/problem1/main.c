//
//  main.c
//  problem1
//
//  Created by Dcalsky on 15/11/21.
//  Copyright © 2015年 Dcalsky. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    float *nums, total = 0;
    nums = (float *)malloc(sizeof(float));
    int i = 0;
    while(scanf("%f", nums + i) != EOF){
        total += nums[i];
        ++i;
    }
    free(nums);
    printf("%.2f", total / i);
    return 0;
}
