#include <stdio.h>

unsigned fibo(unsigned n)
{
    if (n == 1 || n == 2) {
        return 1;
    } else {
        return fibo(n - 1) + fibo(n - 2);
    }
}

int main(void)
{
    unsigned n;
    scanf("%u", &n);
    printf("%u", fibo(n));
    return 0;
}
