#include <iostream>
#include <stdio.h>
#include <cmath>
#define N 1000000000
using namespace std;
typedef unsigned long long int ulli;
ulli sum;
/*void ways(ulli *arr, int m, int n, int prev, int cnt, ulli p){
	if(cnt == n){
		sum += p;
		sum %= N;
		//cout << " p=" << p << " done" << endl;
		return;
	}
	for(int i = prev ; i <= m ; i++){
		//cout << i << " ";
		ways(arr, m, n, i, cnt+1, (p * arr[i]) % N);
	}
}*/
/*int calc(int n, int r){
	ulli s, p;
	s = p = 1;
	for(int i = 1 ; i <= n-1 ; i++){
		s *= (ulli)(r+i);
		p *= (ulli)i;
		//s %= N;
		//p %= N;
	}
	s /= p;
	return s % N;
}*/
int main(){
	int t, n, m, k;
	ulli *arr, p, x;
	scanf("%d", &t);
	while(t--){
		sum = 0;
		scanf("%d%d", &n, &m);
		arr = new ulli[m+1];
		arr[0] = 1;
		k = m;
		for(int i = 1 ; i <= m ; i++){
			arr[i] = (arr[i-1] * k) / i;
			arr[i] %= N;
			k++;
		}
		//p = 1;
		/*for(int i = 0 ; i <= m ; i++)
			printf("%llu ", arr[i]);*/
		//cout << "\ndone" << endl;
		//ways(arr, m, n, 0, 0, p);
		//cout << sum << "\n";
		ulli **dp;
		dp = new ulli*[m+1];
		for(int i = 0 ; i <= m ; i++)
			dp[i] = new ulli[n];
		dp[m][0] = arr[m];
		for(int i = 1 ; i < n ; i++)
			dp[m][i] = (dp[m][i-1] * arr[m]) % N;
		for(int i = m-1 ; i >= 0 ; i--){
			for(int j = 0 ; j < n ; j++){
				dp[i][j] = dp[i+1][j];
				x = arr[i];
				if(j > 0){
					x = x * dp[i][j-1];
					x = x % N;
				}
				dp[i][j] += x;
				dp[i][j] %= N;
				/*x = 1;
				for(int k = j-1 ; k >= 0 ; k--){
					x = (x * arr[i]) % N;
					dp[i][j] += (x * dp[i+1][k]) % N;
					dp[i][j] %= N;
				}*/
			}
		}
		/*for(int i = 0 ; i <= m ; i++){
			for(int j = 0 ; j < m ; j++){
				printf("%2llu ", dp[i][j]);
			}
			printf("\n");
		}*/
		cout << dp[0][n-1] << endl;
	}
	return 0;
}