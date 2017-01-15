#include <bits/stdc++.h>
#define PB push_back
#define FF first
#define SS second
#define MP make_pair
#define N 1000
using namespace std;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9+7;
const int MOD = 1e9+7;
lli dp[N][N];
int main(){
	int n;
	lli ans;
	scanf("%d", &n);
	for(int i = 0 ; i <= n ; i++)
		dp[i][0] = 1LL;
	dp[1][1] = 1LL;
	for(int i = 2 ; i <= n ; i++){
		for(int j = 1 ; j <= i ; j++){
			dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
		}
	}
	ans = dp[n][5] + dp[n][6] + dp[n][7];
	cout << ans << endl;
	return 0;
}