#include <stdio.h>
int main()
{
    int iHeight[100], iExchange = 0, i, j, k, t, n = 0;
    for (i = 0; i<100; i++)
    {
        scanf("%d", &iHeight[i]);
        n = i;
        if (i>0 && iHeight[i] <= iHeight[i - 1])
            break;
    }
    for (j = 0; j <= n; j++)
    {
        if (iHeight[j]>iHeight[n])
        {
            iExchange = iHeight[j];
            iHeight[j] = iHeight[n];
            for (k = n; k>j + 1; k--)
            {
                iHeight[k] = iHeight[k - 1];
            }
            iHeight[j + 1] = iExchange;
            break;
        }
    }
    for (t = 0; t <= n; t++)
        printf("%d\n", iHeight[t]);
    return 0;
}