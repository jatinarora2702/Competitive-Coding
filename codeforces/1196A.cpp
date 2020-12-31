#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main() {
	int q;
	vector<lli> a;
	lli x, d;
	cin >> q;
	while(q--) {
		a.clear();
		for(int i = 0; i < 3; i++) {
			cin >> x;
			a.push_back(x);
		}
		sort(a.begin(), a.end());
		a[0] += a[2];
		d = a[0] - a[1];
		a[0] -= (d/2LL);
		a[1] += (d/2LL);
		cout << min(a[0], a[1]) << endl;
	}
	return 0;
}