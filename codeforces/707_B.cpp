#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define N 100005
const int INF = 1e9 + 7;
using namespace std;
int a[N];
vector < pair < int, int > > g[N];
map < int, int > mp;
int main() {
	int n, k, m, x, y, z, i, j, minm;
	scanf("%d%d%d", &n, &m, &k);
	for(i = 0 ; i < m ; i++) {
		scanf("%d%d%d", &x, &y, &z);
		x--;
		y--;
		g[x].PB(MP(y, z));
		g[y].PB(MP(x, z));
	}
	for(i = 0 ; i < k ; i++) {
		scanf("%d", &a[i]);
		a[i]--;
		mp[a[i]] = 1;
	}
	for(i = 0 ; i < n ; i++) {
		mp[i]++;
	}
	minm = INF;
	for(i = 0 ; i < k ; i++) {
		for(j = 0 ; j < g[a[i]].size() ; j++) {
			if(mp[g[a[i]][j].FF] == 1)
				minm = min(minm, g[a[i]][j].SS);
		}
	}
	if(minm == INF) {
		printf("-1\n");
	}
	else
		printf("%d\n", minm);
	return 0;
}