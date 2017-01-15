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

typedef struct _qnode {
	int time;
	int pos;
	int dist;
	bool operator < (const _qnode& qn) const {
		return dist > qn.dist;
	}
}qnode;

int e[M][30], v[N][30], dist[30][N], d[N][30], a[30], n;
vector < pii > g[N];
priority_queue < qnode > pq;

int calc(int stime, int loc) {
	qnode p;
	pii q;
	int tempd, tempt, i, j;
	if(a[stime] == 0) {
		a[stime] = 1;
		for(i = 0 ; i < n ; i++) {
			for(j = 0 ; j < 24 ; j++) {
				v[i][j] = 0;
				d[i][j] = INF;
			}
			dist[stime][i] = INF;
		}
		while(!pq.empty()) {
			pq.pop();
		}
		pq.push({stime, 0, 0});
		while(!pq.empty()) {
			p = pq.top();
			pq.pop();
			if(v[p.pos][p.time] == 0) {
				v[p.pos][p.time] = 1;
				for(i = 0 ; i < g[p.pos].size() ; i++) {
					q = g[p.pos][i];
					tempt = p.time + e[q.SS][p.time];
					tempt %= 24;
					tempd = p.dist + e[q.SS][p.time];
					if(v[q.FF][tempt] == 0 && d[q.FF][tempt] > tempd) {
						d[q.FF][tempt] = tempd;
						pq.push({tempt, q.FF, tempd});
					}
				}
			}
		}
		for(i = 0 ; i < n ; i++) {
			for(j = 0 ; j < 24 ; j++) {
				dist[stime][i] = min(dist[stime][i], d[i][j]);
			}
			if(dist[stime][i] == INF)
				dist[stime][i] = -1;
		}
	}
	return dist[stime][loc];
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