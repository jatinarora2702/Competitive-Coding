#include <bits/stdc++.h>
#define N 55
using namespace std;
int h[N], v[N];
int main(){
	int n, k, x, y;		
	scanf("%d", &n);
	k = n * n;
	for(int i = 0 ; i < k ; i++){
		scanf("%d%d", &x, &y);
		if(h[x] == 0 && v[y] == 0){
			printf("%d", i+1);
			h[x] = 1;
			v[y] = 1;
		}
	}
	return 0;
}