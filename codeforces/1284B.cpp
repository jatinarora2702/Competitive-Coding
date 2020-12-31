#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main() {
	int n, m, f, x;
	lli s, p;
	vector < pair < int, int > > vs;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> m;
		vector < int > v;
		for(int j = 0; j < m; j++) {
			cin >> x;
			v.push_back(x);
		}
		f = 1;
		for(int j = 1; j < m; j++) {
			if (v[j] > v[j-1]) {
				f = 0;
				break;
			}
		}
		if (f == 1) {
			vs.push_back(make_pair(v[0], v[v.size()-1]));
		}
	}
	p = 0LL;
	sort(vs.begin(), vs.end());
	for(int i = vs.size() - 1; i >= 0; i--) {
		x = upper_bound(vs.begin(), vs.end(), make_pair(vs[i].second, vs[i].second)) - vs.begin();
		p += (lli)(x);
	}
	s = (lli)n * (lli)n;
	s -= p;
	cout << s << "\n";
	return 0; 
}