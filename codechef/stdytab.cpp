#include <iostream>
#include <cstdio>
#include <cmath>
#define N 2005
#define MOD 1000000000
using namespace std;
typedef long long int lli;
typedef long double ld;
int dp[N][N];
ld val[N], mod, t2;
lli valmod[N], t1;
int main() {
	int t, n, m;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		val[0] = 1;
		valmod[0] = 1;
		for(int i = 1 ; i <= m ; i++){
			val[i] = (val[i-1] * (ld)(m+i-1)) / (ld)i;
			// cout << val[i] << " ";
			t2 = val[i] / (ld)(MOD);
			valmod[i] = (lli)((ld)(modf(t2, &mod)) * (ld)(MOD));
		}
		// cout << endl;
		// for(int i = 0 ; i <= m ; i++)
		// 	printf("%lld ", valmod[i]);
		// printf("\n");
		for(int j = 0 ; j <= m ; j++)
			dp[0][j] = 1;
		for(int i = 1 ; i <= n ; i++){
			for(int j = 0 ; j <= m ; j++){
				t1 = (lli)dp[i-1][j] * (lli)valmod[j];
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