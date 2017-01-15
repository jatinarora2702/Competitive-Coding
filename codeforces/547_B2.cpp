#include <iostream>
#include <stdio.h>
#define INF 1e9+7
using namespace std;
// void print(int **dp, int n){
// 	for(int i = 0 ; i < n ; i++){
// 		for(int j = 0 ; j < n ; j++){
// 			printf("%d ", dp[i][j]);
// 		}
// 		printf("\n");
// 	}
// }
int main(){
	int n, **dp, *a, *minarr, f;
	scanf("%d", &n);
	a = new int[n];
	minarr = new int[n];
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	dp = new int*[2];
	for(int i = 0 ; i < 2 ; i++)
		dp[i] = new int[n];
	minarr[0] = -INF;
	for(int i = 0 ; i < n ; i++){
		dp[0][i] = a[i];
		if(minarr[0] < dp[0][i])
			minarr[0] = dp[0][i];
	}
	// print(dp, n);
	f = 1;
	for(int i = 1 ; i < n ; i++){
		minarr[i] = -INF;
		f ^= 1;
		for(int j = 0 ; j < n-i ; j++){
		// cout << i << " " << j << " " << (f^1) << " kk" << endl;
			dp[f^1][j] = min(dp[f][j], dp[f][j+1]);
			// cout << i << " " << j << " " << f << " " << dp[f^1][j] << endl;
			if(dp[f^1][j] > minarr[i])
				minarr[i] = dp[f^1][j];
		}
	}
	// print(dp, n);
	for(int i = 0 ; i < n ; i++)
		printf("%d ", minarr[i]);
	return 0;
}