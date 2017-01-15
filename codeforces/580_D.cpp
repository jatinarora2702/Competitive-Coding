#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int a[20], satis[20][20];
lli dp[1 << 18][20];
bool eaten[20], noteaten[20];
int main() {
	int n, m, k, x, y;
	lli maxm;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	for(int i = 0 ; i < k ; i++){
		scanf("%d%d", &x, &y);
		x--; y--;
		scanf("%d", &satis[y][x]);
	}
	for(int i = 0 ; i < (1 << n) ; i++){
		for(int j = 0 ; j < n ; j++){
			if(i & (1 << j)){
				eaten[j] = true;
				noteaten[j] = false;
			}
			else{
				eaten[j] = false;
				noteaten[j] = true;
			}
		}
		int cnt1 = __builtin_popcount(i);
		if(cnt1 == 1){
			for(int j = 0 ; j < n ; j++){
				if(eaten[j])
					dp[i][j] = a[j];
			}
		}
		for(int j = 0 ; j < n ; j++){
			if(eaten[j]){
				for(int k = 0 ; k < n ; k++){
					if(noteaten[k]){
						dp[i | (1 << k)][k] = max(dp[i | (1 << k)][k], dp[i][j] + (lli)satis[k][j] + (lli)a[k]);
					}
				}
			}
		}
	}
	maxm = -1;
	for(int i = 0 ; i < (1 << n) ; i++){
		int cnt1 = __builtin_popcount(i);
		if(cnt1 == m){
			for(int j = 0 ; j < n ; j++){
				maxm = max(maxm, dp[i][j]);
			}
		}
	}
	cout << maxm;
	return 0;
}