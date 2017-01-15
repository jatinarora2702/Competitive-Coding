#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second

using namespace std;
typedef long long int lli;
typedef long double ld;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

int fn(lli n) {
	int s;
	if(n < 10LL)
		return (int)n;
	s = 0;
	while(n > 0LL) {
		s += (int)(n % 10LL);
		n /= 10LL;
	}
	return fn((lli)s);
}

int main() {
	int t, a, d, ans, t1, t2, t3, f;
	lli l, r, temp;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%lld%lld", &a, &d, &l, &r);
		temp = r - l + 1LL;
		f = 0;
		if(temp % 2LL == 0LL) {
			temp /= 2LL;
			f = 1;
		}
		ans = fn(temp);
		temp = 2LL * (lli)a;
		if(f == 0) {
			temp /= 2LL;
		}
		t1 = fn(temp);
		temp = l + r - 2LL;
		if(f == 0 && temp % 2LL == 0LL) {
			temp /= 2LL;
			f = 1;
		}
		t2 = fn(temp);
		temp = (lli)d;
		if(f == 0) {
			temp /= 2LL;
		}
		t3 = fn(temp);
		temp = (lli)t2 * (lli)t3;
		t2 = fn(temp);
		temp = (lli)t1 + (lli)t2;
		t1 = fn(temp);
		temp = (lli)ans * (lli)t1;
		ans = fn(temp);
		printf("%d\n", ans);
	}
	return 0;
}