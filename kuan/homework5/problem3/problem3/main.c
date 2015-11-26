//
//  main.c
//  problem3
//
//  Created by Dcalsky on 15/11/25.
//  Copyright © 2015年 Dcalsky. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int dots = -1;

int main(int argc, const char * argv[]) {
    char str[1001];
    int i, success = -1;
    int judgeNum(char *, int , char);
    scanf("%s", str);
    for(i = 0; i < strlen(str); ++i){
        if(judgeNum(str, i, str[i]) == 1){
            success = 1;
        }else{
            success = 0;
            break;
        }
        
    }
    if(success == 1){
        printf("true");
    }else{
        printf("false");
    }
    return 0;
}


int judgeNum(char str[], int i, char c){
    if(c == 43 || c == 45){
        return i == 0 || str[i - 1] == 69 || str[i - 1] == 101;
    }else if(c > 47 && c < 58){
        return 1;
    }else if(c == 69 || c == 101){
        return i != 0 && i != strlen(str) - 1 && str[i + 1] != 46 ;
    }else if(c == 46){
        dots += 1;
        return dots == 0 && i != strlen(str) - 1 && str[i + 1] > 47 && str[i + 1] < 58;
    }else{
        return 0;
    }
}

