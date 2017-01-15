#include <bits/stdc++.h>
#define N 2005
using namespace std;
typedef long long int lli;
int ncr[2*N][N], dp[N][N];
const int mod = 1e9;
int main() {
	int t, n, m, l;
	lli t1, t2;
	for(int i = 0 ; i < N ; i++){
		ncr[i][0] = 1;
		ncr[i][i] = 1;
	}
	for(int i = 1 ; i < 2*N ; i++){
		l = min(i, N);
		for(int j = 1 ; j < l ; j++){
			t1 = (lli)ncr[i-1][j] + (lli)ncr[i-1][j-1];
			t1 %= (lli)mod;
			ncr[i][j] = t1;
		}
	}
	// for(int i = 0 ; i <= 100 ; i++){
	// 	for(int j = 0 ; j <= i ; j++){
	// 		cout << "[" << i << "][" << j << "]: " << ncr[i][j] << endl;
	// 	}
	// 	cout << endl;
	// }
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int j = 0 ; j <= m ; j++){
			dp[0][j] = ncr[m+j-1][j];
		}
		for(int i = 1 ; i < n ; i++){
			t2 = 0;
			for(int j = 0 ; j <= m ; j++){
				t2 += (lli)dp[i-1][j];
				t2 %= (lli)mod;
				t1 = t2;
				t1 *= (lli)ncr[m+j-1][j];
				t1 %= (lli)mod;
				dp[i][j] = t1;
			}
		}
		t1 = dp[n-1][0];
		for(int j = 1 ; j <= m ; j++){
			t1 += (lli)dp[n-1][j];
			t1 %= (lli)mod;
		}
		l = t1;
		printf("%d\n", l);
	}
	return 0;
}