#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int n, m, *a, **dp;
	printf("Enter the no. of possible dinominations of coins : ");
	scanf("%d", &m);
	a = new int[m];
	for(int i = 0 ; i < m ; i++){
		scanf("%d", &a[i]);
	}
	printf("Enter the no. to be made : ");
	scanf("%d", &n);
	dp = new int*[n+1];
	for(int i = 0 ; i <= n ; i++)
		dp[i] = new int[m];
	for(int j = 0 ; j < m ; j++)
		dp[0][j] = 1;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j < m ; j++){
			dp[i][j] = 0;
			if(j-1 >= 0)
				dp[i][j] += dp[i][j-1];
			if(i-a[j] >= 0)
				dp[i][j] += dp[i-a[j]][j];
		}
	}
	// for(int i=0 ; i <= n ; i++){
	// 	for(int j = 0 ; j < m ; j++)
	// 		printf("dp[%d][%d] = %d | ", i, j, dp[i][j]);
	// 	printf("\n");
	// }
	printf("ways : %d\n", dp[n][m-1]);
	return 0;
}