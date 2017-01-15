#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int n, *a, s, **dp;
	printf("Enter the no. of terms in the array : ");
	scanf("%d", &n);
	a = new int[n];
	s = 0;
	printf("Enter the array(all positive elements) :\n");
	for(int i = 0 ; i < n ; i++ ) {
		scanf("%d", &a[i]);
		s += a[i];
	}
	if(s % 2 != 0)
		printf("It is not posible to partition it into two subsets of equal sum\n");
	else{
		s = s / 2;
		dp = new int*[s];
		for(int i = 0 ; i < s ; i++) {
			dp[i] = new int[n];
		}
		for(int i = 0 ; i < n ; i++) {
			dp[a[i]-1][0] = 1;
		}
		for(int i = 0 ; i < n ; i++) {
			if(dp[i][0] != 1)
				dp[i][0] = 0;
		}
		for(int i = 0 ; i < s ; i++) {
			for(int j = 1 ; j < n ; j++) {
				dp[i][j] = dp[i][j-1] or (i-a[j] > 0 and dp[i-a[j]][j-1]);
			}
		}
		if(dp[s-1][n-1] == 1)
			printf("It can be partitioned into two subsets of equal sum\n");
		else
			printf("It is not posible to partition it into two subsets of equal sum\n");
	}	
	return 0;
}