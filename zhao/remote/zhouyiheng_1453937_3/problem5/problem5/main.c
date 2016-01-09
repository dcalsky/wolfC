#include <stdio.h>
#include <string.h>

int main(){
	int num;
	scanf("%d", &num);
	printf("total price is $%.2f", num > 50 ? num * 5 * 0.85 : num > 30 ? num * 5 * 0.9 : num * 5);
	return 0;
}