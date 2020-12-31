#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e9 + 7;

struct Entry {
	int s, p, w;
	Entry(int _s, int _p, int _w) {
		this->s = _s;
		this->p = _p;
		this->w = _w;
	}
};

struct Compare {
	bool operator()(const struct Entry& p, const struct Entry& q) {
		return p.w > q.w;
	}
};

void dijkstra(vector<vector<pii>>& g, int s, vector<int>& ans, vector<int>& parent) {
	priority_queue<struct Entry, vector<struct Entry>, Compare> pq;
	pq.push(Entry(s, -1, 0));
	while(!pq.empty()) {
		struct Entry e = pq.top();
		pq.pop();
		if (e.w < ans[e.s]) {
			ans[e.s] = e.w;
			parent[e.s] = e.p;
			for(int i = 0; i < g[e.s].size(); i++) {
				pii tmp = g[e.s][i];
				pq.push(Entry(tmp.first, e.s, e.w + tmp.second));
			}
		}
	}
}

int main() {
	int n, m, x, y, z, s;
	cin >> n >> m;
	vector<vector<pii>> g(n);
	for(int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		g[x].push_back(make_pair(y, z));
		g[y].push_back(make_pair(x, z));
	}
	cin >> s;
	vector<int> ans(n, INF);
	vector<int> parent(n, -1);
	dijkstra(g, s, ans, parent);
	
	cout << "dist: ";
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	cout << "parent: ";
	for(int i = 0; i < parent.size(); i++) {
		cout << parent[i] << " ";
	}
	cout << "\n";
	
	return 0;
}

/*
inp:
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 5 4
2 8 2
3 4 9
2 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
0

out:
dist: 0 4 12 19 21 11 9 8 14
parent: -1 0 1 2 5 6 7 0 2
*/