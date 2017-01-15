#include <bits/stdc++.h>
using namespace std;
int main() {
	int *p, n, **dp, **s, min, t_min;
	printf("Enter the no. matrices : ");
	scanf("%d", &n);
	printf("Enter the p array :\n");
	p = new int[n+1];
	for(int i = 0 ; i < n+1 ; i++ ) {
		scanf("%d", &p[i]);
	}
	dp = new int*[n];
	s = new int*[n];
	for(int i = 0 ; i < n ; i++ ) {
		dp[i] = new int[n];
		s[i] = new int[n];
	}
	for(int i = 0 ; i < n ; i++ ) {
		dp[i][i] = 0;
	}
	for(int i = 1 ; i < n ; i++ ) {
		for(int j = 0 ; j < n-i ; j++ ) {
			min = p[j]*p[j+1]*p[j+i+1] + dp[j+1][j+i];
			for(int k = j+2 ; k <= j+i ; k++ ) {
				t_min = dp[j][k-1] + dp[k][j+i] + p[j]*p[k]*p[j+i+1];
				if(t_min < min){
					min = t_min;
					s[j][j+i] = k;
				}
			}
			dp[j][j+i] = min;
		}
	}
	printf("Min. no. of computations is : %d\n",dp[0][n-1]);
	return 0;
}