//
//  main.c
//  problem2
//
//  Created by Dcalsky on 15/10/27.
//  Copyright © 2015年 Dcalsky. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int count, i;
    float ci, total_ci=0.00, total_si=0.00;
    char si[3];
    scanf("%d", &count);
    if(count < 1 && count > 1000){
        return 1;
    }
    for ( i = 0; i<count; ++i){
        scanf("%f %s", &ci, si);
        if(ci>=1 && ci<= 10){
            if(strcmp(si, "P") != 0 && strcmp(si, "N") != 0){
                total_ci += ci;
            }
            if(strcmp(si, "A")==0){
                total_si += 4.0 * ci;
            }else if(strcmp(si, "A-")==0){
                total_si += 3.7 * ci;
            }else if(strcmp(si, "B+")==0){
                total_si += 3.3 * ci;
            }else if(strcmp(si, "B")==0){
                total_si += 3.0 * ci;
            }else if(strcmp(si, "B-")==0){
                total_si += 2.7 * ci;
            }else if(strcmp(si, "C+")==0){
                total_si += 2.3 * ci;
            }else if(strcmp(si, "C")==0){
                total_si += 2.0 * ci;
            }else if(strcmp(si, "C-")==0){
                total_si += 1.7 * ci;
            }else if(strcmp(si, "D")==0){
                total_si += 1.3 * ci;
            }else if(strcmp(si, "D-")==0){
                total_si += 1.0 * ci;
            }else if(strcmp(si, "F")==0){
                total_si += 0.0;
            }else{
                total_si += 0.0;
            }
        }else{
            return 1;
        }
        
    }
    printf("%.2f", total_si/total_ci);
    return 0;
}
