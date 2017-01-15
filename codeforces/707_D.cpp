#include <bits/stdc++.h>
#define N 1005
#define M 100005
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;
int a[N][N], sum, c[N], f[N], b[M][4], m;
vector < int > g[M];

void dfs_visit(int s) {
	int ai, aj, ch, x, i;
	ch = 0;
	if(b[s][0] == 1) {
		ai = b[s][1];
		aj = b[s][2];
		if(a[ai][aj] != f[ai]) {
			a[ai][aj] = f[ai];
			c[ai] = (f[ai] == 1) ? c[ai]+1 : c[ai]-1;
			sum++;
			ch = 1;
		}
	}
	else if(b[s][0] == 2) {
		ai = b[s][1];
		aj = b[s][2];
		if(a[ai][aj] != (f[ai]^1)) {
			a[ai][aj] = f[ai]^1;
			c[ai] = (f[ai] == 1) ? c[ai]-1 : c[ai]+1;
			ch = 1;
			sum--;
		}
	}
	else if(b[s][0] == 3) {
		ai = b[s][1];
		f[ai] ^= 1;
		x = 2*c[ai] - m;
		if(f[ai] == 1) {
			sum += x;
		}
		else {
			sum -= x;
		}
		ch = 1;
	}
	b[s][3] = sum;
	for(i = 0 ; i < g[s].size() ; i++) {
		dfs_visit(g[s][i]);
	}
	if(ch == 1) {
		if(b[s][0] == 1) {
			a[ai][aj] = f[ai]^1;
			c[ai] = (f[ai] == 1) ? c[ai]-1 : c[ai]+1;
			sum--;
		}
		else if(b[s][0] == 2) {
			a[ai][aj] = f[ai];
			c[ai] = (f[ai] == 1) ? c[ai]+1 : c[ai]-1;
			sum++;
		}
		else if(b[s][0] == 3) {
			f[ai] ^= 1;
			if(f[ai] == 1) {
				sum += x;
			}
			else {
				sum -= x;
			}
		}
	}
}

int main() {
	int n, q, i, ch, ai, aj;
	scanf("%d%d%d", &n, &m, &q);
	b[0][0] = 4;
	for(i = 1 ; i <= q ; i++) {
		scanf("%d", &ch);
		b[i][0] = ch;
		if(ch == 1 || ch == 2) {
			scanf("%d%d", &ai, &aj);
			b[i][1] = ai - 1;
			b[i][2] = aj - 1;
			g[i-1].PB(i);
		}
		else if(ch == 3) {
			scanf("%d", &ai);
			b[i][1] = ai - 1;
			g[i-1].PB(i);
		}
		else if(ch == 4) {
			scanf("%d", &ai);
			g[ai].PB(i);
		}
	}
	for(i = 0 ; i < n ; i++) {
		f[i] = 1;
	}
	sum = 0;
	dfs_visit(0);
	for(i = 1 ; i <= q ; i++) {
		printf("%d\n", b[i][3]);
	}
	return 0;
}