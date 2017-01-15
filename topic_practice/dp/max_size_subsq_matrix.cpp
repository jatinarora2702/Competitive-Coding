#include <bits/stdc++.h>
using namespace std;
int max_fn(int a, int b, int c, int d, int k){
	if(a == b and b == c and c == d and d == k){
		return k+1;
	}
	int max1, max2;
	max1 = ((a > b) ? a : b);
	max2 = ((c > d) ? c : d);
	return (max1 > max2) ? max1 : max2;
}
int main() {
	int m, n, **a, ***dp, min, v, max;
	printf("Enter the dimensions of the matrix (r c) : ");
	scanf("%d%d", &m, &n);
	min = (m < n) ? m : n;
	printf("Enter the matrix :\n");
	a = new int*[m];
	for(int i = 0 ; i < m ; i++) {
		a[i] = new int[n];
	}
	for(int i = 0 ; i < m ; i++) {
		for(int j = 0 ; j < n ; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	dp = new int**[m];
	for(int i = 0 ; i < m ; i++){
		dp[i] = new int*[n];
		for(int j = 0 ; j < n ; j++){
			dp[i][j] = new int[min];
		}
	}
	max = 0;
	for(int i = 0 ; i < m ; i++) {
		for(int j = 0 ; j < n ; j++) {
			dp[i][j][0] = a[i][j];
			if(max < a[i][j])
				max = a[i][j];
		}
	}
	cout << "max=" << max << endl;
	for(int k = 1 ; k < min ; k++) {
		for(int i = 0 ; i < m-k ; i++) {
			for(int j = 0 ; j < n-k ; j++) {
				v = max_fn(dp[i][j][k-1], dp[i+1][j][k-1], dp[i][j+1][k-1], dp[i+1][j+1][k-1], k);
				dp[i][j][k] = v;
				if(max < dp[i][j][k])
					max = dp[i][j][k];
			}
		}
	}
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++){
			for(int k = 0 ; k < min ; k++){
				printf("dp[%d][%d][%d] = %d\n", i, j, k, dp[i][j][k]);
			}
		}
	}
	printf("Max. size sub-square matrix with all 1's is of size : %d\n", max);
	return 0;
}