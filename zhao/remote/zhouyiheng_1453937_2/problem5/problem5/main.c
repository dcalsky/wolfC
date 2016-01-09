#include <stdio.h>

int main(){
	float cm;
	scanf("%f", &cm);
	printf("cm: %.2f cm\n", cm);
	printf("dm: %.2f dm\n", cm/10);
	printf("m: %.2f m\n", cm/100);
	printf("km: %.2f km\n", cm/1000);
	return 0;
}