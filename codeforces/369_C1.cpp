#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

using namespace std;

typedef pair < int, int > pii;

const int N = 100005;

vector < pii > g[N];
vector < int > v;

int dfs(int s, int p, int f) {
	int i, k;
	k = 0;
	for(i = 0 ; i < g[s].size() ; i++) {
		if(g[s][i].FF != p)
			k += dfs(g[s][i].FF, s, g[s][i].SS);
	}
	if(f == 1 && k == 0) {
		k++;
		v.PB(s);
	}
	return k;
}

int main() {
	int n, i, x, y, t;
	scanf("%d", &n);
	for(i = 0 ; i < n-1 ; i++) {
		scanf("%d%d%d", &x, &y, &t);
		x--;
		y--;
		t--;
		g[x].PB(MP(y, t));
		g[y].PB(MP(x, t));
	}
	dfs(0, -1, 0);
	printf("%lu\n", v.size());
	for(i = 0 ; i < v.size() ; i++)
		printf("%d ", v[i]+1);
	printf("\n");
	return 0;
}