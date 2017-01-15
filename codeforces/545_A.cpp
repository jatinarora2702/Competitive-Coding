#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int n, **a, *p, k;
	scanf("%d", &n);
	a = new int*[n];
	p = new int[n];
	for(int i = 0 ; i < n ; i++)
		p[i] = 0;
	for(int i = 0 ; i < n ; i++)
		a[i] = new int[n];
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++)
			scanf("%d", &a[i][j]);
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(a[i][j] == 1)
				p[i] = 1;
			else if(a[i][j] == 2)
				p[j] = 1;
			else if(a[i][j] == 3){
				p[i] = p[j] = 1;
			}
		}
	}
	k = 0;
	for(int i = 0 ; i < n ; i++){
		if(p[i] == 0)
			k++;
	}
	printf("%d\n",k);
	for(int i = 0 ; i < n ; i++){
		if(p[i] == 0)
			printf("%d ", i+1);
	}
	return 0;
}