#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n, k, a, b, s, r;
	cin >> n >> k >> a >> b;
	s = 0LL;
	if(k == 1LL) {
		s = a * (n-1);
	}
	else {
		while(n > 1LL) {
			if(n >= k) {
				r = n % k;
				if(r > 0) {
					s += r * a;
					n -= r;
				}
				s += min(b, (n - n/k) * a);
				n = n/k;
			}
			else {
				s += (n-1LL) * a;
				n = 1LL;
			}
		}
	}
	cout << s << endl;
	return 0;
}