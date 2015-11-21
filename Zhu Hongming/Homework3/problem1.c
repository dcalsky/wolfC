#include <stdio.h>

void swap(int * a, int * b)
{
    int tmp;
    tmp = *a;
    *a = (*b);
    *b = tmp;
}

int main(void)
{
    int x, y;
    scanf("%d %d", &x, &y);
    swap(&x, &y);
    printf("%d %d", x, y);
    /*
     * I don't use the method using XOR (^)
     * It's just 'seems-smart'
     * The method is not faster
     * Nor more comprehensible than this
     * That's it
     * Good night
     */
    return 0;
}
