#include <stdio.h>
#include <stdlib.h>
int **a;
int row(int c, int r, int i, int b)
{
    return !a[c ? i : b][c ? b : i]
        && ((i == r - 1) ? 1 : row(c, r, i + 1, b));
}

int find(int r, int i)
{
    return (i == r - 1) ? a[i][i] == 1 : row(0, r, i + 1, i)
        && row(1, r, i + 1, i) && find(r, i + 1);
}

int main(void)
{
    int m, n;
    scanf("%d%d", &m, &n);
    a = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        a[i] = malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf(((m == n) ? find(n, 0) : 0) ? "YES" : "NO");
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
}
