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
		dp[1][i] = sph[i];
		printf("%lld ", dp[1][i]);
	}
	printf("\n");
	for(int i = 2 ; i <= c ; i++){
		temp = 0;
		for(int j = 1 ; j <= c ; j++){
			dp[i][j] = 0;
			if(sph[j] != 0){
				for(int k = i-1 ; k < j ; k++){
					dp[i][j] += dp[i-1][k];
					dp[i][j] %= (lli)(MOD);
				}
				dp[i][j] *= sph[j];
				dp[i][j] %= (lli)(MOD);
				temp += dp[i][j];
				temp %= (lli)(MOD);
				printf("%lld ", dp[i][j]);
			}
		}
		printf(" : %lld\n", temp);
	}
	printf("0");
	return 0;
} 