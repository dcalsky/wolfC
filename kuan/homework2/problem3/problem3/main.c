//
//  main.c
//  problem3
//
//  Created by Dcalsky on 15/10/27.
//  Copyright © 2015年 Dcalsky. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n, type=1, i;
    void(printStar(int n, int i));
    scanf("%d %d", &n, &type);
    if(type==0){
        for(i=n; i>0; --i){
            printStar(n, i);
            printf("\n");
        }
    }else{
        for(i=1; i<=n; ++i){
            printStar(n, i);
            printf("\n");
        }
    }
    return 0;
}

void printStar(int n, int i){
    int star;
    for(star=0; star<n*2-1; ++star){
        if(i==n || star == (n*2-1)/2-i+1 ||star == (n*2-1)/2+i-1){
            printf("*");
        }else{
            printf(" ");
        }
    }
}
