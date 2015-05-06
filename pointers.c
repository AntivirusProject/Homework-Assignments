#include <stdio.h>
#include <string.h>

char printing(char *a);

int main(){
	char a[100];
	scanf("%s", a);

	printing(a);
	
	return 0;
	}

char printing(char *a){
	
	
	printf("%s", a);
	
	
	return 0;
	}

