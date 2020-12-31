#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

vector < int > v;

int main() {
	int n, m;
	lli f;
	cin >> n >> m;
	f = 1LL;
	v.push_back(1);
	for(int i = 1; i <= n; i++) {
		f *= (lli)i;
		f %= (lli)m;
		v.push_back((int)f);
	}
	f = 0LL;
	for(int i = 0; i < n; i++) {
		lli t = (lli)(n-i) * (lli)v[n-i];
		t %= (lli)m;
		t *= (lli)v[i+1];
		t %= (lli)m;
		f += t;
		f %= (lli)m;
	}
	cout << f << "\n";
	return 0;
}