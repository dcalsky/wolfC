//
//  main.c
//  problem2
//
//  Created by Dcalsky on 15/11/2.
//  Copyright © 2015年 Dcalsky. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int totalDays = 0, year, month, day, i;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d %d %d", &year, &month, &day);
    if (year % 100 == 0) {
        if (year % 400 == 0) {
            days[1] = 29;
        }
    } else if (year % 4 == 0) {
        days[1] = 29;
    }
    // 1900 is not a leap year :)
    
    for(i = 0; i < month - 1; ++i){
        totalDays = totalDays + days[i];
    }
    totalDays += day;
    printf("%d", totalDays);
    return 0;
}
