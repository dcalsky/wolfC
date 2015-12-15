//
//  main.c
//  problem1
//
//  Created by Dcalsky on 15/11/12.
//  Copyright © 2015年 Dcalsky. All rights reserved.
//  我能到o(n^3)就很不错了
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a, b, c, i, j, l;
    scanf("%d %d %d", &a, &b, &c);
    long long int matrix1[a][b], matrix2[b][c], matrix3[a][c];
    for(i = 0; i < a; i++){
        for(j = 0; j < b; j++){
            scanf("%lld", &matrix1[i][j]);
        }
    }
    for(i = 0; i < b; i++){
        for(j = 0; j < c; j++){
            scanf("%lld", &matrix2[i][j]);
        }
    }
    for(i = 0; i < a; i ++){
        for(j = 0; j < c; j++){
            matrix3[i][j] = 0;
            for(l = 0; l < b; l++){
                matrix3[i][j] += matrix1[i][l] * matrix2[l][j];
            }
        }
    }
    for(i = 0; i < a; i++){
        for(j = 0; j < c; j++){
            printf("%lld ", matrix3[i][j]);
        }
        printf("\n");
    }
    return 0;
}