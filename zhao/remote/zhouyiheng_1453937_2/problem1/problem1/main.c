#include <stdio.h>

int main(){
	/* (1) 7 is int data type  "7" is string data type , '7' is char data type */
	/* (2) ans == 11.0 */
	double ans = 10.0 + 2.0 / 3.0 - 2.0 * 2.0 + 1.0 / 3.0 + 4.0;
	printf("%.1f", ans);
	return 0;
}