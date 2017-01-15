#include <bits/stdc++.h>
using namespace std;
void print(int *a, int *s, int i) {
	if(i == -1)
		return;
	print(a,s,s[i]);
	printf(" %d",a[i]);
}
int main() {
	int *a, *dp, *s, max, n;
	printf("Enter the no. of elements in the seq. : ");
	scanf("%d",&n);
	printf("Enter the seq. :\n");
	a = new int[n];
	for(int i = 0 ; i < n ; i++ ) {
		scanf("%d",&a[i]);
	}
	dp = new int[n];
	s = new int[n];
	dp[0] = 1;
	s[0] = -1;
	for(int i = 1 ; i < n ; i++ ) {
		max = 0;
		for(int j = 0 ; j < i ; j++ ) {
			if(a[j] <= a[i] and max < dp[j]) {
				max = dp[j];
				s[i] = j;
			}
		}
		dp[i] = max + 1;
	}
	max = 0;
	for(int i = 0 ; i < n ; i++ ) {
		if(dp[max] < dp[i]) {
			max = i;
		}
	}
	printf("Longest length of non-dec. seq. is : %d",dp[max]);
	printf("\nThe seq. is :\n");
	print(a,s,max);
	printf("\n");
	return 0;
}