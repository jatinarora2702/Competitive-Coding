#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int dim[2], f;

lli r[2];

lli check(lli n) {
	int i, p;
	lli l, u, c, tmp;
	c = 0LL;
	for(i = 0 ; i < dim[f] ; i++) {
		p = min((lli)dim[f^1], n / (lli)(i+1));
		tmp = (lli)(i+1) * (lli)p;
		c = max(c, tmp);
	}
	l = 0LL;
	u = 0LL;
	for(i = 0 ; i < dim[f] ; i++) {
		p = min((lli)dim[f^1], c / (lli)(i+1));
		tmp = (lli)(i+1) * (lli)p;
		l += (lli)((tmp == c) ? (p-1) : p);
		u += (lli)p;
	}
	r[0] = l + 1LL;
	r[1] = u;
	return c;
}

int main() {
	lli k, sq, p, n, m, l, u;
	scanf("%d%d%lld", &dim[0], &dim[1], &k);
	f = (dim[0] <= dim[1]) ? 0 : 1;
	p = (lli)dim[0] * (lli)dim[1];
	l = 1LL;
	u = sqrt(p) + 1LL;
	do {
		m = (l + u) / 2LL;
		sq = m * m;
		n = check(sq);
		if(k < r[0]) {
			u = m - 1LL;
		}
		else if(k > r[1]) {
			l = m + 1LL;
		}
		else {
			printf("%lld\n", n);
			return 0;
		}
	} while(l <= u);
	if(k < r[0]) {
		l = (m-1LL) * (m-1LL);
		u = m * m;
	}
	else {
		l = m * m;
		u = (m+1LL) * (m+1LL);
	}
	do {
		m = (l + u) / 2LL;
		n = check(m);
		if(k < r[0])
			u = m;
		else if(k > r[1])
			l = m;
		else {
			printf("%lld\n", n);
			return 0;
		}
	} while(l < u);
	printf("0\n");	// error
	return 0;
}