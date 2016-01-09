//
//  main.c
//  problem2
//
//  Created by Dcalsky on 15/10/31.
//  Copyright © 2015年 Dcalsky. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int num, i;
    int first=1, second=1, current = 1;
    scanf("%d", &num);
    for (i = 0; i < num - 2; ++i) {
        current = first + second;
        first = second;
        second = current;
    }
    printf("%d", current);
    return 0;
}
