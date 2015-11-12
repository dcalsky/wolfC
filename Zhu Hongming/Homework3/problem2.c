#include <stdio.h>

int days[] = {
    31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31
}; // we set feburary as 28 days

int days_of_feb(int year)
{
    if (year % 100 == 0) {
        if (year % 400 == 0) {
            return 29;
        } else {
            return 28;
        }
    } else {
        if (year % 4 == 0) {
            return 29;
        } else {
            return 28;
        }
    }
    return 28; //default
}

int main(void)
{
    int y, m, d;
    int pdays = 0;
    int i;
    scanf("%d %d %d", &y, &m, &d);
    days[1] = days_of_feb(y);
    for (i = 0; i < m - 1; i++) {
        pdays += days[i];
    }
    printf("%d", d + pdays);
    return 0;
}
