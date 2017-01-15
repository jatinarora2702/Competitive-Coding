#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int n, m, x, y, *a, *b, max, k, f;
	scanf("%d%d", &n, &m);
	a = new int[n];
	for(int i = 0 ; i < n ; i++)
		a[i] = -1;
	k = 0;
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d", &x, &y);
		x--; y--;
		if(a[x] == -1 and a[y] == -1){
			a[x] = a[y] = k;
			k++;
		}
		else if(a[x] != -1){
			a[y] = a[x];
		}
		else if(a[y] != -1){
			a[x] = a[y];
		}
	}
	b = new int[n/3];
	for(int i = 0 ; i < n/3 ; i++)
		b[i] = 0;
	for(int i = 0 ; i < n ; i++){
		b[a[i]]++;
	}
	max = b[0];
	for(int i = 0 ; i < k ; i++){
		if(b[i] > max)
			max = b[i];
	}
	if(max > 3)
		printf("-1");
	else{
		for(int i = 0 ; i < n ; i++){
			if(a[i] == -1){
				for(int j = 0 ; j < n/3 ; j++){
					if(b[j] <= 2){
						a[i] = j;
						b[j]++;
						break;
					}
				}
			}
		}
		k = 0;
		f = 1;
		while(f){
			f = 0;
			for(int i = 0 ; i < n ; i++){
				if(a[i] == k){
					printf("%d ", i+1);
					f = 1;
				}
			}
			printf("\n");
			k++;
		}
	}
	return 0;
}