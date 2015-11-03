//
//  main.c
//  problem4
//
//  Created by Dcalsky on 15/10/28.
//  Copyright © 2015年 Dcalsky. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i;
    /* continue */
    printf("########continue########\n");
    for(i = 0; i < 10; ++i){
        if(i == 6){
            continue;
        }
        printf("%d\n", i);
    }
    
    
    /* break */
    printf("########break########\n");
    for(i = 0; i < 10; ++i){
        if(i == 6){
            break;
        }
        printf("%d\n", i);
    }
    return 0;
}
