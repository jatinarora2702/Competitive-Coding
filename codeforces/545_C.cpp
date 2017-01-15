#include <iostream>
#include <stdio.h>
using namespace std;
int maxm(int a, int b, int c){
	if(a > b){
		if(a > c)
			return a;
		else
			return c;
	}
	else{
		if(b > c)
			return b;
		else
			return c;
	}
}
int main() {
	int n, *x, *h, **dp, k;
	scanf("%d", &n);
	x = new int[n];
	h = new int[n];
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &x[i], &h[i]);
	}
	dp = new int*[n];
	for(int i = 0 ; i < n ; i++)
		dp[i] = new int[3];
	dp[0][0] = dp[0][1] = 1;
	dp[0][2] = 0;
	for(int i = 1 ; i < n ; i++){
		dp[i][0] = 0;
		if(x[i-1] < x[i] - h[i])
			dp[i][0] = 1 + dp[i-1][0];
		if(x[i-1] + h[i-1] < x[i] - h[i] and dp[i-1][1] > dp[i-1][0])
			dp[i][0] = 1 + dp[i-1][1];
		if(x[i-1] < x[i] - h[i] and dp[i][0] < 1+dp[i-1][2])
			dp[i][0] = 1 + dp[i-1][2];
		dp[i][1] = 0;
		k = maxm(dp[i-1][0],dp[i-1][1],dp[i-1][2]);
		if(i < n-1){
			if(x[i] + h[i] < x[i+1])
				dp[i][1] = 1 + k;
		}
		else
			dp[i][1] = 1 + k;
		dp[i][2] = k;
	}
	printf("%d", maxm(dp[n-1][0],dp[n-1][1],dp[n-1][2]));
	return 0;
}