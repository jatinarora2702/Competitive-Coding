#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define N 100005

using namespace std;

typedef pair < int, int > pii;

typedef struct _entry {
	int x, y, wt;

	bool operator<(const struct _entry& e) const {
		return wt > e.wt;
	}
} entry;

vector < pii > g[N];
vector < entry > mst;
int v[N];
priority_queue < entry, vector < entry > > pq;

int main() {
	int n, m, x, y, z, w;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		g[x].PB(MP(y, z));
		g[y].PB(MP(x, z));
	}
	v[0] = 1;
	for(int j = 0; j < g[0].size(); j++) {
		entry e = {0, g[0][j].FF, g[0][j].SS};
		pq.push(e);
	}
	w = 0;
	while(!pq.empty()) {
		entry e = pq.top();
		pq.pop();
		if (v[e.x] == 0 || v[e.y] == 0) {
			mst.PB(e);
			w += e.wt;
			if (v[e.x] == 0) {
				v[e.x] = 1;
				for(int j = 0; j < g[e.x].size(); j++) {
					entry ne = {e.x, g[e.x][j].FF, g[e.x][j].SS};
					pq.push(ne);
				}
			}
			else {
				v[e.y] = 1;
				for(int j = 0; j < g[e.y].size(); j++) {
					entry ne = {e.y, g[e.y][j].FF, g[e.y][j].SS};
					pq.push(ne);
				}
			}
		}
	}
	cout << "mst:\n";
	for(int i = 0; i < mst.size(); i++) {
		cout << mst[i].x << " " << mst[i].y << " " << mst[i].wt << "\n";
	}
	cout << "wt: " << w << "\n";
	return 0;
}