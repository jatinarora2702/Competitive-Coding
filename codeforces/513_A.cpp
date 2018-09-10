#include <bits/stdc++.h>
#define N 105
using namespace std;

typedef long long int lli;

const int INF = 1e9 + 7;

int dp[N][N][2];

int main() {
	int n1, n2, k1, k2, i;
	cin >> n1 >> n2 >> k1 >> k2;

	for(i = 0 ; i < n1 ; i++) {
		dp[i][0][1] = 0;
	}
	for(i = 0 ; i < n2 ; i++) {
		dp[0][i][0] = 1;
	}
	for(i = 1 ; i < n1 ; i++) {
		for(j = 1 ; j < n2 ; j++) {
			s = 0;
			for(k = 0 ; k < )
		}
	}
}