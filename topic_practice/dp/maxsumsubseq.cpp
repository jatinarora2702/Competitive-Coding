#include <bits/stdc++.h>
#define INF 1000000007
using namespace std;
int main() {
	int *a, *dp, n, max;
	printf("Enter the no. of elements in the array : ");
	scanf("%d", &n);
	printf("Enter the array :\n");
	a = new int[n];
	for(int i = 0 ; i < n ; i++ ) {
		scanf("%d", &a[i]);
	}
	dp = new int[n];
	dp[0] = a[0];
	for(int i = 1 ; i < n ; i++ ) {
		max = -INF;
		for(int j = 0 ; j < i ; j++ ) {
			if(a[j] < a[i] and max < dp[j])
				max = dp[j];
		}
		dp[i] = max + a[i];
	}
	max = dp[0];
	for(int i = 1 ; i < n ; i++ ) {
		if(max < dp[i])
			max = dp[i];
	}
	printf("The max. sum increasing subseq. has sum : %d\n", max);
	return 0;
}