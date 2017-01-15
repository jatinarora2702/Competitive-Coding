#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define N 100005
#define M 2005
using namespace std;
typedef long long int lli;
typedef long double ld;
const int MOD = 1e9+7;
const int INF = 1e9+7;

char s[N];
lli dp[M][M];
int main(){
	int n, m, lcnt, rcnt, x, y, n1;
	lli ans;
	scanf("%d%d%s", &n, &m, s);
	if(n % 2 != 0){
		printf("0\n");
		return 0;
	}
	x = 0;
	y = INF;
	for(int i = 0 ; i < m ; i++){
		if(s[i] == '(')
			y++;
		else
			y--;
		x = min(x, y);
	}
	dp[0][0] = 1LL;
	for(int i = 1 ; i < M ; i++){
		for(int j = 0 ; j < M ; j++){
			if(j > 0)
				dp[i][j] = dp[i-1][j-1];
			dp[i][j] += dp[i-1][j+1];
			dp[i][j] %= (lli)MOD;
		}
	}
	n1 = n - m;
	ans = 0;
	for(int i = 0 ; i <= n1 ; i++){
		for(int j = 0 ; j <= i ; j++){
			if(j + x < 0 || j + y > n1-i)
				continue;
			ans += dp[i][j] * dp[n1-i][j+y];
			ans %= (lli)MOD;
		}
	}
	cout << ans << endl;
}