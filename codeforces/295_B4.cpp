#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 501;

ll a[N][N], c[N], s[N];

int main() {
	int n, i, j, k;
	scanf("%d", &n);
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < n ; j++)
			scanf("%d", &a[i][j]);
	}
	for(i = n-1 ; i >= 0 ; i--) {
		scanf("%d", &c[i]);
		c[i]--;
	}
	for(k = 0 ; k < n ; k++) {
		for(i = 0 ; i < n ; i++) {
			for(j = 0 ; j < n ; j++)
				a[i][j] = min(a[i][j], a[i][c[k]] + a[c[k]][j]);
		}
		for(i = 0 ; i <= k ; i++) {
			for(j = 0 ; j <= k ; j++)
				s[k] += a[c[i]][c[j]];
		}
	}
	for(i = n-1 ; i >= 0 ; i--)
		printf("%lld ", s[i]);
	printf("\n");
	return 0;
}