#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    char *item = malloc(sizeof(char) * (N + 1));
    int space = 0;
    for (int i = 0; i < N + 1; i++) {
        if ((item[i] = getchar()) == ' ') {
            space = 1;
            break;
        }
    }
    printf(space ? "YES" : "NO");
    free(item);
    return 0;
}
