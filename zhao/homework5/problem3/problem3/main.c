//
//  main.c
//  problem3
//
//  Created by Dcalsky on 15/10/31.
//  Copyright © 2015年 Dcalsky. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int num, i;
    /* cute rabbits :) */
    int rabbits[1000];
    rabbits[0] = rabbits[1] = 1;
    scanf("%d", &num);
    for (i = 2; i < num; ++i) {
        rabbits[i] = rabbits[i-1] + rabbits[i-2];
    }
    printf("%d", rabbits[num-1]);
    return 0;
}