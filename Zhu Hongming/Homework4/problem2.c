#include <stdio.h>

char uppersentence[210];
char lowersentence[110];

char * qcf_strcat ( char * destination, const char * source )
{
    char * dst_start = destination;

    if (*destination) {
        while (*(++destination) != '\n');
    }
    while ((*(destination++) = *(source++)) != '\0');

    return dst_start;
}

int main(void)
{
    fgets(uppersentence, 110, stdin);
    fgets(lowersentence, 110, stdin);
    printf("%s", qcf_strcat(uppersentence, lowersentence));
    return 0;
}
