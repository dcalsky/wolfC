//
//  main.c
//  problem4
//
//  Created by Dcalsky on 15/10/31.
//  Copyright © 2015年 Dcalsky. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    double data[12][5], x = 2.0;
    int i;
    /* obviously, there are only 11 steps :-( */
    for (i = 1; i <= 11; ++i) {
        printf("Line %d: ", i);
        data[i][1] = 1 / x;
        printf("%.2lf, ", data[i][1]);
        data[i][2] = x*x;
        printf("%.2lf, ", data[i][2]);
        data[i][3] = x*x*x;
        printf("%.2lf, ", data[i][3]);
        data[i][4] = x*x*x*x;
        printf("%.2lf\n", data[i][4]);
        x += 0.1;
    }
    return 0;
}
