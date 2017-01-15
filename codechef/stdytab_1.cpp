#include <iostream>
#include <cstdio>
#include <cmath>
#define N 2001
#define MOD 1000000000
using namespace std;
typedef long long int lli;
int dp[N][N], val[2*N][N];
lli t1;
int main() {
	int t, n, m;
	for(int j = 0 ; j < N ; j++)
		val[j][0] = 1;
	for(int i = 1 ; i < 2*N ; i++){
		int k = min(i, N);
		for(int j = 1 ; j <= k ; j++){
			t1 = val[i-1][j] + val[i-1][j-1];
			t1 %= (lli)(MOD);
			val[i][j] = t1;
		}
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);	
		for(int j = 0 ; j <= m ; j++)
			dp[0][j] = 1;
		for(int i = 1 ; i <= n ; i++){
			for(int j = 0 ; j <= m ; j++){
				t1 = (lli)dp[i-1][j] * (lli)val[m+j-1][j];
				t1 %= (lli)(MOD);
				if(j-1 >= 0){
					t1 += (lli)dp[i][j-1];
					t1 %= (lli)(MOD);
				}
				dp[i][j] = t1;
			}
		}
		printf("%d\n", dp[n][m]);
	}
	return 0;
}