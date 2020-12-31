#include <bits/stdc++.h>
#define N 100005
using namespace std;

int h[N][2];
long long dp[N][2];

int main() {
	int n, i;
	cin >> n;
	for(i = 0; i < n; i++) {
		cin >> h[i][0];
	}
	for(i = 0; i < n; i++) {
		cin >> h[i][1];
	}
	dp[n-1][0] = (long long)h[n-1][0];
	dp[n-1][1] = (long long)h[n-1][1];
	if (n >= 2) {
		dp[n-2][0] = dp[n-1][1] + (long long)h[n-2][0];
		dp[n-2][1] = dp[n-1][0] + (long long)h[n-2][1];
	}
	for(i = n-3; i >= 0; i--) {
		dp[i][0] = max(dp[i+1][1], dp[i+2][1]) + (long long)h[i][0];
		dp[i][1] = max(dp[i+1][0], dp[i+2][0]) + (long long)h[i][1];
	}
	cout << max(dp[0][0], dp[0][1]) << "\n";
	return 0;
}