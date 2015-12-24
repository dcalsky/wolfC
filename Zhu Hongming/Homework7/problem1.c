#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

struct list {
    int v;
    struct list *last;
    struct list *next;
};

int main(void)
{
    int num_of_command;
    char command[10];
    int command_pos, command_data;
    struct list *head = NULL, *tail = NULL;
    int length = 0;
    scanf("%d", &num_of_command);
    for (int o = 0; o < num_of_command; ++o) {
        scanf("%s", command);
        if (!strcmp(command, "APPEND")) {
            scanf("%d", &command_data);
            if (head == NULL) {
                head = malloc(sizeof(struct list));
                head->v = command_data;
                tail = head;
                tail->last = NULL;
                tail->next = NULL;
            } else {
                tail->next = malloc(sizeof(struct list));
                tail->next->last = tail;
                tail = tail->next;
                tail->v = command_data;
                tail->next = NULL;
            }
            ++length;
        } else if (!strcmp(command, "INSERT")) {
            scanf("%d %d", &command_pos, &command_data);
            if (command_pos >= 0 && command_pos < length) {
                struct list *current = head;
                struct list *pre = NULL;
                for (int i = 0; i < command_pos; ++i) {
                    pre = current;
                    current = current->next;
                }
                current = malloc(sizeof(struct list));
                current->v = command_data;
                current->last = pre;
                if (pre != NULL) {
                    if (pre->next != NULL) {
                        pre->next->last = current;
                    }
                    current->next = pre->next;
                    pre->next = current;
                }
                if (command_pos == 0) {
                    current->next = head;
                    head->last = current;
                    head = current;
                } else if (command_pos == length - 1) {
                    tail = current->next;
                    assert(tail != NULL);
                }
                ++length;
            } else if (command_pos == length) {
                if (head == NULL) {
                    head = malloc(sizeof(struct list));
                    head->v = command_data;
                    tail = head;
                    tail->last = NULL;
                    tail->next = NULL;
                } else {
                    tail->next = malloc(sizeof(struct list));
                    tail->next->last = tail;
                    tail = tail->next;
                    tail->v = command_data;
                    tail->next = NULL;
                }
                ++length;
            }
        } else if (!strcmp(command, "DELETE")) {
            scanf("%d", &command_pos);
            if (command_pos >= 0 && command_pos < length) {
                struct list *current = head;
                for (int i = 0; i < command_pos; ++i) {
                    current = current->next;
                }
                if (current->last != NULL) {
                    current->last->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next != NULL) {
                    current->next->last = current->last;
                } else {
                    tail = current->last;
                }
                free(current);
                --length;
            }
        } else if (!strcmp(command, "GET")) {
            scanf("%d", &command_pos);
            if (command_pos < 0 || command_pos >= length) {
                printf("-1\n");
            } else {
                struct list *current = head;
                for (int i = 0; i < command_pos; ++i) {
                    current = current->next;
                }
                printf("%d\n", current->v);
            }
        } else if (!strcmp(command, "CLEAR")) {
            struct list *current = head;
            struct list *nt;
            for (int i = 0; i < length; ++i) {
                nt = current->next;
                free(current);
                current = nt;
            }
            length = 0;
            head = tail = NULL;
        }
    }
    struct list *current = head;
    struct list *nt;
    for (int i = 0; i < length; ++i) {
        nt = current->next;
        free(current);
        current = nt;
    }
    return 0;
}
