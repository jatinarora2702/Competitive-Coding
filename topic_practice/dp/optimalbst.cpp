#include <bits/stdc++.h>
using namespace std;
int sum(int *freq, int i , int j){
	int s = 0;
	for(int k = i ; k <= j ; k++)
		s += freq[k];
	return s;
}
int main() {
	int n, *a, *freq, **dp, s, v;
	printf("Enter the no. of nodes in the tree : ");
	scanf("%d", &n);
	printf("Enter the values of the nodes :\n");
	a = new int[n];
	freq = new int[n];
	dp = new int*[n];
	for(int i = 0 ; i < n ; i++) {
		dp[i] = new int[n];
	}
	for(int i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
	}
	printf("Enter the resp. frequencies :\n");
	for(int i = 0 ; i < n ; i++) {
		scanf("%d", &freq[i]);
	}
	for(int i = 0 ; i < n ; i++)
		dp[i][i] = freq[i];
	for(int k = 1 ; k < n ; k++){
		for(int i = 0 ; i < n-k ; i++) {
			int j = i+k;
			s = sum(freq, i, j);
			dp[i][j] = dp[i+1][j];
			for(int r = i+1 ; r < j ; r++){
				v = dp[i][r-1] + dp[r+1][j];
				if(v < dp[i][j])
					v = dp[i][j];
			}
			v = dp[i][j-1];
			if(v < dp[i][j])
				dp[i][j] = v;
			dp[i][j] += s;
		}
	}
	printf("The optimal cost of searches is : %d\n", dp[0][n-1]);
	return 0;
}