#include <bits/stdc++.h>
using namespace std;

bool hasCycle(vector<vector<int>>& g, vector<int>& v, int s, int p) {
	v[s] = 1;
	for(int i = 0; i < g[s].size(); i++) {
		int k = g[s][i];
		if (k == p) {
			continue;
		}
		if (v[k] == 1) {
			return true;
		}
		if (v[k] == 0) {
			bool f = hasCycle(g, v, k, s);
			if (f) {
				return true;
			}
		}
	}
	v[s] = 2;
	return false;
}

int main() {
	int n, m, x, y;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for(int i = 0; i < m; i++) {
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	bool f = false;
	vector<int> v(n, 0);
	for(int i = 0; i < n; i++) {
		if (v[i] == 0) {
			f = hasCycle(g, v, i, -1);
			if (f) {
				break;
			}
		}
	}
	cout << "Has Cycle: " << (f ? "Yes\n" : "No\n");
	return 0;
}