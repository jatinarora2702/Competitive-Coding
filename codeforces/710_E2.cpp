#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define N 80000005
using namespace std;

typedef long long int lli;
typedef long double ld;
typedef pair < lli, int > pli;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

lli st[N];

void build(int ss, int se, int si) {
	if(ss == se) {
		st[si] = LINF;
		return;
	}
	int m = (ss + se) / 2;
	build(ss, m, 2*si+1);
	build(m+1, se, 2*si+2);
	st[si] = min(st[2*si+1], st[2*si+2]);
}

void update(int ss, int se, int si, int pos, lli val) {
	if(ss <= pos && se >= pos) {
		if(ss == se && ss == pos) {
			st[si] = min(st[si], val);
			return;
		}
		int m = (ss + se) / 2;
		update(ss, m, 2*si+1, pos, val);
		update(m+1, se, 2*si+2, pos, val);
		st[si] = min(st[2*si+1], st[2*si+2]);
	}
}

lli query(int ss, int se, int si, int qs, int qe) {
	cout << "!!!!!!!!!!ss=" << ss << " se=" << se << " si=" << si << " qs=" << qs << " qe=" << qe << " st=" << st[si] << endl;
	if(ss > qe || se < qs)
		return LINF;
	if(qs <= ss && se <= qe) {
		cout << " in" << endl;
		return st[si];
	}
	int m = (ss + se) / 2;
	return min(query(ss, m, 2*si+1, qs, qe), query(m+1, se, 2*si+2, qs, qe));
}

void printst(int ss, int se, int si) {
	if(ss < se) {
		int m = (ss + se) / 2;
		printst(ss, m, 2*si+1);
		printst(m+1, se, 2*si+2);
	}
	cout << "ss=" << ss << " se=" << se << " si=" << si << " stval=" << st[si] << endl;
}

int main() {
	int i, n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	build(0, 2*n, 0);
	update(0, 2*n, 0, 0, 0LL);
	update(0, 2*n, 0, 1, (lli)(2*x));
	update(0, 2*n, 0, 2, (lli)x+(lli)y+(lli)(2*x));
	printf("printing:\n");
	printst(0, 2*n, 0);
	for(i = 2 ; i <= n ; i++) {
		cout << "doing: " << query(0, 2*n, 0, i-1, i-1) << endl;
		update(0, 2*n, 0, i, query(0, 2*n, 0, i-1, i-1)+(lli)(2*x));
		printf("printing:\n");
		printst(0, 2*n, 0);
		update(0, 2*n, 0, i, query(0, 2*n, 0, i+1, 2*i-1));
		update(0, 2*n, 0, 2*i, query(0, 2*n, 0, i, i)+(lli)y+(lli)(2*i)*(lli)x);
	}
	cout << query(0, 2*n, 0, n, n)-(lli)n*(lli)x << endl;
	return 0;
}