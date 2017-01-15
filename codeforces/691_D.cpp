#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define N 1000005
using namespace std;

typedef long long int lli;
vector < int > g[N], vtemp, vt;
int v[N], n, m;
int a[N], b[N];

bool fn(int x, int y) {
	return x > y;
}

void dfs_visit(int s) {
	int i;
	// printf("%d\n", s);
	v[s] = 1;
	vtemp.PB(s);
	for(i = 0 ; i < g[s].size() ; i++) {
		if(v[g[s][i]] == 0)
			dfs_visit(g[s][i]);
	}
}

void dfs() {
	int i, j;
	for(i = 0 ; i < n ; i++) {
		v[i] = 0;
	}
	for(i = 0 ; i < n ; i++) {
		if(v[i] == 0) {
			vtemp.clear();
			dfs_visit(i);
			sort(vtemp.begin(), vtemp.end());
			vt.clear();
			// printf("[");
			for(j = 0 ; j < vtemp.size() ; j++) {
				// printf("%d ", vtemp[j]);
				vt.PB(a[vtemp[j]]);
			}
			// printf("]\n");
			sort(vt.begin(), vt.end(), fn);
			for(j = 0 ; j < vtemp.size() ; j++) {
				b[vtemp[j]] = vt[j];
			}
		}
	}
}

int main() {
	int i, x, y;
	scanf("%d%d", &n, &m);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
	}
	for(i = 0 ; i < m ; i++) {
		scanf("%d%d", &x, &y);
		x--;
		y--;
		g[x].PB(y);
		g[y].PB(x);
	}
	dfs();
	for(i = 0 ; i < n ; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");
	return 0;
}