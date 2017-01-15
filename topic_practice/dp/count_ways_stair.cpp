#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int n, *dp;
	printf("Enter the no. of stairs (>=1) : ");
	scanf("%d", &n);
	dp = new int[n];
	dp[0] = 1;
	dp[1] = 2;
	for(int i = 2 ; i < n ; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	printf("The no. of ways is : %d\n", dp[n-1]);
	return 0;
}