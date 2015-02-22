#include <stdio.h>
#include <string.h>

int main(){
	int i = 0;
	char a[] = "abcde";
	char b[] = "fghijk";
	int la = strlen(a);
	int lb = strlen(b);
	int lc = la+lb;
	char c[lc];
	for (i=0;i<lc;i++)
	{
		if (i<5)
			c[i] = a[i];
		else
			c[i] = b[i-la];
	}
	printf("%s",c);
	return 0;
}
