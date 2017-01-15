#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int n, **dp;
	printf("Enter the length of the binary string : ");
	scanf("%d", &n);
	dp =new int*[n];
	for(int i = 0 ; i < n; i++)
		dp[i] = new int[2];
	dp[0][0] = 1;
	dp[0][1] = 1;
	for(int i = 1 ; i < n ; i++){
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
		dp[i][1] = dp[i-1][0];
	}
	printf("No. of strings of given length which has no consecutive 1's is : %d\n", dp[n-1][0]+dp[n-1][1]);
	return 0;
}