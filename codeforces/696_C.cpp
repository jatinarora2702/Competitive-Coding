#include <bits/stdc++.h>
#define N 100005
using namespace std;
typedef long long int lli;
typedef long double ld;
const lli INF = 1e9 + 7LL;
const lli LINF = 1e18 + 7LL;
lli a[N];

lli expfn(lli x, lli p) {
	lli ans;
	if(p < 0LL)
		return 0LL;
	if(p == 0LL)
		return 1LL;
	ans = expfn(x, p/2LL);
	ans *= ans;
	ans %= INF;
	if(p % 2LL != 0LL) {
		ans *= x;
		ans %= INF;
	}
	return ans;
}

lli gcd(lli a, lli b, lli &x, lli &y) {
	lli x1, y1, g;
	if(b == 0LL) {
		x = 1LL;
		y = 0LL;
		// cout << "a=" << a << " x=" << x << " b=" << b << " y=" << y << " g=" << a << endl;
		return a;
	}
	else {
		g = gcd(b, a%b, x1, y1);
		x = y1;
		y = x1 - y1 * (a/b);
		// cout << "a=" << a << " x=" << x << " b=" << b << " y=" << y << " g=" << g << endl;
		return g;
	}
}

lli invmod(lli a) {
	lli x, y;
	// cout << "finding gcd of " << a << endl;
	gcd(INF, a, x, y);
	y += INF;
	y %= INF;
	// cout << "inv " << a << " = " << y << endl;
	return y;
}

int main() {
	int i, k, f;
	lli p, q, t, v2, v3;
	scanf("%d", &k);
	f = 0;
	for(i = 0 ; i < k ; i++) {
		cin >> a[i];
		if(a[i] % 2LL == 0LL)
			f = 1;
	}
	t = 2LL;
	for(i = 0 ; i < k ; i++) {
		t = expfn(t, a[i]);
	}
	v2 = invmod(2LL);
	// cout << "v2=" << v2 << endl;
	v3 = invmod(3LL);
	// cout << "v3=" << v3 << endl;
	t *= v2;
	t %= INF;
	q = t;
	// cout << "q=" << q << endl;
	if(f == 0) {
		t -= 1LL;
		t += INF;
		t %= INF;
	}
	else {
		t += 1LL;
		t %= INF;
	}
	// cout << "t=" << t << endl;
	t *= v3;
	t %= INF;
	p = t;
	// cout << "p=" << p << endl;
	cout << p << "/" << q << "\n";
	return 0;
}