//
//  main.c
//  problem2
//
//  Created by Dcalsky on 15/11/12.
//  Copyright © 2015年 Dcalsky. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    char str1[101], str2[101];
    int i;
    gets(str1);
    gets(str2);
    for(i = 0; i < strlen(str1); i++){
        printf("%c", str1[i]);
    }
    for(i = 0; i < strlen(str2); i++){
        printf("%c", str2[i]);
    }
    return 0;
}
