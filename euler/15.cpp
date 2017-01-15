#include <bits/stdc++.h>
#define N 25
using namespace std;
typedef long long int lli;
lli dp[N][N];
int main() {
	int i, j, n;
	scanf("%d", &n);
	for(j = 0 ; j < n ; j++)
		dp[0][j] = 1LL;
	for(i = 0 ; i < n ; i++)
		dp[i][0] = 1LL;
	for(i = 1 ; i < n ; i++) {
		for(j = 1 ; j < n ; j++) {
			dp[i][j] = 0LL;
			if(i-1 >= 0) {
				dp[i][j] += dp[i-1][j];
			}
			if(j-1 >= 0) {
				dp[i][j] += dp[i][j-1];
			}
		}
	}
	printf("%lld\n", dp[n-1][n-1]);
	return 0;
}