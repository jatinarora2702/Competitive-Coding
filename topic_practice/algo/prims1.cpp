#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back

#define N 1005

using namespace std;

typedef pair<int, int> pii;

class edge {
public:
	int x, y, z;
	const bool operator<(const edge& e) const {
		return this->z > e.z;
	}
};

vector<pii> g[N], t[N];
vector<int> v(N, 0);
priority_queue<edge> pq;

int main() {
	int n, m, x, y, z, d;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		g[x].PB(MP(y, z));
		g[y].PB(MP(x, z));
	}
	v[0] = 1;
	for(int i = 0; i < g[0].size(); i++) {
		edge e = {0, g[0][i].FF, g[0][i].SS};
		pq.push(e);
	}
	d = 0;
	while(!pq.empty()) {
		edge e = pq.top();
		pq.pop();
		x = e.x;
		y = e.y;
		z = e.z;
		if (v[y] == 1) {
			continue;
		}
		v[y] = 1;
		t[x].PB(MP(y, z));
		t[y].PB(MP(x, z));
		d += z;
		for(int i = 0; i < g[y].size(); i++) {
			int r = g[y][i].FF;
			int w = g[y][i].SS;
			if (v[r] == 0) {
				edge ne = {y, r, w};
				pq.push(ne);
			}
		}
	}
	cout << "tree:\n";
	for(int i = 0; i < n; i++) {
		cout << i << ": ";
		for(int j = 0; j < t[i].size(); j++) {
			cout << "(" << t[i][j].FF << ", " << t[i][j].SS << ") ";
		}
		cout << "\n";
	}
	cout << "dist: " << d << "\n";
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
tree:
0: (1, 4) (7, 8)
1: (0, 4)
2: (5, 4) (8, 2) (3, 7)
3: (2, 7) (4, 9)
4: (3, 9)
5: (6, 2) (2, 4)
6: (7, 1) (5, 2)
7: (0, 8) (6, 1)
8: (2, 2)
dist: 37
*/
