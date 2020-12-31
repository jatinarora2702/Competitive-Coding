#include <bits/stdc++.h>
#define N 200005
using namespace std;

typedef long long int lli;

const lli INF = 1e18 + 7LL;

lli dp[N][2];

int main() {
	int t, n, a, b;
	string s;
	cin >> t;
	while(t--) {
		cin >> n >> a >> b >> s;
		dp[0][0] = b;
		dp[0][1] = INF;
		for(int i = 1; i < n; i++) {
			if(s[i] == '0') {
				dp[i][0] = INF;
				if (s[i-1] != '1' && dp[i-1][0] != INF) {
					dp[i][0] = min(dp[i][0], dp[i-1][0] + a + b);
				}
				if (s[i-1] != '1' && dp[i-1][1] != INF) {
					dp[i][0] = min(dp[i][0], dp[i-1][1] + (2*a) + b);
				}
				dp[i][1] = INF;
				if (dp[i-1][0] != INF) {
					dp[i][1] = min(dp[i][1], dp[i-1][0] + (2*a) + (2*b));
				}
				if (dp[i-1][1] != INF) {
					dp[i][1] = min(dp[i][1], dp[i-1][1] + a + (2*b));
				}
			}
			else {
				dp[i][0] = INF;
				dp[i][1] = INF;
				if (dp[i-1][0] != INF) {
					dp[i][1] = min(dp[i][1], dp[i-1][0] + (2*a) + (2*b));
				}
				if (dp[i-1][1] != INF) {
					dp[i][1] = min(dp[i][1], dp[i-1][1] + a + (2*b));
				}
			}
		}
		// for(int i = 0; i < n; i++) {
		// 	cout << dp[i][0] << " " << dp[i][1] << "\n";
		// }
		cout << min(dp[n-1][0] + a + b, dp[n-1][1] + (2*a) + b) << "\n";
	}
	return 0;
}