#include <bits/stdc++.h>
using namespace std;
float min(float a, float b, float c) {
	if(a < b) {
		if(a < c)
			return a;
		else
			return c;
	}
	else {
		if(b < c)
			return b;
		else
			return c;
	}
}
int main() {
	int m, n;
	float ic, dc, rc, **dp, c1, c2, c3; 
	char *a, *b, **s;
	printf("Enter the length of the old string : ");
	scanf("%d",&m);
	a = new char[m+1];
	printf("Enter the string :\n");
	scanf("%s",a);
	printf("Enter the length of the new string : ");
	scanf("%d",&n);
	b = new char[n+1];
	printf("Enter the string :\n");
	scanf("%s",b);
	printf("Enter the costs for editing :\n");
	printf("Insertion : ");
	scanf("%f", &ic);
	printf("\nDeletion : ");
	scanf("%f", &dc);
	printf("\nReplacement : ");
	scanf("%f", &rc);
	dp = new float*[m+1];
	for(int i = 0 ; i < m+1 ; i++ ) {
		dp[i] = new float[n+1];
	}
	for(int i = 0 ; i < m+1 ; i++ ) {
		dp[i][0] = i * dc;
	}
	for(int i = 0 ; i < n+1 ; i++ ) {
		dp[0][i] = i * ic;
	}
	for(int i = 1 ; i < m+1 ; i++ ) {
		for(int j = 1 ; j < n+1 ; j++ ) {
			c1 = dp[i-1][j] + dc;
			c2 = dp[i][j-1] + ic;
			c3 = dp[i-1][j-1] + ((a[i-1] == b[j-1]) ? 0 : rc);
			dp[i][j] = min(c1,c2,c3);
		}
	}
	printf("Minimum edit cost is : %f\n", dp[m][n]);
	return 0;
}