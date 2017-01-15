#include <iostream>
#include <cstdio>
#define N 1000
#define M 10000
using namespace std;
int a[N], dp[M][N];
int ways(int v, int n){
	if(v < 0 || n < 1)
		return 0;
	if(dp[v][n] == -1){
		if(n == 1)
			dp[v][n] = (v % a[n-1] == 0) ? 1 : 0;
		else
			dp[v][n] = ways(v-a[n-1], n) + ways(v, n-1);	
	}
	return dp[v][n];
}
int main() {
	int n, k, s;
	printf("Enter the no. of diff. coins: ");
	scanf("%d", &n);
	printf("Enter the deinominations:\n");
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	printf("Enter the no.: ");
	scanf("%d", &s);
	for(int i = 0 ; i < M ; i++){
		for(int j = 0 ; j < N ; j++)
			dp[i][j] = -1;
	}
	k = ways(s, n);
	printf("No. of ways is: %d\n", k);
	return 0;
}