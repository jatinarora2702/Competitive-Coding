#include <bits/stdc++.h>
#define N 9000025
#define M 3005

using namespace std;

typedef long long int lli;

int n, m, a, b, g0, x, y, z, g[N], h[M][M], seg[M][4*M], run[M], runseg[4*M];

void makeinps() {
	int i, j, k;
	g[0] = g0;
	for(i = 1; i < m*n; i++) {
		g[i] = ((lli)g[i-1] * x + y) % z;
	}
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			k = i * m + j;
			h[i][j] = g[k];
		}
	}
}

void makesegtree(int s, int ss, int se, int si) {
	int sm;
	if (ss == se) {
		seg[s][si] = h[ss][s];
		return;
	}
	sm = (ss + se) / 2;
	makesegtree(s, ss, sm, 2*si);
	makesegtree(s, sm+1, se, 2*si+1);
	seg[s][si] = min(seg[s][2*si], seg[s][2*si+1]);
}

int querysegtree(int s, int ss, int se, int qs, int qe, int si) {
	int sm;
	if (qs > se || qe < ss) {
		return z;
	}
	if (ss >= qs && se <= qe) {
		return seg[s][si];
	}
	sm = (ss + se) / 2;
	return min(querysegtree(s, ss, sm, qs, qe, 2*si), querysegtree(s, sm+1, se, qs, qe, 2*si+1));
}

void preprocess() {
	int j;
	for(j = 0; j < m; j++) {
		makesegtree(j, 0, n-1, 1);
	}
}

// lli calc() {		// heap based implementation
// 	int i, j;
// 	lli s;
// 	s = 0LL;
// 	for(i = 0; i <= n-a; i++) {
// 		while(!pq.empty()) {
// 			pq.pop();
// 		}
// 		for(j = 0; j < b; j++) {
// 			pq.push(querysegtree(j, 0, n-1, i, i+a-1, 1));
// 		}
// 		s += pq.top();
// 		for(j = b; j < m; j++) {
// 			pq.pop();
// 			pq.push(querysegtree(j, 0, n-1, i, i+a-1, 1));
// 			s += pq.top();
// 		}
// 	}
// 	return s;
// }

void makerunsegtree(int ss, int se, int si) {
	int sm;
	if (ss == se) {
		runseg[si] = run[ss];
		return;
	}
	sm = (ss + se) / 2;
	makerunsegtree(ss, sm, 2*si);
	makerunsegtree(sm+1, se, 2*si+1);
	runseg[si] = min(runseg[2*si], runseg[2*si+1]);
}

int queryrunseqtree(int ss, int se, int qs, int qe, int si) {
	int sm;
	if (qs > se || qe < ss) {
		return z;
	}
	if (ss >= qs && se <= qe) {
		return runseg[si];
	}
	sm = (ss + se) / 2;
	return min(queryrunseqtree(ss, sm, qs, qe, 2*si), queryrunseqtree(sm+1, se, qs, qe, 2*si+1));
}

void updaterunsegtree(int ss, int se, int k, int si) {
	int sm;
	if (k < ss || k > se) {
		return;
	}
	if (ss == se) {
		runseg[si] = run[k];
		return;
	}
	sm = (ss + se) / 2;
	updaterunsegtree(ss, sm, k, 2*si);
	updaterunsegtree(sm+1, se, k, 2*si+1);
	runseg[si] = min(runseg[2*si], runseg[2*si+1]);
}

lli calc() {
	int i, j, k;
	lli s;
	s = 0LL;
	for(i = 0; i <= n-a; i++) {
		for(j = 0; j < b; j++) {
			run[j] = querysegtree(j, 0, n-1, i, i+a-1, 1);
		}
		makerunsegtree(0, b-1, 1);
		s += queryrunseqtree(0, b-1, 0, b-1, 1);
		for(j = b; j < m; j++) {
			k = j % b;
			run[k] = querysegtree(j, 0, n-1, i, i+a-1, 1);
			updaterunsegtree(0, b-1, k, 1);
			s += queryrunseqtree(0, b-1, 0, b-1, 1);
		}
	}
	return s;
}

int main() {
	cin >> n >> m >> a >> b >> g0 >> x >> y >> z;
	makeinps();
	preprocess();
	cout << calc() << "\n";
	return 0;
}