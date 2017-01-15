#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, *a, *dp, cnt;
	scanf("%d", &n);
	a = new int[n];
	dp = new int[n];
	for(int i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 0 ; i < n ; i++){
		dp[i] = 1;
		cnt = 0;
		for(int j = 0 ; j < i ; j++){
			if(a[j] < a[i] && dp[j] > cnt)
				cnt = dp[j];
		}
		dp[i] += cnt;
	}
	cnt = dp[0];
	for(int i = 0 ; i < n ; i++){
		if(dp[i] > cnt)
			cnt = dp[i];
	}
	printf("lis length : %d\n", cnt);
	return 0;
}