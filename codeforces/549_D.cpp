#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int n, m, **dp, cnt, j, minm;
	char **s;
	scanf("%d%d", &n, &m);
	s = new char*[n];
	dp = new int*[n];
	for(int i = 0 ; i < n ; i++){
		s[i] = new char[m+1];
		dp[i] = new int[m];
		scanf("%s", s[i]);
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++)
			dp[i][j] = 0;
	}
	cnt = 0;
	minm = (m < n) ? m : n;
	cout << minm << endl;
	for(int k = 0 ; k < minm ; k++){
		j = m-k-2;
		for(int i = n-1 ; i >= n-k-1 ; i--){
			j++;
				if(i < n-1 and j < m-1){
					if(dp[i+1][j] != dp[i][j+1]){
						if(dp[i+1][j] == dp[i+1][j+1])
							dp[i][j] = dp[i][j+1];
						else
							dp[i][j] = dp[i+1][j];
					}
					else
						dp[i][j] = dp[i+1][j];
				}
				else if(i < n-1){
					dp[i][j] = dp[i+1][j];
				}
				else if(j < m-1){
					dp[i][j] = dp[i][j+1];
				}
				printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
				if(dp[i][j] == 1){
					if(s[i][j] == 'W')
						continue;
					else{
						dp[i][j] = -1;
						cnt++;
					}
				}
				else if(dp[i][j] == -1){
					if(s[i][j] == 'B')
						continue;
					else{
						dp[i][j] = 1;
						cnt++;
					}
				}
				else{
					if(s[i][j] == 'B'){
						dp[i][j] = -1;
						cnt++;
					}
					else{
						dp[i][j] = 1;
						cnt++;
					}
				}
		}
	}
	for(int k = 0 ; k < minm ; k++){
		j = m-k-2;
		for(int i = n-1 ; i >= n-k-1 ; i--){
			j++;
			if(i < n-1 and j < m-1){
				if(dp[i+1][j] != dp[i][j+1]){
					if(dp[i+1][j] == dp[i+1][j+1])
						dp[i][j] = dp[i][j+1];
					else
						dp[i][j] = dp[i+1][j];
				}
				else
					dp[i][j] = dp[i+1][j];
			}
			else if(i < n-1){
				dp[i][j] = dp[i+1][j];
			}
			else if(j < m-1){
				dp[i][j] = dp[i][j+1];
			}
			if(dp[i][j] == 1){
				if(s[i][j] == 'W')
					continue;
				else{
					dp[i][j] = -1;
					cnt++;
				}
			}
			else if(dp[i][j] == -1){
				if(s[i][j] == 'B')
					continue;
				else{
					dp[i][j] = 1;
					cnt++;
				}
			}
			else{
				if(s[i][j] == 'B'){
					dp[i][j] = -1;
					cnt++;
				}
				else{
					dp[i][j] = 1;
					cnt++;
				}
			}
		}
	}
	printf("%d", cnt);
	return 0;
}