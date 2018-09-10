#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int a[N][N], dp[N][N], c[N], s[N];

int main() {
	int n, m, i, j, k, t;
	scanf("%d", &n);
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < n ; j++)
			scanf("%d", &a[i][j]);
	}
	for(i = n-1 ; i >= 0 ; i--) {
		scanf("%d", &c[i]);
		c[i]--;
	}
	for(i = 0 ; i < n ; i++)
		s[i] = 0;
	for(k = 0 ; k < n ; k++) {
		s[k] = 0;
		for(i = 0 ; i < k ; i++) {
			dp[c[k]][c[i]] = a[c[k]][c[i]];
			dp[c[i]][c[k]] = a[c[i]][c[k]];
			for(j = 0 ; j < k ; j++) {
				dp[c[k]][c[i]] = min(dp[c[k]][c[i]], dp[c[k]][c[j]] + dp[c[j]][c[i]]);
				dp[c[i]][c[k]] = min(dp[c[i]][c[k]], dp[c[j]][c[k]] + dp[c[i]][c[j]]);
			}
			s[k] += dp[c[k]][c[i]];
			s[k] += dp[c[i]][c[k]];
		}
		for(i = 0 ; i < k ; i++) {
			for(j = 0 ; j < k ; j++) {
				t = min(dp[c[i]][c[k]] + dp[c[k]][c[j]], dp[c[i]][c[k]] + dp[c[k]][c[j]]);
				dp[c[i]][c[j]] = min(dp[c[i]][c[j]], t);
				s[k] += dp[c[i]][c[j]];
			}
		}
	}
	for(i = n-1 ; i >= 0 ; i--)
		printf("%d ", s[i]);
	printf("\n");
	return 0;
}