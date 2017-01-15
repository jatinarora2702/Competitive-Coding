#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

#define N 1005

int a1[N][N], a2[N][N], a3[N][N], a4[N][N], a[N][N];
int main() {
	int t, n, m, minm, i, j;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		for(i = 0 ; i < n ; i++) {
			for(j = 0 ; j < m ; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		for(i = 0 ; i < n ; i++) {
			a1[i][0] = a[i][0];
			for(j = 1 ; j < m ; j++) {
				a1[i][j] = min(a1[i][j-1], 0) + a[i][j];
			}
		}
		for(i = 0 ; i < n ; i++) {
			a2[i][m-1] = a[i][m-1];
			for(j = m-2 ; j >= 0 ; j--) {
				a2[i][j] = min(a2[i][j+1], 0) + a[i][j];
			}
		}
		for(j = 0 ; j < m ; j++) {
			a3[0][j] = a[0][j];
			for(i = 1 ; i < n ; i++) {
				a3[i][j] = min(a3[i-1][j], 0) + a[i][j];
			}
		}
		for(j = 0 ; j < m ; j++) {
			a4[n-1][j] = a[n-1][j];
			for(i = n-2 ; i >= 0 ; i--) {
				a4[i][j] = min(a4[i+1][j], 0) + a[i][j];
			}
		}
		minm = INF;
		for(i = 0 ; i < n ; i++) {
			for(j = 0 ; j < m ; j++) {
				minm = min(minm, a1[i][j] + a2[i][j] + a3[i][j] + a4[i][j] - 3 * a[i][j]);
			}
		}
		printf("%d\n", minm);
	}
	return 0;
}