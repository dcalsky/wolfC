#include <stdio.h>

int maltreated[10000];
int n, m;

void add_maltreated()
{
    int d;
    scanf("%d", &d);
    for (int i = 0; i < n; i++) {
        maltreated[i] += d;
    }
}

void multi_maltreated()
{
    int d;
    scanf("%d", &d);
    for (int i = 0; i < n; i++) {
        maltreated[i] *= d;
    }
}

void div_maltreated()
{
    int d;
    scanf("%d", &d);
    for (int i = 0; i < n; i++) {
        maltreated[i] /= d;
    }
}

void reverse_maltreated()
{
    int tmp;
    int d;
    scanf("%d", &d);
    for (int i = 0; i < n / 2; i++) {
        tmp = maltreated[n - i - 1];
        maltreated[n - i - 1] = maltreated[i];
        maltreated[i] = tmp;
    }
}

void exchange_matreated()
{
    int tmp;
    int first, second;
    scanf("%d%d", &first, &second);
    tmp = maltreated[first];
    maltreated[first] = maltreated[second];
    maltreated[second] = tmp;
}

int main(void)
{
    char command;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", maltreated + i);
    }
    while (m-- > 0) {
        command = getchar();
        if (command == 'S') {
            add_maltreated();
        } else if (command == 'M') {
            multi_maltreated();
        } else if (command == 'D') {
            div_maltreated();
        } else if (command == 'R') {
            reverse_maltreated();
        } else if (command == 'P') {
            exchange_matreated();
        } else {
            ++m;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", maltreated[i]);
    }
    return 0;
}
