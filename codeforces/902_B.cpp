#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define FF first
#define SS second

using namespace std;

typedef vector < int > vi;

const int N = 11000;

vi g[N];
int c[N], cnt;

void dfs(int s, int p) {
	int i;
	if (c[s] != c[p])
		cnt++;
	for(i = 0 ; i < g[s].size() ; i++) {
		if (g[s][i] != p)
			dfs(g[s][i], s);
	}
}

int main() {
	int n, i, p;
	scanf("%d", &n);
	for(i = 0 ; i < n - 1 ; i++) {
		scanf("%d", &p);
		p--;
		g[i + 1].PB(p);
		g[p].PB(i + 1);
	}
	for(i = 0 ; i < n ; i++) 
		scanf("%d", &c[i]);
	cnt = 1;
	dfs(0, 0);
	printf("%d\n", cnt);
	return 0;
}