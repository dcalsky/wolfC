#include <stdio.h>
#include <ctype.h>

char st[50];

int right(char * pt)
{
    char *ppt = pt;
    int ok = 0;
    int dotno = 0;
    if (*pt == '+' || *pt == '-') { ++pt; }
    while (isdigit(*pt)) { ++pt; }
    if (*pt == '.') { ++pt; }
    while (isdigit(*pt)) { ++pt; }
    if (ppt != pt) { ok = 1; }
    if (*(pt - 1) == '.') { ok = 0; dotno = 1; }
    if (*pt == 'e' || *pt == 'E') { ++pt; }
    if (*pt == '+' || *pt == '-') { ++pt; }
    while (isdigit(*pt)) { ++pt; }
    if (*pt) { ok = 0; }
    else if (!dotno) { ok = 1; }
    if (*(pt - 1) == 'e' || *(pt - 1) == 'E') {ok = 0; }
    return ok;
}

int main(void)
{
    scanf("%[^\n]", st);
    if (right(st)) {
        printf("true");
    } else {
        printf("false");
    }
    return 0;
}
