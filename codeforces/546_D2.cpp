#include <iostream>
#include <stdio.h>
#define N 5000001
using namespace std;
int main() {
	int *a, *b, t, a1, b1, cnt;
	a = new int[N];
	b = new int[N];
	a[0] = 1;
	a[1] = 1;
	for(int i = 2 ; i < N ; i++)
		a[i] = 1;
	b[0] = 0;
	b[1] = 0;
	for(int i = 2 ; i < N ; i++){
		if(a[i] == 1){
			for(int j = i ; j < N ; j+=i){
				if(a[j] == 1)
					a[j] = i;
			}
		}
	}
	for(int i = 2 ; i < N ; i++){
		if(a[i] == i)
			b[i] = 1;
		else
			b[i] = b[i/a[i]] + 1;
	}
	for(int i = 1 ; i < N ; i++)
		b[i] = b[i] + b[i-1];
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &a1, &b1);
		printf("%d\n",b[a1]-b[b1]);
	}
	return 0;
}