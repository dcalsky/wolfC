
/* (1)
worry: 
#include < stdio.h>; 

corret: 
#include <stdio.h>;  

reason: spare space. */

/* (2)
worry: 
	#int function (void arg1)
	{
		Return arg1-1;
	}  
corret:  
	#int function (int arg1)
	{
		return arg1-1;
	}  
reason:
1. 'return'  should be lowercase,
2. arg1 as the parma should be int data type in here.
*/

/* (3)
worry:
#define MESSAGE = ¡°Happy National Day!¡±
puts(MESSAGE);

corret:  
#define MESSAGE "Happy National Day!"
puts(MESSAGE);

reason: 
1. spare '=',
2. ' " ' should be lowercase.
*/

#include <stdio.h>

int main(){
	printf("C");
	return 0;
}