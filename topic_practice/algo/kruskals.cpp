#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define N 100005

using namespace std;

typedef struct _edge {
	int x, y, wt;
	bool operator<(const struct _edge& e) const {
		return wt < e.wt;
	}
} edge;

vector < edge > v, mst;
int p[N], r[N];

int getP(int s) {
	if (p[s] == -1) {
		return s;
	}
	p[s] = getP(p[s]);
	return p[s];
}

int main() {
	int n, m, x, y, z, w;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		edge e = {x, y, z};
		v.PB(e);
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++) {
		p[i] = -1;
		r[i] = 0;
	}
	w = 0;
	for(int i = 0; i < v.size(); i++) {
		int px = getP(v[i].x);
		int py = getP(v[i].y);
		if (px != py) {
			mst.PB(v[i]);
			w += v[i].wt;
			if (r[px] > r[py]) {
				p[py] = px;
			}
			else if (r[py] > r[px]) {
				p[px] = py;
			}
			else {
				p[py] = px;
				r[px]++;
			}
		}
	}
	cout << "wt: " << w << "\n";
	cout << "mst:\n";
	for(int i = 0; i < mst.size(); i++) {
		cout << mst[i].x << " " << mst[i].y << " " << mst[i].wt << "\n";
	}
	return 0;
}