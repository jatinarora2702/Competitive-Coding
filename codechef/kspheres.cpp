#include <iostream>
#include <cstdio>
#define N 1005
#define MOD 1000000007
using namespace std;
typedef long long int lli;
int ucnt[N], lcnt[N];
lli sph[N], dp[N][N];
int main(){
	int n, m, c, x;
	lli temp;
	scanf("%d%d%d", &n, &m, &c);
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &x);
		ucnt[x]++;
	}
	for(int i = 0 ; i < m ; i++){
		scanf("%d", &x);
		lcnt[x]++;
	}
	for(int i = 1 ; i <= c ; i++){
		sph[i] = (lli)lcnt[i] * (lli)ucnt[i];
		sph[i] %= (lli)(MOD);
		dp[1][i] = dp[1][i-1] + sph[i];
		dp[1][i] %= (lli)(MOD);
		// printf("%lld ", dp[1][i]);
	}
	// printf("\n");
	for(int i = 2 ; i <= c ; i++){
		for(int j = i ; j <= c ; j++){
			dp[i][j] = dp[i][j-1] + dp[i-1][j-1] * sph[j];
			dp[i][j] %= (lli)(MOD);
		}
		printf("%lld ", dp[i][c]);
	}
	printf("0");
	return 0;
}