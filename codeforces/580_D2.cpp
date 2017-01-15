#include <bits/stdc++.h>
#define FF first
#define SS second
using namespace std;
typedef long long int lli;
int satis[20], valid[20], psatis[20][20];
lli dp[1<<19][20];
int main() {
	int n, m, k, k1, val, t1, t2;
	lli maxm;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &satis[i]);
	for(int i = 0 ; i < k ; i++){
		scanf("%d%d", &t1, &t2);
		t1--;
		t2--;
		scanf("%d", &psatis[t1][t2]);
	}
	for(int i = 0 ; i < 1<<n ; i++){
		for(int j = 0 ; j < n ; j++)
			valid[j] = (i & (1 << j)) ? 1 : 0;
		if(__builtin_popcount(i) == 1){
			for(int j = 0 ; j < n ; j++){
				if(valid[j] == 1)
					dp[i][j] = satis[j];
			}
		}
		for(int j = 0 ; j < n ; j++){
			if(valid[j] == 1){
				for(int k2 = 0 ; k2 < n ; k2++){
					if(valid[k2] == 0){
						dp[i | 1<<k2][k2] = max(dp[i | 1<<k2][k2], dp[i][j] + (lli)satis[k2] + (lli)psatis[j][k2]);
					}
				}
			}
		}
	}
	maxm = -1;
	for(int i = 0 ; i < 1<<n ; i++){
		if(__builtin_popcount(i) == m){
			for(int j = 0 ; j < n ; j++)
				maxm = max(maxm, dp[i][j]);
		}
	}
	cout << maxm;
	return 0;
}