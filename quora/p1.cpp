#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll getsum(vector < int > v) {
	if (v.size() == 0) {
		return 0;
	}
	if (v.size() == 1) {
		string s = to_string(v[0]);
		return stoll(s + s);
	}
	int m = v.size() / 2;
	vector < int > v1(v.begin(), v.begin() + m);
	vector < int > v2(v.begin() + m, v.end());
	ll s1 = getsum(v1);
	ll s2 = getsum(v2);
	ll ns1, ns2, ds1, ds2;
	ns1 = ns2 = ds1 = ds2 = 0LL;
	for(int i = 0; i < v1.size(); i++) {
		ns1 += (ll)v1[i];
		ll m = 1LL;
		int tmp = v1[i];
		while(tmp > 0) {
			tmp /= 10;
			m *= 10LL;
		}
		ds1 += m;
	}
	for(int i = 0; i < v2.size(); i++) {
		ns2 += (ll)v2[i];
		ll m = 1LL;
		int tmp = v2[i];
		while(tmp > 0) {
			tmp /= 10;
			m *= 10LL;
		}
		ds2 += m;
	}
	ds1 += (ll)v1.size();
	ds2 += (ll)v2.size();
	ll s = (ns1 * ds2) + (ns2 * ds1);
	return s + s1 + s2;
}

int main() {
	int n, x;
	vector < int > v;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	cout << getsum(v) << "\n";
	return 0;
}