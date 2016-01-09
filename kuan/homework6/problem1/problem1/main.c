//
//  main.c
//  problem1
//
//  Created by Dcalsky on 15/12/8.
//  Copyright © 2015年 Dcalsky. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int len, i;
    scanf("%d", &len);
    char *str = malloc(sizeof(char) * (len + 1));
    scanf(" %[^\n]", str);
    for(i = 0; i < len; ++i){
        if(str[i] == 32){
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}
