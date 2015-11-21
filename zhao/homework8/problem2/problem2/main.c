//
//  main.c
//  problem2
//
//  Created by Dcalsky on 15/11/21.
//  Copyright © 2015年 Dcalsky. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char s[1000];
    scanf("%s", s);
    char *sign = ":,\"\'\\.?/_-~`!@#$%^&()";
    char *p;
    printf("%s", strtok(s, sign));
    while((p = strtok(NULL, sign))){
         printf("%s", p);
    }
    return 0;
}
