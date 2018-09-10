#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

using namespace std;
typedef long long int lli;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

#define N 10005

lli n, m, k;

int check(lli s) {
	lli tot, d, l;
	d = max(s-k, 0LL);
	tot = (s*(s+1LL) - d*(d+1LL)) / 2LL;
	tot += max(k-s, 0LL);
	// cout << "s=" << s << " | d=" << d << " | tot=" << tot << endl;
	d = max((s-1LL)-(n-k), 0LL);
	tot += (s*(s-1LL) - d*(d+1LL)) / 2LL;
	tot += max((n-k)-(s-1LL), 0LL);
	// cout << "s=" << s << " | d=" << d << " | tot=" << tot << endl;
	return (tot <= m) ? 1 : 0;
}

int main() {
	int c, b, l, mid, f;
	cin >> n >> m >> k;
	c = m / n;
	b = c;
	l = m - (n-1);
	while(b <= l) {
		mid = (b + l) / 2;
		f = check((lli)mid);
		if(f == 1)
			b = mid+1;
		else
			l = mid-1;
	}
	printf("%d\n", b-1);
	return 0;
}