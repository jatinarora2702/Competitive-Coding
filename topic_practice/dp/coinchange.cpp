#include <bits/stdc++.h>
using namespace std;
/*
// USING RECURSION NOT DP

int compute(int *s, int **dp, int m, int n) {
	if(m == 0)
		return 1;
	if(n == 0 or m < 0)
		return 0;
	return compute(s,m,n-1) + compute(s,m-s[n-1],n);
}
*/
int main() {
	int *s, m, n, k, **dp;
	printf("Enter the no. of different types of coins : ");
	scanf("%d",&n);
	printf("Enter the different denominations :\n");
	s = new int[n];
	for(int i = 0 ; i < n ; i++ ) {
		scanf("%d", &s[i]);
	}
	printf("Enter the sum : ");
	scanf("%d", &m);
	dp = new int*[m+1];
	for(int i = 0 ; i <= m ; i++ ) {
		dp[i] = new int[n+1];
	}
	for(int i = 0 ; i <= n ; i++ ) {
		dp[0][i] = 1;
	}
	for(int i = 1 ; i <= m ; i++) {
		dp[i][0] = 0;
	}
	for(int i = 1; i <= m ; i++ ) {
		for(int j = 1 ; j <= n ; j++ ) {
			dp[i][j] = dp[i][j-1] + ((i - s[j-1] >= 0) ? dp[i-s[j-1]][j] : 0);
		}
	}
	k = dp[m][n];  // k = compute(s,m,n);  // FOR RECURSION NOT DP
	printf("Total no. of ways to form this are : %d\n", k);
	return 0;
}