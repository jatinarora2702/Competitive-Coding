#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int balance(int *a, int *dp, int k, int n, int &cnt){
	int v1, v2, d;
	if(dp[k] == -1){
		v1 = balance(a, dp, 2*k+1, n, cnt) + a[2*k];
		v2 = balance(a, dp, 2*k+2, n, cnt) + a[2*k+1];
		v1 = abs(v1);
		v2 = abs(v2);
		d = v1 - v2;
		if(d < 0) d = d * (-1);
		cnt += d;
		dp[k] = (v1 > v2) ? v1 : v2;
	}
	return dp[k];
}
int main() {
	int n, *a, *dp, s, cnt, k;
	int p[] = {2, 6, 14, 30, 62, 126, 254, 510, 1022, 2046};
	scanf("%d", &n);
	a = new int[p[n-1]];
	dp = new int[p[n-1]+1];
	for(int i = 0 ; i < p[n-1] ; i++)
		scanf("%d", &a[i]);
	k = 0;
	if(n-2 >= 0)
		k = p[n-2];
	for(int i = 0 ; i <= k ; i++)
		dp[i] = -1;
	for(int i = k+1 ; i < p[n-1]+1 ; i++)
		dp[i] = 0;
	cnt = 0;
	s = balance(a, dp, 0, p[n-1]+1, cnt);
	printf("%d", cnt);
	return 0;
}