#include <bits/stdc++.h>
#define N 502
typedef long long int lli;
typedef long double ld;
bool dp[N][N][N];
int c[N];
int main() {
	int n, m, i, j, k, cnt;
	bool f;
	scanf("%d%d", &n, &m);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &c[i]);
	}
	dp[0][0][0] = true;
	for(i = 1 ; i <= n ; i++) {
		dp[i][0][0] = true;
		for(j = 1 ; j <= m ; j++) {
			f = false;
			for(k = 1 ; k <= j ; k++) {
				dp[i][j][k] = dp[i-1][j][k];
				if(j >= c[i-1]) {
					dp[i][j][k] = dp[i][j][k] || dp[i-1][j-c[i-1]][k];
					if(k >= c[i-1]) {
						dp[i][j][k] = dp[i][j][k] || dp[i-1][j-c[i-1]][k-c[i-1]];
					}
				}
				f = (dp[i][j][k] == true) ? true : f;
			}
			dp[i][j][0] = f;
		}
	}
	cnt = 0;
	for(i = 0 ; i <= m ; i++) {
		if(dp[n][m][i] == true) {
			cnt++;
		}
	}
	printf("%d\n", cnt);
	for(i = 0 ; i <= m ; i++) {
		if(dp[n][m][i] == true) {
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}