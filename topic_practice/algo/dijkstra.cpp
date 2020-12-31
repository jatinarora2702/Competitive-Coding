#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

#define N 100005

using namespace std;

typedef pair < int, int > pii;

const int INF = 1e9 + 7;

vector < pii > g[N];
priority_queue < pii, vector < pii >, greater < pii > > pq;
int d[N], v[N];

int main() {
	int n, m, x, y, z, s;
	cin >> n >> m;
	for(int i = 0 ; i < m; i++) {
		cin >> x >> y >> z;
		g[x].PB(MP(y, z));
		g[y].PB(MP(x, z));
	}
	cin >> s;
	for(int i = 0; i < n; i++) {
		d[i] = INF;
		v[i] = 0;
	}
	d[s] = 0;
	pq.push(MP(0, s));
	while(!pq.empty()) {
		pii p = pq.top();
		pq.pop();
		if (v[p.SS] == 1) {
			continue;
		}
		v[p.SS] = 1;
		for(int i = 0; i < g[p.SS].size(); i++) {
			pii pi = g[p.SS][i];
			if (d[pi.FF] > p.FF + pi.SS) {
				d[pi.FF] = p.FF + pi.SS;
				pq.push(MP(d[pi.FF], pi.FF));
			}
		}
	}
	cout << "d: ";
	for(int i = 0; i < n; i++) {
		cout << d[i] << " ";
	}
	cout << "\n";
	return 0;
}