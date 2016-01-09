#include <stdio.h>

int main(){
	char c;
	scanf("%c", &c);

	/*  regular expression will be better */
	if(islower(c)){
		printf("lower");
	}else if(isdigit(c)){
		printf("digit");
	}else if(isupper(c)){
		printf("upper");
	}else{
		printf("white space");
	}
	return 0;
}