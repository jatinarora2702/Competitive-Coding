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
	int n, n5, n3;
	lli ans;
	scanf("%d", &n);
	n5 = 5 + n - 1;
	n3 = 3 + n - 1;
	for(int i = 0 ; i <= n+5 ; i++)
		dp[i][0] = 1LL;
	dp[1][1] = 1LL;
	for(int i = 2 ; i <= n+5 ; i++){
		for(int j = 1 ; j <= 6 ; j++){
			dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
		}
	}
	ans = dp[n5][5] * dp[n3][3];
	cout << ans << endl;
	return 0;
}