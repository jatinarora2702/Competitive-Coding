#include <bits/stdc++.h>
#define PB push_back
#define N 105
#define M 10005
using namespace std;
vector < int > v[N], a[N];
int main() {
	int n, x, i, j;
	scanf("%d", &n);
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < i+1 ; j++) {
			scanf("%d", &x);
			v[i].PB(x);
		}
	}
	a[0].PB(v[0][0]);
	for(i = 1 ; i < n ; i++) {
		for(j = 0 ; j < i+1 ; j++) {
			a[i].PB(v[i][j]);
			x = 0;
			if(j-1 >= 0)
				x = max(x, a[i-1][j-1]);
			if(j < a[i-1].size())
				x = max(x, a[i-1][j]);
			a[i][j] += x; 
		}
	}
	x = 0;
	for(j = 0 ; j < a[n-1].size() ; j++) {
		x = max(x, a[n-1][j]);
	}
	printf("%d\n", x);
	return 0;
}