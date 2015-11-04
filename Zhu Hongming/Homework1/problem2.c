#include <stdio.h>

const double pi = 3.14159;

int main(void)
{
    int diameter;
    scanf("%d", &diameter);
    double radius = (double)diameter / 2.0;
    printf("%.4lf\n%.4lf", (double)diameter * pi, radius * radius * pi);
    return 0;
}
