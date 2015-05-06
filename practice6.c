#include <stdio.h>

int adding(int a, int b){
	int c = a + b;
	
	
	return c;
	}




int main(){
	int a = 7;
	int b = 3;

	adding(a, b);
	
	int c = adding(a,b);
	
	printf("%d", c);
	
	return 0;
	}
