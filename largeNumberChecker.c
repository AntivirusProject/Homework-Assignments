
#include<stdio.h>
int main(){
  int a[3],i,big;
  printf("Enter 3 elements in to the array: ");
  scanf("%d %d %d", &a[0], &a[1], &a[2]);
  big=a[0];
  for(i=1; i< 3;i++){
      if(big<a[i])
           big=a[i];
  }
  printf("\nBiggest: %d",big);
  return 0;
}
