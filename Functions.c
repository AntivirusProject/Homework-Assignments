#include <stdio.h>
#include <math.h>
int primeNumberChecker(int);
int main(){
	
	int x;
	printf("Enter a number: ");
	scanf("%d", &x);
	primeNumberChecker(x);
	
}

int primeNumberChecker(int x){
	
	int y = sqrt(x);
	int z = 0;
	
	for(z = 1; z <= y; z++){
		if(x % z == 0){
		
		
		printf("This number is prime!");
		
		
	}
}
	
	
}
