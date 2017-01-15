#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, v, k, *p, *dp, *s;
	printf("Enter the length of the rod : ");
	scanf("%d", &n);
	p = new int[n];
	printf("Enter the resp. prices for various integral lengths of the rod :\n");
	for(int i = 0 ; i < n ; i++ ) {
		scanf("%d", &p[i]);
	}
	dp = new int[n];
	s = new int[n];
	dp[0] = p[0];
	s[0] = -1;
	for(int i = 1 ; i < n ; i++ ) {
		dp[i] = p[i];
		s[i] = -1;
		for(int j = 0 ; j < i ; j++ ) {
			v = p[j] + dp[i-j-1];
			if(v > dp[i]){
				dp[i] = v;
				s[i] = i-j-1;
			}
		}
	}
	printf("Max. price is : %d\n", dp[n-1]);
	printf("The cuts are :\n");
	k = n-1;
	while(1) {
		if(s[k] != -1){
			printf("%d ", k-s[k]);
			k = s[k];
		}
		else if(s[k] == -1) {
			printf("%d\n", k+1);
			break;
		}
	}
	return 0;
}