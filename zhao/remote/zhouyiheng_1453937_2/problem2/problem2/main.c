#include <stdio.h>
#define squared1(x) x*x
#define squared2(x) (x*x)
#define squared3(x) (x)*(x)
#define squared4(x) ((x)*(x)) 
#define MESSAGE = "Happy National Day!"
int main(void){
	double ans1 = 18.0 / squared1( 2 + 1);
	double ans2 = 18.0 / squared2( 2 + 1);
	double ans3 = 18.0 / squared3( 2 + 1);
	double ans4 = 18.0 / squared4( 2 + 1);

	printf("%.1f\n", ans1);  //output: 12.0
	printf("%.1f\n", ans2);  //output: 3.6
	printf("%.1f\n", ans3);  //output: 18.0
	printf("%.1f\n", ans4);  //output: 2.0
puts(MESSAGE);
	return 0;
}