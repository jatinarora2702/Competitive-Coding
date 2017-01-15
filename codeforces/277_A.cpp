#include <iostream>
#include <stdio.h>
using namespace std;
int root(int *s, int i){
	while((s[i] != -1 and s[i] != -2)){
		i = s[i];
	}
	return i;
}
int main(){
	int n, m, k, **a, f, *b;
	scanf("%d%d", &n, &m);
	a = new int*[n];
	b = new int[m];
	f = 0;
	for(int i = 0 ; i < m ; i++)
		b[i] = -1;
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &k);
		if(k == 0)
			f++;
		a[i] = new int[k+1];
		for(int j = 0 ; j < k ; j++){
			scanf("%d", &a[i][j]);
			a[i][j]--;
		}
		a[i][k] = -1;
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; a[i][j] != -1 ; j++){
			if(j == 0){
				if(b[a[i][j]] == -1)
					b[a[i][j]] = -2;
				continue;
			}
			b[root(b,a[i][j])] = a[i][j-1];
		}		
	}
	k = 0;
	for(int i = 0 ; i < m ; i++){
		if(b[i] == -2){
			k++;
		}
	}
	if(k > 0)
		k--;
	printf("%d", k+f);
	return 0;
}