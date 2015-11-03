//
//  main.c
//  problem3
//
//  Created by Dcalsky on 15/11/2.
//  Copyright © 2015年 Dcalsky. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int heights[100], i=0, place=-1, brother, length;
    
    while (scanf("%d", &heights[i]) != EOF) {
        ++i;
    }
    --i;
    length = i;
    brother = heights[i];
    --i;
    for (; i>=0; --i) {
        if(heights[i] <= brother){
            place = i;
            break;
        }
    }
    if(place == -1){
        printf("%d\n", brother);
    }
    for(i = 0; i<length; ++i){
        if(place == i){
            printf("%d\n", heights[i]);
            printf("%d\n", brother);
        }else{
            printf("%d\n", heights[i]);
        }
    }

    return 0;
}
