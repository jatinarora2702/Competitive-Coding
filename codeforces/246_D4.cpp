#include <bits/stdc++.h>
#define PB push_back

using namespace std;

const int N = 100005;

vector < int > g[N];
set < int > st[N], cs;
int c[N], v[N];

void dfs(int s) {
	int i, k;
	v[s] = 1;
	for(i = 0 ; i < g[s].size() ; i++) {
		k = g[s][i];
		if (c[s] != c[k]) {
			st[c[s]].insert(c[k]);
			st[c[k]].insert(c[s]);
		}
		if(v[k] == 0)
			dfs(k);
	}
}

int main() {
	int n, m, i, maxm, x, y;
	scanf("%d%d", &n, &m);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &c[i]);
		c[i]--;
		cs.insert(c[i]);
	}
	for(i = 0 ; i < m ; i++) {
		scanf("%d%d", &x, &y);
		x--;
		y--;
		g[x].PB(y);
		g[y].PB(x);
	}
	for(i = 0 ; i < n ; i++) {
		if (v[i] == 0)
			dfs(i);
	}
	i = 0;
	for(auto &cc : cs) {
		if(i == 0 || st[maxm].size() < st[cc].size())
			maxm = cc;
		i++;
	}
	printf("%d\n", maxm+1);
	return 0;
}