#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
int main() {
	int n, k, **dp, min, v;
	printf("Enter the no. of floors : ");
	scanf("%d",&n);
	printf("Enter the no. of eggs : ");
	scanf("%d",&k);
	dp = new int*[n];
	for(int i = 0 ; i < n ; i++) {
		dp[i] = new int[k];
	}
	for(int i = 0 ; i < n ; i++) {
		dp[i][0] = i;
	}
	for(int i = 0 ; i < n ; i++) {
		for(int j = 1 ; j < k ; j++) {
			dp[i][j] = 1;
			min = INF;
			for(int f = 0 ; f <= i ; f++) {
				if(f != 0)
					v = dp[f-1][j-1];
				else
					v = 0;
				if(i-f-1 >= 0 and dp[i-f-1][j] > v)
					v = dp[i-f-1][j];
				if(v < min)
					min = v;
			}
			dp[i][j] += min;
		}
	}
	printf("Min. no. of egg drops is : %d\n",dp[n-1][k-1]);
	return 0;
}