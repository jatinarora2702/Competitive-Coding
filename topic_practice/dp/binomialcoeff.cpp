#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int **dp, n, k;
	printf("n = ");
	scanf("%d",&n);
	printf("k = ");
	scanf("%d",&k);
	if(k == 0 or k == n)
		printf("nCk = 1\n");
	else if(k == 1 or k == n-1)
		printf("nCk = %d\n",n);
	else if(k > n or k < 0)
		printf("Not Possible\n");
	else {
		dp = new int*[n];
		for(int i = 0 ; i < n ; i++ ) {
			dp[i] = new int[i+2];
		}
		for(int i = 0 ; i < n ; i++ ) {
			dp[i][0] = 1;
			dp[i][1] = i+1;
			dp[i][i+1] = 1;
			dp[i][i] = i+1;
		}
		for(int i = 1 ; i < n ; i++ ) {
			int f = 2, l = i-1;
			while(f <= l) {
				if(f > k)
					break;
				dp[i][f] = dp[i-1][f] + dp[i-1][f-1];
				dp[i][l] = dp[i-1][l] + dp[i-1][l-1];
				f++;
				l--;
			}
		}
		for(int i = 0 ; i < n ; i++) {
			for(int j = 0 ; j <= i+1 ; j++ ) {
				printf("%dC%d = %d  ",i+1,j,dp[i][j]);
			}
			printf("\n");
		}
		printf("nCk = %d\n",dp[n-1][k]);
	}
	return 0;
}