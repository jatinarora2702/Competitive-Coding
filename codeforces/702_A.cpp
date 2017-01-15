#include <bits/stdc++.h>
#define N 100005
using namespace std;

int a[N], dp[N];
int main() {
	int n, m, i;
	scanf("%d", &n);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
	}
	dp[0] = 1;
	for(i = 1 ; i < n ; i++) {
		dp[i] = 1;
		if(a[i] > a[i-1])
			dp[i] += dp[i-1];
	}
	m = 1;
	for(i = 0 ; i < n ; i++) {
		m = max(m, dp[i]);
	}
	printf("%d\n", m);
	return 0;
}