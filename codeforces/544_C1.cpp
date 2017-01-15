#include <iostream>
#include <stdio.h>
using namespace std;
typedef unsigned long long int ulli;
int mod, a[500];
/*int ways(int ***dp, int n, int m , int b){
	int max;
	ulli sum;
	if(b < 0 or m < 0)
		return 0;
	if(dp[n][m][b] == -1){
		if(n == 0 and m == 0){
			dp[n][m][b] = 1;
			return 1;
		}
		if(n == 0 and m > 0){
			dp[n][m][b] = 0;
			return 0;
		}
		max = b / a[n-1];
		sum = 0;
		for(int i = 0 ; i <= max ; i++){
			sum += (ulli)ways(dp, n-1, m-i, b - i*a[n-1]);
			sum %= mod;
		}
		dp[n][m][b] = sum;	
	}
	return dp[n][m][b];
}*/
int main(){
	int n, m, b, max;
	scanf("%d%d%d%d", &n, &m, &b, &mod);
	int **dp, **dp1;
	ulli sum;
	dp = new int*[m+1];
	dp1 = new int*[m+1];
	for(int i = 0 ; i <= m ; i++){
		dp[i] = new int[b+1];
		dp1[i] = new int[b+1];
	}

	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	//cout << "oo\n";	
	for(int k = 0 ; k <= b ; k++)
		dp1[0][k] = 1;
	//cout << "apapa\n";
	for(int j = 1 ; j <= m ; j++){
		for(int k = 0 ; k <= b ; k++){
			dp1[j][k] = 0;
			//cout << "qq\n";
		}
		//cout << "ww\n";
	}
	//cout << "alal\n";
	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ;j <= m ; j++){
			for(int k = 0 ; k <= b ; k++){
				//cout << "reaching..\n";
				max = k / a[i-1];
				//cout << "max=" << max << endl;
				sum = 0;
				for(int l = 0 ; l <= max ; l++){
					if(j-l<0 or b-l*a[i-1]<0)
						break;
					sum += (ulli)dp1[j-l][b-l*a[i-1]];
					sum %= mod;
				}
				dp[j][k] = sum;
			}
		}
		for(int j = 0 ; j <= m ; j++){
			for(int k = 0 ;k <= b ; k++){
				dp1[j][k] = dp[j][k];
			}
		}
	}
	//cout << "allotted\n";
	
	printf("%d",dp[m][b]);
	return 0;
}