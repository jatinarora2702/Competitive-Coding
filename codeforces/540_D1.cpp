#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 101;
double dp[N][N][N];
double sums[3];
int main(){
	int r, p, s;
	scanf("%d%d%d", &r, &s, &p);
	dp[r][p][s] = 1;
	for(int i = r ; i >= 0 ; i--){
		for(int j = p ; j >= 0 ; j--){
			for(int k = s ; k >= 0 ; k--){
				if(i == r and j == p and k == s)
					continue;
				dp[i][j][k] = 0;
				if(i < r and (i+1)*j + (i+1)*k + j*k > 0)
					dp[i][j][k] += (double)(dp[i+1][j][k]*(i+1)*j) / (double)((i+1)*j + (i+1)*k + j*k);
				if(j < p and (i*(j+1) + i*k + (j+1)*k) > 0)
					dp[i][j][k] += (double)(dp[i][j+1][k]*(j+1)*k) / (double)(i*(j+1) + i*k + (j+1)*k);
				if(k < s and (i*j + i*(k+1) + j*(k+1)) > 0)
					dp[i][j][k] += (double)(dp[i][j][k+1]*(k+1)*i) / (double)(i*j + i*(k+1) + j*(k+1));
				//printf("dp[%d][%d][%d] = %.12lf\n", i, j, k, dp[i][j][k]);
			}
		}
	}
	for(int i = 0 ; i < 3 ; i++)
		sums[i] = 0;
	for(int i = 0 ; i <= r ; i++)
		sums[0] += dp[i][0][0];
	for(int i = 0 ; i <= p ; i++)
		sums[1] += dp[0][i][0];
	for(int i = 0 ; i <= s ; i++)
		sums[2] += dp[0][0][i];
		printf("%.12lf %.12lf %.12lf", sums[0], sums[2], sums[1]);
	return 0;
}