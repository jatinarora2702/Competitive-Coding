#include <iostream>
#include <cstdio>
#define N 10000
using namespace std;
int dp[N][N];
int main() {
	int e, f, n;
	printf("Enter the no. of eggs: ");
	scanf("%d", &e);
	printf("Enter the no. of floors: ");
	scanf("%d", &f);
	printf("The max. no. of egg droppings are: ");
	for(int i = 0 ; i < f ; i++)
		dp[i][0] = i+1;
	for(int j = 0 ; j < e ; j++)
		dp[0][j] = 1;
	for(int i = 1 ; i < f ; i++){
		for(int j = 1 ; j < e ; j++){
			dp[i][j] = dp[i-1][j];
			for(int k = 1 ; k < i ; k++)
				dp[i][j] = min(dp[i][j], max(dp[i-k-1][j], dp[k-1][j-1]));
			dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
			dp[i][j]++;
		}
	}
	printf("%d\n", dp[f-1][e-1]);
	return 0;
}