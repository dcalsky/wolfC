#include<stdio.h>
#include<string.h>
int main()
{
    char *p;
    char s[1000];
    gets(s);
    char sep[]=",. \();:\"‘’‘’'＇＇“”“”＂＂”?!%$1234567890";
    p=strtok(s,sep);
    printf("%s",p);
    while(	p=strtok(NULL,sep))
        printf("%s",p);
    return 0;
}