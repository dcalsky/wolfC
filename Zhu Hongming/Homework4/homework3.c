#include <stdio.h>

#define lcm(a,b) ((a)*(b)/gcd(a,b))

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    return b == 0ULL? a : gcd(b, a % b);
}

int main(void)
{
    unsigned long long a, b;
    scanf("%llu%llu", &a, &b);
    printf("%llu\n%llu", gcd(a, b), lcm(a, b));
    return 0;
}
