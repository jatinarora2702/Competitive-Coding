// is actually activity selection problem

#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int n, *a, *b, **dp;
	printf("Enter the no. of cities on both sides of the river : ");
	scanf("%d", &n);
	printf("Enter the no.s of the northern cities :\n");
	a = new int[n];
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	printf("Enter the no.s of the southern cities :\n");
	b = new int[n];
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &b[i]);
	dp = new int*[n];
	for(int i = 0 ; i < n ; i++)
		dp[i] = new int[n];
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(a[i] == b[j]){
				dp[i][j] = 1;
				if(i > 0 and j > 0)
					dp[i][j] += dp[i-1][j-1];
			}
			else{
				dp[i][j] = 0;	
				if(i > 0 and dp[i-1][j] > dp[i][j])
					dp[i][j] = dp[i-1][j];
				if(j > 0 and dp[i][j-1] > dp[i][j])
					dp[i][j] = dp[i][j-1];
			}
		}
	}
	printf("Max. no. of bridges is : %d\n", dp[n-1][n-1]);
	return 0;
}