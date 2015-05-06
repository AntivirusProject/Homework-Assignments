#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char strAdding(char *i){
	i = (char*)realloc(i, 5);
	strcat(i, "gh");
	
	
	
	return 0;
	}



int main(){
		char *i = (char*)malloc(5);
	scanf("%s",  i);
	strAdding(i);
	
	printf("%s", i);
return 0;
}
