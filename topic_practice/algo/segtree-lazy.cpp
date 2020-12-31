#include <bits/stdc++.h>
#define N 100005

using namespace std;

int n, a[N], seg[4*N], lazy[4*N];

int getsum(int ss, int se, int qs, int qe, int si) {
	seg[si] += (se - ss + 1) * lazy[si];
	if (ss < se) {
		lazy[2*si+1] += lazy[si];
		lazy[2*si+2] += lazy[si];
	}
	lazy[si] = 0;
	if (qs > se || qe < ss) {
		return 0;
	}
	if (ss >= qs && se <= qe) {
		return seg[si];
	}
	int sm = (ss + se) / 2;
	return getsum(ss, sm, qs, qe, 2*si+1) + getsum(sm+1, se, qs, qe, 2*si+2);
}

void update(int ss, int se, int qs, int qe, int si, int v) {
	seg[si] += (se - ss + 1) * lazy[si];
	if (ss < se) {
		lazy[2*si+1] += lazy[si];
		lazy[2*si+2] += lazy[si];
	}
	lazy[si] = 0;
	if (qs > se || qe < ss) {
		return;
	}
	if (ss >= qs && se <= qe) {
		seg[si] += (se - ss + 1) * v;
		if (ss < se) {
			lazy[2*si+1] += v;
			lazy[2*si+2] += v;
		}
		return;
	}
	int sm = (ss + se) / 2;
	update(ss, sm, qs, qe, 2*si+1, v);
	update(sm+1, se, qs, qe, 2*si+2, v);
	seg[si] = seg[2*si+1] + seg[2*si+2];
}

void query() {
	int q, i, j, v;
	cout << "1. Update: Increase values in range i to j by v (1 i j v)\n";
	cout << "2. Query: Get sum of values in range i to j (2 i j)\n";
	cin >> q >> i >> j;
	if (q == 1) {
		cin >> v;
		update(0, n-1, i, j, 0, v);
	}
	else if (q == 2) {
		cout << getsum(0, n-1, i, j, 0) << "\n";
	}
}

void make(int ss, int se, int si) {
	lazy[si] = 0;
	if (ss == se) {
		seg[si] = a[ss];
		return;
	}
	int sm = (ss + se) / 2;
	make(ss, sm, 2*si+1);
	make(sm+1, se, 2*si+2);
	seg[si] = seg[2*si+1] + seg[2*si+2];
}

void inp() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

int main() {
	inp();
	make(0, n-1, 0);
	while(true) {
		query();
	}
	return 0;
}