#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 501;
int dp[2][N][N];
int a[N];
int main() {
	int n, m, b, mod, s, f;
	scanf("%d%d%d%d", &n, &m, &b, &mod);
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);
	}
	dp[0][0][0] = 1;
	for(int i = 1 ; i <= n ; i++){
		f = i & 1;
		for(int j = 0 ; j <= m ; j++){
			for(int k = 0 ; k <= b ; k++){
				dp[f][j][k] = dp[f^1][j][k];
				if(j > 0 and k >= a[i-1]){
					dp[f][j][k] += dp[f][j-1][k-a[i-1]];
					dp[f][j][k] %= mod;
				}
			}
		}
	}
	s = 0;
	for(int k = 0 ; k <= b ; k++){
		s += dp[n&1][m][k];
		s %= mod;
	}
	printf("%d", s);
	return 0;
}