//
//  main.c
//  problem4
//
//  Created by Dcalsky on 15/11/12.
//  Copyright © 2015年 Dcalsky. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    char fuckme;
    int total_num, total_char, nums[101], i, j, tmp1, tmp2;
    scanf("%d %d", &total_num, &total_char);
    for(i = 0; i < total_num; ++i){
        scanf("%d", &nums[i]);
    }
    for(i = 0; i < total_char; ++i){
        scanf("\n");
        scanf("%c", &fuckme);
        switch (fuckme) {
            case 'S':
                scanf("%d", &tmp1);
                for(j = 0; j < total_num; ++j){
                    nums[j] += tmp1;
                }
                break;
            case 'M':
                scanf("%d", &tmp1);
                for(j = 0; j < total_num; ++j){
                    nums[j] *= tmp1;
                }
                break;
            case 'D':
                scanf("%d", &tmp1);
                for(j = 0; j < total_num; ++j){
                    nums[j] /= tmp1;
                }
                break;
            case 'R':
                for(j = 0; j < total_num/2; ++j){
                    tmp1 = nums[j];
                    nums[j] = nums[total_num - j - 1];
                    nums[total_num - j - 1] = tmp1;
                }
                break;
            case 'P':
                scanf("%d", &tmp1);
                scanf("%d", &tmp2);
                j = nums[tmp1];
                nums[tmp1] = nums[tmp2];
                nums[tmp2] = j;
                break;
            default:
                break;
        }
    }
    for(i = 0; i < total_num; ++i){
        printf("%d ", nums[i]);
    }
    return 0;
}
