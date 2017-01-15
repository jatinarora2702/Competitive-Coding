#include <bits/stdc++.h>
using namespace std;
void print(int *a, int *s, int pos) {
	if(pos == -1)
		return;
	print(a,s,s[pos]);
	if(s[pos] == -1)
		printf("%d",a[pos]);
	else
		printf(" %d",a[pos]);
}
int main() {
	int n,max,pos,*a,*dp,*s;
	printf("Enter the no. of tems in the sequence : ");
	scanf("%d",&n);
	a = new int[n];
	printf("\nEnter the sequence :\n");
	for(int i = 0 ; i < n ; i++ ) {
		scanf("%d",&a[i]);
	}
	dp = new int[n];
	s = new int[n];
	dp[0] = 1;
	s[0] = -1;  // invalid
	for(int i = 1 ; i < n ; i++ ) {
		dp[i] = 1;
		max = 0;
		for(int j = 0 ; j < i ; j++ ) {
			if(a[j] > a[i])
				continue;
			if(dp[j] > max) {
				max = dp[j];
				s[i] = j;
			}
		}
		dp[i] += max;
	}
	max = dp[0];
	for(int i = 1 ; i < n ; i++ ) {
		if(max < dp[i]) {
			max = dp[i];
			pos = i;
		}
	}
	printf("Longest increasing sequence is of length : %d\n",max);
	printf("\nSequence is :\n")
	print(a,s,pos);
	delete[] a;
	delete[] dp;
	delete[] s;
	printf("\n");
	return 0;
}
