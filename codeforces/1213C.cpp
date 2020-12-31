#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll q, s, k;
	ll n, m;
	vector < ll > v;
	set < ll > st;
	cin >> q;
	while(q--) {
		cin >> n >> m;
		v.clear();
		st.clear();
		ll t;
		t = m;
		while(st.find(t % 10) == st.end()) {
			st.insert(t % 10);
			v.push_back(t % 10);
			t += m;
		}
		k = v.size();
		for(ll i = 1; i < k; i++) {
			v[i] += v[i-1];
		}
		s = n / m;
		ll ans = (s / k) * v[k-1];
		ll r = (s % k) - 1;
		if (r >= 0) {
			ans += v[r];
		}
		cout << ans << "\n";
	}
	return 0;
}