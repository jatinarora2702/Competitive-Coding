#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 18;
const ll INF = 1e18 + 7LL;

int a[N], c[N][N], p[N];
ll dp[(1 << N) + 5][N][2];

int main() {
	int n, m, x, y, z, i, j, k, f, q, u, M;
	ll t;
	scanf("%d%d%d", &n, &m, &q);
	for(i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	for(i = 0 ; i < q ; i++) {
		scanf("%d%d%d", &x, &y, &z);
		x--;
		y--;
		c[x][y] = z;
	}
	M = (1 << n) + 5;
	p[0] = 1;
	for(i = 1 ; i < n ; i++)
		p[i] = p[i-1] * 2;
	for(i = 0 ; i < M ; i++) {
		for(j = 0 ; j < N ; j++)
			dp[i][j][0] = -INF;
	}
	for(i = 0 ; i < n ; i++)
		dp[p[i]][i][0] = a[i];
	f = 0;
	for(i = 1 ; i < m ; i++) {
		for(j = 0 ; j < M ; j++) {
			for(k = 0 ; k < n ; k++)
				dp[j][k][f^1] = -INF;
		}
		for(j = 0 ; j < M ; j++) {
			for(u = 0 ; u < n ; u++) {
				if (!(j & p[u])) {
					x = j | p[u];
					t = -INF;
					for(k = 0 ; k < n ; k++) {
						if(dp[j][k][f] != -INF)
							t = max(t, dp[j][k][f] + (ll)c[k][u]);
					}
					if (t != -INF)
						dp[x][u][f^1] = max(dp[x][u][f^1], t + (ll)a[u]);
				}
			}
		}
		f ^= 1;
	}
	t = -INF;
	for(i = 0 ; i < M ; i++) {
		for(j = 0 ; j < n ; j++)
			t = max(t, dp[i][j][f]);
	}
	printf("%lld\n", t);
	return 0;
}