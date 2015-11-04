#include <stdio.h>

int main(void)
{
    char last, middle;
    for (last = '1'; last <= '9'; last++) {
        for (middle = '0'; middle <= '9'; middle++) {
            printf("%c%c%c\n", last, middle, last);
        }
    }
    return 0;
}
