#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define N 100005
using namespace std;

int n, q, m;
vector < int > a(N, 1);
vector < int > st(4 * N);
vector < int > lazy(4 * N, 0);
vector < set < int > > v(N);

int stinit(int ss, int se, int si) {
	if(ss > se)
		return -1;
	if(ss == se)
		st[si] = 1;
	else {
		int sm = (ss + se) / 2;
		st[si] = max(stinit(ss, sm, 2*si + 1), stinit(sm+1, se, 2*si + 2));
	}
	return st[si];
}

void init() {
	int i;
	for(i = 0; i < n; i++)
		v[1].PB(i);
	stinit(0, n-1, 0);
}

pair < int, int > getpos(int y, int x) {
	int l, h, tmp;
	l = -1;
	h = x;
	set < int > :: iterator it = v[y].upper_bound(x);
	if(it != v[y].end())
		h = *it - m;
	if(it != v[y].begin())
		l = *(it - 1) + 1;
	tmp = max(x - m + 1, 0);
	l = max(l, tmp);
	h = min(h, x);
	return MP(l, h);
}

void stupdate(int ss, int se, int us, int ue, int si, int diff) {
	if(ss > se)
		return;
	st[si] += lazy[si];
	if(ss < se) {
		lazy[2*si + 1] += lazy[si];
		lazy[2*si + 2] += lazy[si];
	}
	lazy[si] = 0;
	
	if(us > se || ue < ss)
		return;
	if(ss <= us && se >= ue) {
		st[si] += diff;
		if(ss < se) {
			lazy[2*si + 1] += diff;
			lazy[2*si + 2] += diff;
		}
	}
	int sm = (ss + se) / 2;
	stupdate(ss, sm, us, ue, 2*si + 1, diff);
	stupdate(sm + 1, se, us, ue, 2*si + 2, diff);
	st[si] = max(st[2*si + 1], st[2*si + 2]);
}

void handle_update(int x, int ynew) {
	int yold = a[x];
	a[x] = ynew;
	v[yold].erase(x);
	pair < int, int > pold = getpos(yold, x);
	pair < int, int > pnew = getpos(ynew, x);
	v[ynew].insert(x);
	if(pold.FF > x-m && pold.SS <= x && pold.FF <= pold.SS)
		stupdate(0, n-1, pold.FF, pold.SS, 0, -1);
	if(pnew.FF > x-m && pnew.SS <= x && pnew.FF <= pnew.SS)
		stupdate(0, n-1, pnew.FF, pnew.SS, 0, 1);
}

int stquery(int ss, int se, int qs, int qe, int si) {
	if(ss > se)
		return -1;
	st[si] += lazy[si];
	if(ss < se) {
		lazy[2*si + 1] += lazy[si];
		lazy[2*si + 2] += lazy[si];
	}
	lazy[si] = 0;
	if(se < qs || ss > qe)
		return -1;
	if(qs <= ss && qe >= se)
		return st[si];
	int sm = (ss + se) / 2;
	return max(stquery(ss, sm, qs, qe, 2*si + 1), 
		stquery(sm + 1, se, qs, qe, 2*si + 2));
}

int handle_query(int l, int r) {
	return stquery(0, n-1, l, r, 0);
}

void handle(int t, int x, int y) {
	if(t == 1)
		handle_update(x-1, y);
	else if(t == 2)
		cout << handle_query(x-1, y-1) << endl;
}

int main() {
	int t, x, y, i;
	cin >> n >> q >> m;
	init();
	for(i = 0; i < q; i++) {
		cin >> t >> x >> y;
		handle(t, x, y);
	}
	return 0;
}