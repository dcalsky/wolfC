#include <stdio.h>

int main(){
	char type;
	float val;
	printf("celsius or fahrenheit (just enter c or f): ");
	scanf("%c", &type);
	printf("value: ");
	scanf("%f", &val);
	printf("choose the mode %c, the value is %.2f after transforming\n", type, type == 'c' ? val * 1.8 + 32 : (val -32)*5/9);
	return 0;
}