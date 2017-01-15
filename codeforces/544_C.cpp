#include <iostream>
#include <stdio.h>
using namespace std;
typedef unsigned long long int ulli;
int main(){
	int n, m, b, mod, *a;
	ulli **dp;
	scanf("%d%d%d%d", &n, &m, &b, &mod);
	a = new int[n];
	dp = new ulli*[m+1];
	for(int i = 0 ; i <= m ; i++)
		dp[i] = new ulli[b+1];
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	for(int i = 0 ; i <= b ; i++){
		dp[1][i] = 0;
	}
	for(int i = 0 ; i < n ; i++){
		dp[1][a[i]]++;
	}
	for(int i = 0 ; i <= b ; i++){
		dp[1][i] %= (ulli)mod;
	}
	for(int i = 2 ; i <= m ; i++){
		for(int j = 0 ; j <= b ; j++){
			dp[i][j] = 0;
			for(int k = 0 ; k <= j ; k++){
				dp[i][j] += ((dp[i-1][k] * dp[1][j-k]) % (ulli)mod);
			}
			dp[i][j] %= (ulli)mod;
		}
	}
	for(int i = 0 ; i <= m ; i++){
		for(int j = 0 ; j <= b ; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << dp[m][b];
	return 0;
}