#include <bits/stdc++.h>
#define N 100005
using namespace std;
int a[N], dp[N], h[N];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);
	}
	dp[n-1] = a[n-1];
	for(int i = n-2 ; i >= 0 ; i--){
		dp[i] = max(a[i], dp[i+1]);
	}
	for(int i = 0 ; i < n ; i++){
		if(dp[i] == a[i])
			h[i] = 0;
		else
			h[i] = dp[i] - a[i] + 1;
	}
	for(int i = 0 ; i < n ; i++){
		printf("%d ", h[i]);
	}
	return 0;
}