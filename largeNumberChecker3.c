#include <stdio.h>

int main(){

	int a[5],i,n;
	printf("Enter 3 elements in to the array: ");
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	
	for(i = 1; i < n; i++){
		if(a[0] < a[i])
			a[0] = a[i];
		
		}
		printf("The largest number is %d", a[0]);
		return 0;
	
	}
