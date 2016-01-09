#include<stdio.h>
#include <limits>

int main()
{
	//char, unsigned char, short, int, unsigned int, unsigned long, float 

	printf("char: %d\t%d\t%d\n", CHAR_MAX, CHAR_MIN, sizeof(char));
	printf("unsigned char: %d\t%d\t%d\n", CHAR_MAX, CHAR_MIN, sizeof(unsigned char));
	printf("short: %d\t%d\t%d\n", SHRT_MAX, SHRT_MIN, sizeof(short));
	printf("int: %d\t%d\t%d\n", INT_MAX, INT_MIN, sizeof(int));
	printf("unsigned int: %u\t%u\t%d\n", UINT_MAX, 0, sizeof(unsigned int));
	printf("unsigned long: %e\t%d\t%d\n", ULONG_MAX, 0, sizeof(unsigned long));
	printf("float: %u\t%u\t%d\n", FLT_MAX, FLT_MIN, sizeof(float));
    return 0;
}