#include <bits/stdc++.h>
using namespace std;
int min(int a, int b, int c, char& d) {
	if(a < b) {
		if(a < c) {
			d = 'd';
			return a;
		}
		else {
			d = 'u';
			return c;
		}
	}
	else {
		if(b < c) {
			d = 'l';
			return b;
		}
		else {
			d = 'u';
			return c;
		}
	}
}
int main() {
	int **a, m, n, **dp;
	char c, **s;
	printf("Enter the no. of rows in the matrix : ");
	scanf("%d", &m);
	printf("Enter the no. of columns in the matrix : ");
	scanf("%d", &n);
	a = new int*[m];
	for(int i = 0 ; i < m ; i++ ) {
		a[i] = new int[n];
	}
	printf("Enter the cost matrix :\n");
	for(int i = 0 ; i < m ; i++ ) {
		for(int j = 0 ; j < n ; j++ ) {
			scanf("%d", &a[i][j]);
		}
	}
	dp = new int*[m];
	s = new char*[m];
	for(int i = 0 ; i < m ; i++ ) {
		dp[i] = new int[n];
		s[i] = new char[n];
	}
	dp[0][0] = a[0][0];
	s[0][0] = 'k';
	for(int i = 1 ; i < n ; i++ ) {
		dp[0][i] = dp[0][i-1] + a[0][i];
		s[0][i] = 'l';
	}
	for(int i = 1 ; i < m ; i++ ) {
		dp[i][0] = dp[i-1][0] + a[i][0];
		s[i][0] = 'u';
	}
	for(int  i = 1 ; i < m ; i++ ) {
		for(int j = 1 ; j < n ; j++ ) {
			dp[i][j] = a[i][j] + min(dp[i-1][j-1],dp[i][j-1],dp[i-1][j],s[i][j]);
		}
	}
	printf("Min. cost is : %d\n",dp[m-1][n-1]);
	printf("dp matrix :\n");
	for(int i = 0 ; i < m ; i++ ) {
		for(int j = 0 ; j < n ; j++ ) {
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
	printf("\ns matrix :\n");
	for(int i = 0 ; i < m ; i++ ) {
		for(int j = 0 ; j < n ; j++ ) {
			printf("%c ",s[i][j]);
		}
		printf("\n");
	}
}