#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int n, *a, *b, *c, j, k;
	scanf("%d", &n);
	a = new int[n];
	b = new int[n];
	c = new int[n];
	for(int i = 0 ; i < n ; i++)
		b[i] = 0;
	for(int i = 0 ; i < n ; i++)
		c[i] = 0;
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);
		if(a[i] > n){
			c[i] = 1;
			continue;
		}
		if(b[a[i]-1] == 1)
			c[i] = 1;
		else
			b[a[i]-1] = 1;
	}
	j = 0;
	for(int i =  0 ; i < n ; i++){
		if(c[i] == 1){
			while(j < n && b[j] == 1)
				j++;
			b[j] = 1;
			c[i] = 0;
			a[i] = j+1;
		}
	}
	for(int i =  0 ; i < n ; i++)
		printf("%d ", a[i]);
	return 0;
}