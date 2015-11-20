#include <stdio.h>

long long int matrix1[10000];
long long int matrix2[10000];

int main(void)
{
    int a, b, c;
    long long int res;
    scanf("%d%d%d", &a, &b, &c);
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            scanf("%lld", &matrix1[i * b + j]);
        }
    }
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%lld", &matrix2[i * c + j]);
        }
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < c; j++) {
            res = 0LL;
            for (int k = 0; k < b; k++) {
                res += matrix1[i * b + k] * matrix2[k * c + j];
            }
            printf(j < c - 1 ? "%lld " : "%lld", res);
        }
        if (i < a - 1) { printf("\n"); }
    }
    return 0;
}
