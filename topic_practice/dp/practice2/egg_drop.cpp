#include <iostream>
#include <cstdio>
#define INF 1000000000
using namespace std;
int min_drops(int n, int k, int **dp){
	if(n == -1)
		return 0;
	if(k == 0){
		dp[n][k] = n+1;
		return dp[n][k];
	}
	if(dp[n][k] != -1)
		return dp[n][k];
	dp[n][k] = INF;
	for(int i = 0 ; i <= n ; i++){
		dp[n][k] = min(dp[n][k], max(min_drops(i-1, k-1, dp), min_drops(n-i-1, k, dp)) + 1);
	}
	return dp[n][k];
}
int main() {
	int n, k, cnt, **dp;
	scanf("%d%d", &n, &k);
	dp = new int*[n];
	for(int i = 0 ; i < n ; i++)
		dp[i] = new int[k];
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < k ; j++)
			dp[i][j] = -1;
	n--;
	k--;
	cnt = min_drops(n, k, dp);
	printf("%d", cnt);
}