#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define N 100005

using namespace std;

typedef long long int lli;
const int INF = 1e9+7;

int dp[N];
int main() {
	int t, k, a, b, i;
	lli temp;
	scanf("%d%d", &t, &k);
	dp[0] = 1;
	for(i = 1 ; i < N ; i++) {
		temp = (lli)dp[i-1];
		if(i-k >= 0) {
			temp += (lli)dp[i-k];
		}
		temp %= (lli)INF;
		dp[i] = (int)temp;
	}
	for(i = 1 ; i < N ; i++) {
		temp = (lli)dp[i-1] + (lli)dp[i];
		temp %= (lli)INF;
		dp[i] = (int)temp;
	}
	while(t--) {
		scanf("%d%d", &a, &b);
		a--;
		temp = (lli)dp[b] - (lli)dp[a] + (lli)INF;
		temp %= (lli)INF;
		printf("%d\n", (int)temp);
	}
	return 0;
}