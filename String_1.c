#include <stdio.h>
int main(){ 
	
	int flag = 0;
	int i = 0;
	char a[] = "asdf";
	char b[] = "qpwo";
	for(i=0; i < 4; i++){
		if(a[i] != b[i])			
			flag =1;
			
	}
	if(flag == 0)
		printf("It does match!");
	else
		printf("It does not match!");

	return 0;
}
