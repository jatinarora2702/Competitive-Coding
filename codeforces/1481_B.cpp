#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		// cout << "n:" << n << " k:" << k << "\n";
		for(int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int ans = -1;
		// cout << "kk\n";
		while(k > 0) {
			int ep = n;
			int h = 0;
			// cout << "q\n";
			for(int i = 0; i < n-1; i++) {
				if (v[i] < v[i+1]) {
					ep = i;
					h = v[i+1] - v[i];
					break;
				}
			}
			// cout << "r\n";
			if (ep == n) {
				k = 0;
				ans = -1;
				break;
			}
			// cout << "here\n";
			int sp;
			for(sp = ep; sp >= 0; sp--) {
				if (sp == 0) {
					break;
				}
				if (v[sp] < v[sp-1]) {
					h = min(h, v[sp-1] - v[sp]);
					break;
				}
			}
			// cout << sp << " " << ep << " " << h << "\n";
			for(int i = 0; i < h; i++) {
				int f = ep - sp + 1;
				if (f < k) {
					k -= f;
				}
				else {
					ans = ep - k + 1;
					k = 0;
					ans++;
					break;
				}
			}
			for(int i = sp; i <= ep; i++) {
				v[i] += h;
			}
			// cout << "v: ";
			// for(int i = 0; i < n; i++) {
			// 	cout << v[i] << " ";
			// }
			// cout << "\n";
		}
		cout << ans << "\n";
	}
	return 0;
}