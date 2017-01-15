#include <iostream>
#include <cstdio>
#define N 100005
using namespace std;
int dp[N];
int main() {
	int n, x, ans;
	ans = 0;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &x);
		dp[x] = dp[x-1] + 1;
		ans = max(ans, dp[x]);
	}
	printf("%d\n", n - ans);
	return 0;
}