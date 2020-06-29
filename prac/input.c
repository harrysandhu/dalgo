#include <stdio.h>


int main(void){
	int c;
	while((c = getchar()) != EOF){
		if(c == '_'){goto end;}
		putchar(c);
	}
	end:
	return 0;

}