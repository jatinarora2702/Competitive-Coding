#include <bits/stdc++.h>
using namespace std;
int max(int x, int y, char& c) {
	if(x > y) {
		c = '0';
		return x;
	}
	else{
		c = '1';
		return y;
	}
}
int main() {
	int n, **dp;
	char **s, *a;
	printf("Enter the no. of elements in the seq. : ");
	scanf("%d",&n);
	a = new char[n+1];
	printf("Enter the seq.(cannot have no.s 0 and 1) :\n");
	//scanf("%s",a);
	a = "GEEKS FOR GEEKS";
	printf("Printing seq. : %s\n",a);
	dp = new int*[n];
	s = new char*[n];
	for(int i = 0 ; i < n ; i++ ) {
		dp[i] = new int[n];
		s[i] = new char[n];
	}
	for(int i = 0 ; i < n ; i++ ) {
		dp[i][i] = 1;
		s[i][i] = a[i];
	}
	for(int i = 1 ; i < n ; i++ ) {
		for(int j = 0 ; j < n-i ; j++ ) {
			if(a[j] == a[j+i]){
				dp[j][j+i] = 2;
				if(i != 1)
					dp[j][j+i] += dp[j+1][j+i-1];
				s[j][j+i] = a[j];
			}
			else {
				dp[j][j+i] = max(dp[j+1][j+i], dp[j][j+i-1], s[j][j+i]);
			}
		}
	}
	printf("The longest palindromic subseq. is of length : %d\n",dp[0][n-1]);
	int i, j, k;
	char *p = new char[dp[0][n-1]+1];
	i = 0;
	j = n-1;
	k = 0;
	while(k <= dp[0][n-1]-k-1) {
		if(s[i][j] != '0' and s[i][j] != '1') {
			p[k] = p[dp[0][n-1]-k-1] = s[i][j];
			k++;
			i++;
			j--;
		}
		else if(s[i][j] == '0') {
			i++;
		}
		else if(s[i][j] == '1') {
			j--;
		}
	}
	p[dp[0][n-1]] = '\0';
	printf("The longest palindromic sunseq. is : %s\n", p);
	return 0;
}