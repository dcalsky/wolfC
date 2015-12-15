//
//  main.c
//  problem1
//
//  Created by Dcalsky on 15/11/25.
//  Copyright © 2015年 Dcalsky. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i, j, m, n, i1, j1;
    int X = 0, Y = 0;
    char maze[101][101], d, actions[101];
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; ++i){
        for(j = 0; j < m; ++j){
            scanf(" %c", &maze[i][j]);
            if(maze[i][j] == 'S'){
                Y = i;
                X = j;
            }
        }
    }
    i = 0;
    while (scanf(" %c", &d) != EOF) {
        actions[i] = d;
        ++i;
    }
    for (j = 0; j < i; ++j) {
        switch (actions[j]) {
            
            case 'S':
                if(maze[Y + 1][X] == '.'){
                    maze[Y + 1][X] = 'S';
                    maze[Y][X] = '.';
                    Y = Y + 1;
                    X = X;
                }
                break;
            case 'N':
                if(maze[Y - 1][X] == '.'){
                    maze[Y - 1][X] = 'S';
                    maze[Y][X] = '.';
                    Y = Y - 1;
                    X = X;
                }
                break;
            case 'W':
                if(maze[Y][X - 1] == '.'){
                    maze[Y][X - 1] = 'S';
                    maze[Y][X] = '.';
                    Y = Y;
                    X = X - 1;
                }
                break;
            case 'E':
                if(maze[Y][X + 1] == '.'){
                    maze[Y][X + 1] = 'S';
                    maze[Y][X] = '.';
                    Y = Y;
                    X = X + 1;
                }
                break;
            default:
                printf("Error Direction!\n");
                break;
        }
        for(i1 = 0; i1 < n; ++i1){
            for(j1 = 0; j1 < m; ++j1){
                printf("%c", maze[i1][j1]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}