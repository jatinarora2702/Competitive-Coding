#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define FF first
#define SS second

#define N 100005

using namespace std;

typedef pair < int, int > pii;

int h[N], p[N];

int getP(int s) {
	if (p[s] == -1) {
		return s;
	}
	p[s] = getP(p[s]);
	return p[s];
}

int mst() {
	int n, m, x, y, wt;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		h[i] = 0;
		p[i] = -1;
	}
	wt = 0;
	for(int i = 0; i < m; i++) {
		cin >> x >> y;
		x--;
		y--;
		int px = getP(x);
		int py = getP(y);
		if (px != py) {
			wt++;
			if (h[px] < h[py]) {
				p[px] = py;
			}
			else if (h[px] > h[py]) {
				p[py] = px;
			}
			else {
				p[py] = px;
				h[py]++;
			}
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if (p[i] == -1) {
			cnt++;
		}
	}
	cnt--;
	wt += (cnt * 2);
	return wt;
}

int main() {
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": " << mst() << "\n";
	}
	return 0;
}