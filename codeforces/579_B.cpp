#include <bits/stdc++.h>
using namespace std;
int a[802][802];
int main(){
	int n, *b, *p, *pi, flag, k;
	scanf("%d", &n);
	n = 2*n;
	flag = 1;
	b = new int[n];
	p = new int[n];
	pi = new int[n];
	for(int i = 0 ; i < n ; i++)
		b[i] = -1;
	for(int i = 1 ; i < n ; i++){
		for(int j = 0 ; j < i ; j++){
			scanf("%d", &a[i][j]);
		}
	}
	while(flag != 0){
		flag = 0;
		for(int i = 0 ; i < n ; i++){
			p[i] = -1;
			pi[i] = 0;
		}
		for(int i = 0 ; i < n ; i++){
			if(b[i] == -1){
				flag = 1;
				for(int j = i+1 ; j < n ; j++){
					if(b[j] == -1){
						if(a[j][i] > pi[j]){
							p[j] = i;
							pi[j] = a[j][i];
						}
						if(a[j][i] > pi[i]){
							p[i] = j;
							pi[i] = a[j][i];
						}
					}
				}
			}
		}
		for(int i = 0 ; i < n ; i++){
			if(p[i] != -1){
				k = p[i];
				if(p[k] == i){
					b[i] = k+1;
					b[k] = i+1;
				}	
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		printf("%d ", b[i]);
	}
	return 0;
}