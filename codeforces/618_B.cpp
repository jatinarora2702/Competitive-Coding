#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define N 60
using namespace std;

typedef long long int lli;
typedef pair < int, int > pii;

int a[N][N], b[N], c[N], d[N], ans[N];
int main(){
	int n, k;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++)
			scanf("%d", &a[i][j]);
	}
	for(int i = 0 ; i < n ; i++){
		k = 0;
		for(int j = 0 ; j < n ; j++){
			b[j] = max(b[j], a[i][j]);
			k = max(k, a[i][j]);
		}
		b[i] = max(b[i], k);
	}
	for(int i = 0 ; i < n ; i++){
		if(c[b[i]] == 0){
			c[b[i]] = 1;
			d[i] = b[i];
		}
		else{
			k = b[i];
			while(c[k] == 1 && k <= n){
				k++;
			}
			d[i] = k;
		}
	}
	for(int i = 0 ; i < n ; i++){
		printf("%d ", d[i]);
	}
	printf("\n");
	return 0;
}