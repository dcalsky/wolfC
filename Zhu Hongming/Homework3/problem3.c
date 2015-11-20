/* 2015.11.3 1:03
 * by ecnelises
 */
#include <stdio.h>

int heights[100];

int main(void)
{
    int count = 0;
    while (scanf("%d", heights + count++) == 1);
    --count;
    int pheight = heights[count - 1];
    int i, place = -1;
    for (i = 0; i < count - 1; i++) {
        if (pheight < heights[i]) {
            place = i;
            break;
        }
    }
    for (i = 0; i < count - 1; i++) {
        if (i == place) {
            printf("%d\n", pheight);
        }
        printf("%d\n", heights[i]);
    }
    if (place == -1) {
        printf("%d", pheight);
    }
    return 0;
}
