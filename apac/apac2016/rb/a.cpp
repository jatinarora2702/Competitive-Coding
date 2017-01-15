#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define N 505
#define M 2005

using namespace std;
typedef long long int lli;
typedef long double ld;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

int e[M][30], v[N], d[30][N], a[30], n;
vector < pii > g[N];
priority_queue < pii, vector < pii >, greater < pii > > pq;

int calc(int time, int loc) {
	pii p, q;
	int tempd, i;
	if(a[time] == 0) {
		a[time] = 1;
		while(!pq.empty()) {
			pq.pop();
		}
		for(i = 0 ; i < n ; i++) {
			v[i] = 0;
			d[time][i] = INF;
		}
		pq.push(MP(0, 0));
		while(!pq.empty()) {
			p = pq.top();
			pq.pop();
			if(v[p.FF] == 0) {
				v[p.FF] = 1;
				d[time][p.FF] = p.SS;
				for(i = 0 ; i < g[p.FF].size() ; i++) {
					q = g[p.FF][i];
					if(v[q.FF] == 0) {
						tempd = p.SS + e[q.SS][(time+p.SS) % 24];
						if(tempd < d[time][q.FF]) {
							pq.push(MP(q.FF, tempd));
						}
					}
				}
			}
		}
		for(i = 0 ; i < n ; i++) {
			if(v[i] == 0 || d[time][i] == INF) {
				d[time][i] = -1;
			}
		}
	}
	return d[time][loc];
}

int main() {
	int t, m, k, h, x, y, i, j;
	scanf("%d", &t);
	h = 0;
	while(t--) {
		h++;
		scanf("%d%d%d", &n, &m, &k);
		for(i = 0 ; i < n ; i++) {
			g[i].clear();
		}
		for(i = 0 ; i < m ; i++) {
			scanf("%d%d", &x, &y);
			for(j = 0 ; j < 24 ; j++) {
				scanf("%d", &e[i][j]);
			}
			x--, y--;
			g[x].PB(MP(y, i));
			g[y].PB(MP(x, i));
		}
		for(i = 0 ; i < 24 ; i++) {
			a[i] = 0;
		}
		printf("Case #%d: ", h);
		for(i = 0 ; i < k ; i++) {
			scanf("%d%d", &x, &y);
			x--;
			printf("%d ", calc(y, x));
		}
		printf("\n");
	}
	return 0;
}