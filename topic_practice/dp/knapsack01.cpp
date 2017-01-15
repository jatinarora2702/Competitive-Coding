#include <bits/stdc++.h>
#define N 1000
using namespace std;

int wt[N], v[N], dp[N][N];

int main() {
	int n, i, j, w;
	scanf("%d%d", &n, &w);
	for(i = 0 ; i < n ; i++) {
		scanf("%d%d", &wt[i], &v[i]);
	}
	for(i = 1 ; i <= w ; i++) {
		for(j = 1 ; j <= n ; j++) {
			dp[i][j] = dp[i][j-1];
			if(i >= wt[j-1]) {
				dp[i][j] = max(dp[i][j], dp[i-wt[j-1]][j-1] + v[j-1]);
			}
		}
	}
	printf("%d\n", dp[w][n]);
	return 0;
}