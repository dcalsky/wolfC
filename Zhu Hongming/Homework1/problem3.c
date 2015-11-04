/* you should know more about library functions */
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main(void)
{
    int sides[3];
    scanf("%d %d %d", sides, sides + 1, sides + 2);
    qsort(sides, 3, sizeof(int), cmp);
    if (sides[0] + sides[1] > sides[2] && sides[2] - sides[1] < sides[0]) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}
