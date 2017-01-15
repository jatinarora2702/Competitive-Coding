#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define N 5005
using namespace std;

typedef struct _node {
	int cnt;
	int time;
	int previ;
	int prevj;
}node;

const int INF = 1e9 + 7;

vector < pair < int, int > > g[N];
map < int, node > g1[N];
vector < int > v, vtp, vans;
int visited[N], sizearr[N];
map < int, node > :: iterator it;

void toposort(int s) {
	int i;
	visited[s] = 1;
	for(i = 0 ; i < g[s].size() ; i++) {
		if(visited[g[s][i].FF] == 0) {
			toposort(g[s][i].FF);
		}
	}
	vtp.PB(s);
}

int myfind(map < int, node > &mp, int h) {
	for(auto it : mp) {
		if(it.SS.cnt == h) {
			return 1;
		}
	}
	return 0;
}

int main() {
	int n, m, t, i, x, y, z, xi, xj, ni, nj, j, k, x1, x2, maxm;
	scanf("%d%d%d", &n, &m, &t);
	for(i = 0 ; i < m ; i++) {
		scanf("%d%d%d", &x, &y, &z);
		x--, y--;
		g[x].PB(MP(y, z));
	}
	toposort(0);
	reverse(vtp.begin(), vtp.end());
	g1[vtp[0]][0].cnt = 0;
	g1[vtp[0]][0].time = 0;
	g1[vtp[0]][0].previ = g1[vtp[0]][0].prevj = -1;
	sizearr[vtp[0]] = 0;
	for(i = 0 ; i < vtp.size() ; i++) {
		if(vtp[i] == n-1) {
			break;
		}
		// it = g1[vtp[i]].begin() ; it != g1[vtp[i]].end() ; it++
		for(auto it : g1[vtp[i]]) {
			x1 = it.SS.time;
			x2 = it.SS.cnt;
			if(x1 == INF) {
				continue;
			}
			for(k = 0 ; k < g[vtp[i]].size() ; k++) {
				if(x1 + g[vtp[i]][k].SS <= t) {
					if(myfind(g1[g[vtp[i]][k].FF], x2+1)) {
						if(g1[g[vtp[i]][k].FF][x2+1].time > x1 + g[vtp[i]][k].SS) {
							g1[g[vtp[i]][k].FF][x2+1].cnt = x2+1;
							g1[g[vtp[i]][k].FF][x2+1].time = x1 + g[vtp[i]][k].SS;
							g1[g[vtp[i]][k].FF][x2+1].previ = vtp[i];
							// g1[g[vtp[i]][k].FF][x2+1].prevj =  j;
							sizearr[g[vtp[i]][k].FF] = max(sizearr[g[vtp[i]][k].FF], x2+1);
						}
					}
					else {
						g1[g[vtp[i]][k].FF][x2+1].cnt = x2+1;
						g1[g[vtp[i]][k].FF][x2+1].time = x1 + g[vtp[i]][k].SS;
						g1[g[vtp[i]][k].FF][x2+1].previ = vtp[i];
						// g1[g[vtp[i]][k].FF][x2+1].prevj =  j;
						sizearr[g[vtp[i]][k].FF] = max(sizearr[g[vtp[i]][k].FF], x2+1);
					}
				} 
			}
		}
	}
	maxm = -1;
	for(auto it : g1[n-1]) {
		if(maxm == -1 || it.SS.cnt > g1[n-1][maxm].cnt) {
			maxm = it.SS.cnt;
		}
	}
	xi = n-1;
	xj = maxm;
	while(xi != -1) {
		vans.PB(xi);
		xi = g1[xi][xj].previ;
		xj = xj-1;
	}
	cout << vans.size() << endl;
	for(i = vans.size()-1 ; i >= 0 ; i--) {
		printf("%d ", vans[i]+1);
	}
	printf("\n");
	return 0;
}