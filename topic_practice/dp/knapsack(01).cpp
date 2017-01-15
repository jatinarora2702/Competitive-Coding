#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, wt, **dp, *v, *w;
	printf("Enter the no. of items : ");
	scanf("%d",&n);
	printf("Enter the respective weights :\n");
	w = new int[n];
	for(int i = 0 ; i < n ; i++ ) {
		scanf("%d", &w[i]);
	}
	printf("Enter the respective costs :\n");
	v = new int[n];
	for(int i = 0 ; i < n ; i++ ) {
		scanf("%d", &v[i]);
	}
	printf("Enter the total permissible wt. : ");
	scanf("%d", &wt);
	dp = new int*[wt+1];
	for(int i = 0 ; i <= wt ; i++ ) {
		dp = new int[n+1];
	}
	for(int i = 0 ; i <= wt ; i++ ) {
		dp[i][0] = 0;
	}
	for(int i = 0 ; i <= n ; i++ ) {
		dp[0][i] = 0;
	}
	for(int i = 1 ; i <= wt ; i++ ) {
		for(int j = 1 ; j <= n ; j++ ) {
			dp[i][j] = dp[i][j-1];
			if(i-w[j] >= 0 and (dp[i-w[j]][j-1] + v[j]) > dp[i][j]){
				dp[i][j] = dp[i-w[j]][j-1] + v[j];
			}
		}
	}
	printf("Max. cost is : %d\n", &dp[wt][n]);
	return 0;
}