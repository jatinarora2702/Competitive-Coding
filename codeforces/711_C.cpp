#include <bits/stdc++.h>
#define N 105
using namespace std;

typedef long long int lli;

const lli LINF=  1e18 + 7LL;

lli dp[N][N][N];
int c[N], p[N][N];
int main() {
	int n, m, k1, k, i, j, l;
	lli minm;
	scanf("%d%d%d", &n, &m, &k1);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &c[i]);
	}
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < m ; j++) {
			scanf("%d", &p[i][j]);
		}
	}
	for(i = 0 ; i <= n ; i++) {
		for(j = i+1 ; j <= m ; j++) {
			for(k = 0 ; k <= m ; k++) {
				dp[i][j][k] = LINF;
			}
		}
	}
	for(i = 1 ; i <= n ; i++) {
		for(k = 0 ; k <= m ; k++) {
			dp[i][0][k] = LINF;
		}
	}
	for(i = 1 ; i <= n ; i++) {
		for(j = 1 ; j <= k1 ; j++) {
			for(k = 1 ; k <= m ; k++) {
				if(j > i) {
					dp[i][j][k] = LINF;
					continue;
				}
				if(c[i-1] == 0) {
					minm = LINF;
					for(l = 1 ; l <= m ; l++) {
						if(l != k)
							minm = min(minm, dp[i-1][j-1][l]);
					}
					if(i == 1 && j == 1) {
						minm = 0;
					}
					// cout << "minm=" << minm << endl;
					dp[i][j][k] = min(dp[i-1][j][k], minm) + p[i-1][k-1];
				}
				else if(c[i-1] == k) {
					minm = LINF;
					for(l = 1 ; l <= m ; l++) {
						if(l != k)
							minm = min(minm, dp[i-1][j-1][l]);
					}
					if(i == 1 && j == 1) {
						minm = 0;
					}
					// cout << "1minm=" << minm << endl;
					dp[i][j][k] = min(dp[i-1][j][k], minm);
				}
				else {
					dp[i][j][k] = LINF;
				}
				// cout << "i=" << i << " j=" << j << " k=" << k << " got: " << dp[i][j][j] << endl;
			}
		}
	}
	minm = LINF;
	for(i = 1 ; i <= m ; i++) {
		minm = min(minm, dp[n][k1][i]);
	}
	if(minm == LINF) {
		minm = -1;
	}
	cout << minm << endl;
}