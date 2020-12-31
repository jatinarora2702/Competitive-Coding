#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main() {
	int q, x, d, i, k, n;
	lli s;
	vector < int > ans;
	cin >> q;
	while(q--) {
		ans.clear();
		s = 0LL;
		cin >> n >> k;
		for(i = 0; i < n; i++) {
			cin >> x;
			s += (lli)x;
			if (s % 2LL == 1LL) {
				ans.push_back(i+1);
				s = 0LL;
			}
		}
		d = ans.size() - k;
		if (d >= 0 && d % 2 == 0) {
			cout << "YES\n";
			for(i = 0; i < k-1; i++) {
				cout << ans[i] << " ";
			}
			cout << n << "\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}