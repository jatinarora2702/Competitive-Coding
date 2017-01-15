#include <iostream>
#include <stdio.h>
#define N 100002
using namespace std;
int main() {
	int n, k, i;
	char *a, *b, *c;
	a = new char[N];
	b = new char[N];
	c = new char[N];
	scanf("%s", a);
	scanf("%s", b);
	k = 0;
	for(i = 0 ; a[i] != '\0' ; i++){
		if(a[i] != b[i]){
			if(k % 2 == 0)
				c[i] = a[i];
			else
				c[i] = b[i];
			k++;
		}
		else
			c[i] = a[i];
	}
	c[i] = '\0';
	if(k % 2 == 0)
		printf("%s", c);
	else
		printf("impossible");
	return 0;
}