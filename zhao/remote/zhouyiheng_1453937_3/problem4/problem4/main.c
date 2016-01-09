#include <stdio.h>
#include <string.h>

int main(){
	int month, year, day;
	char postfix[2][2] = {"th"};
	const char MONTH[12][10] = {"Jan.", "Feb.", "Mar.", "Apr.", "May.", "June.", "July.", "Aug.", "Sept.", "Oct.", "Nov.", "Dec."};

	scanf("%d %d %d", &day, &month, &year);
	switch(day){
		case 1:
		case 21: 
				strcpy(postfix[0], "st");
				break;
		case 2:
		case 22:
				strcpy(postfix[0], "nd");
				break;
		case 3:
		case 23:
				strcpy(postfix[0], "rd");
				break;
	}
	printf("%s %d%s %d", MONTH[month - 1], day, postfix[0], year );
	return 0;
}