#include <bits/stdc++.h>
#define PB push_back
#define N 200005

using namespace std;

// right things happen at the right time for the right people..

vector < int > g[N];
vector < vector < int > > a;
int v[N], b[N], c[N];

void dfs(int s, vector < int > &vec, int index) {
	vec.PB(s);
	b[s] = index;
	v[s] = 1;
	for(int i = 0; i < g[s].size(); i++) {
		if (v[g[s][i]] == 0) {
			dfs(g[s][i], vec, index);
		}
	}
}

int main() {
	int n, m, x, y;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> x >> y;
		x--;
		y--;
		g[x].PB(y);
		g[y].PB(x);
	}
	for(int i = 0; i < n; i++) {
		if(v[i] == 0) {
			vector < int > comp;
			dfs(i, comp, a.size());
			a.PB(comp);
		}
	}
	int i = 0;
	int prev = -1;
	int maxm = -1;
	int cnt = 0;
	for(i = 0; i < a.size(); i++) {
		if (c[i] == 1) {
			continue;
		}
		if (prev == -1) {
			int minm = N;
			for(int j = 0; j < a[i].size(); j++) {
				maxm = max(maxm, a[i][j]);
				minm = min(minm, a[i][j]);
			}
			if (prev < minm-1) {
				prev = minm-1;
			}
		}
		int f = 0;
		int newmaxm = maxm;
		// cout << " maxm=" << maxm << " prev=" << prev << " i=" << i << "\n";
		for(int j = prev+1; j <= maxm; j++) {
			int l = b[j];
			if (l != i) {
				cnt++;
				// cout << "l=" << l << " i=" << i << "\n";
				c[l] = 1;
				for(int k = 0; k < a[l].size(); k++) {
					b[a[l][k]] = i;
					newmaxm = max(newmaxm, a[l][k]);
					a[i].PB(a[l][k]);
				}
				f = 1;
			}
		}
		if (f == 1) {
			i--;
			prev = maxm;
			maxm = newmaxm;
		}
		else {
			prev = -1;
		}
	}
	cout << cnt << "\n";
	return 0;
}