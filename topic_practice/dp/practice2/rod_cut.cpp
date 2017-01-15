#include <iostream>
#include <cstdio>
#include <utility>
#define ff first
#define ss second
using namespace std;
int main() {
	int n, m, cnt, *dp, x, y;
	pair < int, int > *a;
	scanf("%d%d", &m, &n);
	dp = new int[m+1];
	a = new pair < int , int > [n];
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &x, &y);
		a[i] = make_pair(x, y);	// (length, price)
	}
	cnt = 0;
	dp[0] = 0;
	for(int i = 1 ; i <= m ; i++){
		dp[i] = 0;
		for(int j = 0 ; j < n ; j++){
			if(i - a[j].ff >= 0)
				dp[i] = max(dp[i], dp[i-a[j].ff] + a[j].ss);
		}
	}
	printf("max : %d\n", dp[m]);
	return 0;
}