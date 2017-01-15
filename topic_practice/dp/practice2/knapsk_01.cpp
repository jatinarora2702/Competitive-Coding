#include <iostream>
#include <cstdio>
#include <utility>
#define ff first
#define ss second
using namespace std;
int max_cost(int m, int n, pair < int, int > *p, int **dp){
	if(m < 0)
		return 0;
	if(n == 0 || m == 0)
		dp[m][n] = 0;
	if(dp[m][n] != -1)
		return dp[m][n];
	dp[m][n] = max(max_cost(m-p[n-1].ff, n-1, p, dp) + p[n-1].ss, max_cost(m, n-1, p, dp));
	return dp[m][n];
}
int main() {
	int n, m, cnt, **dp, x, y;
	pair < int, int > *p;
	printf("Enter the no. of comodities : ");
	scanf("%d", &n);
	printf("Enter the size of knapsack : ");
	scanf("%d", &m);
	printf("Enter the comodity info in form (weight, price) :\n");
	p = new pair < int , int > [n];
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &x, &y);
		p[i] = make_pair(x, y);
	}
	dp = new int*[m+1];
	for(int i = 0 ; i <= m; i++)
		dp[i] = new int[n+1];
	for(int i = 0 ; i <= m ; i++){
		for(int j = 0 ; j <= n ; j++)
			dp[i][j] = -1;
	}
	cnt = max_cost(m, n, p, dp);
	printf("max cost is : %d\n", cnt);
	return 0;
}