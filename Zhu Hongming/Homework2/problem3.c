/* not good code, and I'll change this later */
#include <stdio.h>

char res[500][300];
int nl = 0;

int main(void)
{
    scanf("%d", &nl);
    int direction;
    int current_line = 0;
    int current_col = 0;
    scanf("%d", &direction);
    for (int i = 0; i < nl - 1; i++) {
        for (int j = 0; j < nl - 1 - i; j++) {
            res[current_line][current_col++] = ' ';
        }
        res[current_line][current_col++] = '*';
        for (int j = 0; j < 2 * i - 1; j++) {
            res[current_line][current_col++] = ' ';
        }
        if (i > 0) {
            res[current_line][current_col++] = '*';
        }
        res[current_line][current_col++] = '\n';
        res[current_line++][current_col++] = '\0';
        current_col = 0;
    }
    for (int i = 0; i < 2 * nl - 1; i++) {
        res[current_line][current_col++] = '*';
    }
    res[current_line][current_col++] = '\n';
    res[current_line][current_col++] = '\0';
    if (direction) {
        for (int i = 0; i < nl; i++) {
            printf("%s", res[i]);
        }
    } else {
        for (int i = nl - 1; i >= 0; i--) {
            printf("%s", res[i]);
        }
    }
    return 0;
}
