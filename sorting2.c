#include  <stdio.h>

int main(){
	int	a[] = {9,7,2,1,4,5,3,6,8};
	int i, j, k, min, pos;
	
	
	for(k = 0; k < 9; k++){
		min = a[k];
	for(i = k + 1; i < 9; i++){
		
		if(a[i] < min){
			min = a[i];
			
			pos = i;
			
			}
		
	 }
	j = a[k];
	a[k] = a[pos];
	 a[pos] = j;}
	 
	
	for(k = 0; k < 9; k++){
		
	printf("%d", a[i]);
		}
	

return 0;
}
