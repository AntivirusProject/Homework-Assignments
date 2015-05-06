#include <stdio.h>
int main(){

	int x, y, z;
	int a[] = {5, 4, 7, 3};
	for(x = 0; x < 4; x++){
		for(y = x + 1; y < 4; y++){
			if(a[x] > a[y]){
				z = a[x];
				a[x] = a[y];
				a[y] = z;
			}
				}
			
			}
	for(x = 0; x < 4; x++){
		printf("%d", a[x]);
		
		}
		
return 0;
}
