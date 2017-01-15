#include <bits/stdc++.h>
#define N 105
using namespace std;

int a[N], dp[N][N];

void initdp(int sum, int m) {
	int i, j;
	for(i = 0 ; i <= sum ; i++) {
		for(j = 0 ; j < m ; j++) {
			dp[i][j] = -1;
		}
	}
}

int check(int sum, int m) {
	if(m <= 0 || sum < 0) {
		return 0;
	}
	if(dp[sum][m-1] == -1) {
		if(sum == 0) {
			dp[sum][m-1] = 1;
		}
		else if(m == 1) {
			if(sum == a[0]) {
				dp[sum][0] = 1;
			}
			else {
				dp[sum][0] = 0;
			}
		}
		else {
			dp[sum][m-1] = check(sum, m-1);
			dp[sum][m-1] |= check(sum-a[m-1], m-1);
		}
	}
	return dp[sum][m-1];
}

int main() {
	int n, i, m;
	scanf("%d%d", &n, &m);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
	}
	initdp(m, n);
	if(check(m, n)) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
	return 0;
}