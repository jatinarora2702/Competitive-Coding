#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define FF first
#define SS second

#define N 105
#define M 15

using namespace std;

typedef long long int lli;
const int INF = 1e9+7;

int dp[N][M][M], a[M], b[N], c[2][M];
int main() {
	int i, j, k, l, m, f, pos;
	char w[M];
	scanf("%s%d", w, &m);
	for(i = 0 ; w[i] != '\0' ; i++) {
		a[i] = w[i] - '0';
	}
	f = 0;
	for(j = 0 ; j <= 10 ; j++) {
		c[0][j] = 1;
	}
	for(i = 0 ; i < m ; i++) {
		for(j = 0 ; j <= 10 ; j++) {
			if(c[f][j] == 1) {
				for(k = j ; k < 10 ; k++) {
					if(a[k] != 0) {
						dp[i][j][k] = k-(j-1);
						c[f^1][k-(j-1)] = 1;
					}
				}
			}
			c[f][j] = 0;
		}
		f ^= 1;
	}
	for(i = 0 ; i < m ; i++) {
		for(j = 0 ; j <= 10 ; j++) {
			for(k = 0 ; k < 10 ; k++) {
				printf("%d ", dp[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	pos = -1;
	for(j = 0 ; j <= 10 ; j++) {
		for(k = j ; k < 10 ; k++) {
			if(dp[m-1][j][k] > 0) {
				b[l++] = k;
				pos = j;
				break;
			}
		}
		if(pos != -1)
			break;
	}
	if(pos == -1) {
		printf("NO\n");
	}
	else {
		for(i = m-2 ; i >= 0 ; i--) {
			for(k = pos ; k < 10 ; k++) {
				if(a[k] != 0 && dp[i][pos][k] > 0) {
					b[l++] = k;
					pos = dp[i][pos][k];
					break;
				}
			}	
		}
		printf("YES\n");
		for(i = l-1 ; i >= 0 ; i--) {
			printf("%d ", b[i]+1);
		}
		printf("\n");
	}
	return 0;
}