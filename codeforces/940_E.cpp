#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100005;

int a[N];
ll dp[N];
multiset < ll > mst;

int main() {
	int n, c, i;
	scanf("%d%d", &n, &c);
	for(i = 1 ; i <= n ; i++)
		scanf("%d", &a[i]);
	ll s = 0LL;
	dp[0] = 0LL;
	for(i = 1 ; i <= n ; i++) {
		dp[i] = dp[i-1] + a[i];
		s += a[i];
		mst.insert(a[i]);
		if(i-c > 0) {
			s -= a[i-c];
			mst.erase(mst.find(a[i-c]));
		}
		if(i-c >= 0)
			dp[i] = min(dp[i], dp[i-c] + s - *mst.begin());
	}
	printf("%lld\n", dp[n]);
	return 0;
}