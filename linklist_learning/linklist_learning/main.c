//
//  main.c
//  linklist_learning
//
//  Created by Dcalsky on 15/11/29.
//  Copyright © 2015年 Dcalsky. All rights reserved.
//

#include "main.h"

typedef struct Node {
    int data;
    struct Node *next;
} *node;

int main(){
    int num;
    node head, p, p1;
    p = head = (node)malloc(sizeof(struct Node));
    while (scanf("%d", &num) != EOF) {
        p->data = num;
        p1 = malloc(sizeof(node));
        p->next = p1;
        p = p1;
    }
    p = head;
    while (p->next != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    return 0;
}