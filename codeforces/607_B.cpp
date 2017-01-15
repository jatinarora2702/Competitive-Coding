#include <bits/stdc++.h>
#define N 505
#define INF 1000000007
#define PB push_back
using namespace std;
int a[N], dp[N][N];
vector < int > v[N];
int main(){
	int n, m, j;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);
		v[a[i]].PB(i);
	}
	for(int i = 0 ; i < n ; i++)
		dp[i][i] = 1;
	for(int k = 1 ; k < n ; k++){
		for(int i = 0 ; i < n-k ; i++){
			j = i+k;
			dp[i][j] = INF;
			if(a[i] == a[i+1])
				dp[i][j] = min(dp[i][j], 1 + dp[i+2][j]);
			dp[i][j] = min(dp[i][j], 1 + dp[i+1][j]);
			for(int l = 0 ; l < v[a[i]].size() ; l++){
				if(v[a[i]][l] > i+1 && v[a[i]][l] <= j){
					m = v[a[i]][l];
					dp[i][j] = min(dp[i][j], dp[i+1][m-1] + dp[m+1][j]);
				}
				else if(v[a[i]][l] > j)
					break;
			}
		}
	}
	printf("%d", dp[0][n-1]);
	return 0;
}