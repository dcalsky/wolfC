#include <stdio.h>

int permutation(int src[], int n)
{
    int pos1 = -1, pos2 = 0;
    int tmp;
    for (int i = n - 1; i > 0; i--) {
        if (src[i] > src[i - 1]) {
            pos1 = i - 1;
            break;
        }
    }
    if (pos1 == -1) {
        return 0;
    }
    for (int i = pos1 + 1; i < n; i++) {
        if (src[i] > src[pos1]) {
            pos2 = i;
        }
    }
    
    tmp = src[pos1];
    src[pos1] = src[pos2];
    src[pos2] = tmp;
    
    for (int i = pos1 + 1; i < pos1 + 1 + (n - pos1 - 1) / 2; i++) {
        tmp = src[i];
        src[i] = src[n - i + pos1];
        src[n - i + pos1] = tmp;
    }
    
    return 1;
}

int main(void)
{
    int src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int num;
    scanf("%d", &num);
    if (num == 0) {
        return 0;
    }
    do {
        for (int i = 0; i < num - 1; i++) {
            printf("%d ", src[i]);
        }
        printf("%d\n", src[num - 1]);
    } while (permutation(src, num));
}
