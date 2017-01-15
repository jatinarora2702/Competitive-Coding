#include <iostream>
#include <cstdio>
#define N 4004
#define MOD 1000000007
using namespace std;
typedef long long int lli;
int dp[N][N], eq[N], C[N][N];
int main() {
	int n, s;
	lli k;
	scanf("%d", &n);
	// printf("iC0(from i=0) : ");
	for(int i = 0 ; i <= n ; i++){
		C[i][0] = 1;
		// printf("%d ", C[i][0]);
	}
	// printf("\nC[i][j] (from i=1,j=1) :\n");
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= i ; j++){
			k = (lli)C[i-1][j] + (lli)C[i-1][j-1];
			k %= (lli)MOD;
			C[i][j] = k;
			// printf("%d ", C[i][j]);
		}
		// printf("\n");
	}
	for(int i = 0 ; i <= n ; i++){
		dp[0][i] = 1;
	}
	dp[0][0] = 0;
	// printf("\ndp[i][j] (from i=1,j=1) :\n");
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= i ; j++){
			k = (lli)j * (lli)dp[i-1][j];
			k %= (lli)MOD;
			k += (lli)dp[i-1][j-1];
			k %= (lli)MOD;
			dp[i][j] = k;
			// printf("%d ", dp[i][j]);
		}
		// printf("\n");
	}
	// printf("eq :\n");
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= i ; j++){
			k = (lli)eq[i] + (lli)dp[i][j];
			k %= (lli)MOD;
			eq[i] = k;
		}
		// printf("%d ", eq[i]);
	}
	// printf("\n");
	s = 0;
	for(int i = 0 ; i < n ; i++){
		k = (lli)C[n][n-i] * (lli)eq[i];
		k %= (lli)MOD;
		k += (lli)s;
		k %= (lli)MOD;
		s = k;
	}
	k = s + 1;
	k %= (lli)MOD;
	s = k;
	printf("%d", s);
	return 0;
}