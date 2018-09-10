#include <bits/stdc++.h>
#define PB push_back

using namespace std;

const int MOD = 1e8;

int dp[105][105][15][2];

int main() {
	int n1, n2, k1, k2, i, j, k, s;
	scanf("%d%d%d%d", &n1, &n2, &k1, &k2);
	for(i = 1 ; i <= k1 ; i++)
		dp[i][0][i][0] = 1;
	for(j = 1 ; j <= k2 ; j++)
		dp[0][j][j][1] = 1;
	for(i = 1 ; i <= n1 ; i++) {
		for(j = 1 ; j <= n2 ; j++) {
			for(k = 1 ; k <= k1 ; k++) {
				dp[i][j][1][1] += dp[i][j-1][k][0];
				dp[i][j][1][1] %= MOD;
			}
			for(k = 1 ; k <= k2 ; k++) {
				dp[i][j][1][0] += dp[i-1][j][k][1];
				dp[i][j][1][0] %= MOD;
			}
			for(k = 2 ; k <= k1 ; k++)
				dp[i][j][k][0] = dp[i-1][j][k-1][0];
			for(k = 2 ; k <= k2 ; k++)
				dp[i][j][k][1] = dp[i][j-1][k-1][1];
		}
	}
	s = 0;
	for(k = 1 ; k <= k1 ; k++) {
		s += dp[n1][n2][k][0];
		s %= MOD;
	}
	for(k = 1 ; k <= k2 ; k++) {
		s += dp[n1][n2][k][1];
		s %= MOD;
	}
	printf("%d\n", s);
	return 0;
}