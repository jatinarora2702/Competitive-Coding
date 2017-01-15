#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define N 100
using namespace std;
typedef long long int lli;
int a[N];
int main() {
	int m, n, x, f, y;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &x);
		for(int j = 0 ; j < x ; j++){
			scanf("%d", &y);
			a[y] = 1;
		}
	}
	f = 1;
	for(int i = 1 ; i <= m ; i++){
		if(a[i] == 0){
			f = 0;
			break;
		}
	}
	if(f == 0)
		printf("NO");
	else
		printf("YES");
	return 0;
}