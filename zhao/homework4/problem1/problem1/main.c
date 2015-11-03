//
//  main.c
//  problem1
//
//  Created by Dcalsky on 15/10/28.
//  Copyright © 2015年 Dcalsky. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int height, width, i, j;
    printf("width: ");
    scanf("%d", &width);
    printf("height: ");
    scanf("%d", &height);
    for (i = 0; i < height; ++i){
        for(j = 0; j < width; ++j){
            if(i == 0 || i == height - 1 || j == 0 || j == width -1){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
