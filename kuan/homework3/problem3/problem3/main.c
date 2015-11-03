//
//  main.c
//  problem3
//
//  Created by Dcalsky on 15/11/2.
//  Copyright © 2015年 Dcalsky. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int heights[100], i=0, place=-1, brother_height, length;
    while (scanf("%d", &heights[i]) != EOF){
        ++i;
    };
    length = --i;
    brother_height = heights[i--];
    for (; i >= 0; --i) {
        if(heights[i] <= brother_height){
            place = i;
            break;
        }
    }
    if(place == -1){
        printf("%d\n", brother_height);
    }
    for(i = 0; i < length; ++i){
        printf("%d\n", heights[i]);
        if(place == i){
            printf("pass");
        }
    }
    return 0;
}
