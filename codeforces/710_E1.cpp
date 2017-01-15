#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define N 30000005
using namespace std;

typedef long long int lli;
typedef long double ld;
typedef pair < lli, int > pli;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

lli dp[N];
pli p;
priority_queue < pli, vector < pli >, greater < pli > > pq;
int main() {
	int i, n, x, y, f;
	scanf("%d%d%d", &n, &x, &y);
	dp[0] = 0LL;
	dp[1] = (lli)x;
	// cout << dp[1] << endl;
	for(i = 2 ; i <= 2*n ; i++) {
		dp[i] = LINF;
	}
	dp[2] = dp[1] + (lli)y;
	for(i = 2 ; i <= n ; i++) {
		dp[i] = min(dp[i], dp[i-1]+(lli)x);
		dp[i] = min(dp[i], dp[i+1]+(lli)x);
		dp[2*i] = min(dp[2*i], dp[i]+(lli)y);
	}
	// cout << endl;
	cout << dp[n] << endl;
	return 0;
}