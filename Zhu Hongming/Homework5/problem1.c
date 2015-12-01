#include <stdio.h>
#include <ctype.h>

#define isvalid(x) (x == '#' || x == 'S' || x == '.')
#define iscommand(x) (x == 'W' || x == 'E' || x == 'S' || x == 'N')

int puzzle[100][100];

int main(void)
{
    int n = 0, m = 0;
    char status;
    char move;
    int maox = -1, maoy = -1;
    int i = 0, j = 0;
    while (isdigit(status = getchar())) {
        n = n * 10 + (status - '0');
    }
    while (!isdigit(status)) { status = getchar(); }
    while (isdigit(status)) {
        m = m * 10 + (status - '0');
        status = getchar();
    }
    while (i != n && j != m) {
        status = getchar();
        if (!isvalid(status)) { continue; }
        if (status == 'S') {
            maox = j;
            maoy = i;
        }
        puzzle[i][j++] = status;
        if (j == m) {
            ++i;
            j = 0;
        }
    }
    while ((status = getchar()) != EOF) {
        if (!iscommand(status)) { continue; }
        if (status == 'E') {
            if (maox != m - 1) {
                if (puzzle[maoy][maox+1] == '#') {
                } else {
                    puzzle[maoy][maox+1] = 'S';
                    puzzle[maoy][maox] = '.';
                    maox++;
                }
            }
        } else if (status == 'W') {
            if (maox != 0) {
                if (puzzle[maoy][maox-1] == '#') {
                } else {
                    puzzle[maoy][maox-1] = 'S';
                    puzzle[maoy][maox] = '.';
                    maox--;
                }
            }
        } else if (status == 'S') {
            if (maoy != n - 1) {
                if (puzzle[maoy+1][maox] == '#') {
                } else {
                    puzzle[maoy+1][maox] = 'S';
                    puzzle[maoy][maox] = '.';
                    maoy++;
                }
            }
        } else if (status == 'N') {
            if (maoy != 0) {
                if (puzzle[maoy-1][maox] == '#') {
                } else {
                    puzzle[maoy-1][maox] = 'S';
                    puzzle[maoy][maox] = '.';
                    maoy--;
                }
            }
        } else {
            continue;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%c", puzzle[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
