#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

#define N 1005

using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9 + 7;

vector<pii> g[N];
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<int> d(N, INF);

int main() {
	int n, m, x, y, z;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		g[x].PB(MP(y, z));
		g[y].PB(MP(x, z));
	}
	cin >> x;
	d[x] = 0;
	pq.push(MP(0, x));
	while(!pq.empty()) {
		pii p = pq.top();
		pq.pop();
		z = p.FF;
		y = p.SS;
		if (d[y] < z) {
			continue;
		}
		for(int i = 0; i < g[y].size(); i++) {
			int t = g[y][i].FF;
			int w = g[y][i].SS;
			if (d[t] > d[y] + w) {
				d[t] = d[y] + w;
				pq.push(MP(d[t], t));
			}
		}
	}
	cout << "dist:\n";
	for(int i = 0; i < n; i++) {
		cout << d[i] << " ";
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
dist:
0 4 12 19 21 11 9 8 14
*/
