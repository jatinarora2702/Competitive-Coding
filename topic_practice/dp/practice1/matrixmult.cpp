#include <iostream>
#include <cstdio>
#define N 100
using namespace std;
int p[N], dp[N][N];
int main() {
	int n;
	printf("Enter the no. of matrices: ");
	scanf("%d", &n);
	printf("Enter the orders array: ");
	for(int i = 0 ; i <= n ; i++)
		scanf("%d", &p[i]);
	for(int i = 0 ; i < n ; i++)
		dp[i][i] = 0;
	for(int i = 1 ; i < n ; i++){
		for(int j = 0 ; j < n-i ; j++){
			dp[j][j+i] = dp[j][j] + dp[j+1][j+i] + p[j]*p[j+1]*p[j+i+1];
			for(int k = 1 ; k < i ; k++)
				dp[j][j+i] = min(dp[j][j+i], dp[j][j+k] + dp[j+k+1][j+i] + p[j]*p[j+k+1]*p[j+i+1]);
		}
	}
	printf("No. of multiplications is: %d\n", dp[0][n-1]);
	return 0;
}