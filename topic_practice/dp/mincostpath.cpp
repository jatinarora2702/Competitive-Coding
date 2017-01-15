#include <bits/stdc++.h>
using namespace std;
int min(int a, int b, int c, int& flag) {
	if(a < b) {
		if(a < c) {
			flag = 1;
			return a;
		}
		else{
			flag = 3;
			return c;
		}
	}
	else{
		if(b < c){
			flag = 2;
			return b;
		}
		else{
			flag = 3;
			return c;
		}
	}
}
void print_path(int **s, int **a, int x, int y) {
	if(x < 0 or y < 0)
		return;
	if(s[x][y] == 3)
		print_path(s,a,x-1,y-1);
	else if(s[x][y] == 2)
		print_path(s,a,x,y-1);
	else
		print_path(s,a,x-1,y);
	printf("(%d,%d):%d ",x,y,a[x][y]);
}
int main() {
	int **a,**dp,**s,m,n,x,y,flag;
	printf("Enter the no. of rows : ");
	scanf("%d",&n);
	printf("Enter the no. of columns : ");
	scanf("%d",&m);
	a = new int*[n];
	for(int i = 0 ; i < n ; i++ ) {
		a[i] = new int[m];
	}
	printf("Enter the 2-d array of costs :\n");
	for(int i = 0 ; i < n ; i++ ) {
		for(int j = 0 ; j < m ; j++ ) {
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter the position(0-indexed) to which the min. cost path from (0,0) is to be found :\n");
	printf("Enter x : ");
	scanf("%d",&x);
	printf("Enter y : ");
	scanf("%d",&y);
	dp = new int*[y+1];
	s = new int*[y+1];
	for(int i = 0 ; i <= y ; i++ ) {
		dp[i] = new int[x+1];
		s[i] = new int[x+1];
	}
	dp[0][0] = a[0][0];
	s[0][0] = 3;  // invalid
	for(int j = 1 ; j <= y ; j++) {
		dp[0][j] = dp[0][j-1] + a[0][j];
		s[0][j] = 2;
	}
	for(int i = 1 ; i <= x ; i++ ) {
		dp[i][0] = dp[i-1][0] + a[i][0];
		s[i][0] = 1;
	}
	for(int i = 1 ; i <= x ; i++ ) {
		for(int j = 1 ; j <= y ; j++ ) {
			dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1],flag) + a[i][j];
			s[i][j] = flag;
		}
	}
	/*
	printf("\ndp array :\n");
	for(int i = 0 ; i <= x ; i++ ) {
		for(int j = 0 ; j <= y ; j++ ) {
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
	printf("\ns array :\n");
	for(int i = 0 ; i <= x ; i++ ) {
		for(int j = 0 ; j <= y ; j++ ) {
			printf("%d",s[i][j]);
		}
		printf("\n");
	}
	*/
	printf("\nMinimum cost path from (0,0) to (%d,%d) is : %d\n",x,y,dp[x][y]);
	printf("Path :\n");
	print_path(s,a,x,y);
	printf("\n");
	return 0;
}