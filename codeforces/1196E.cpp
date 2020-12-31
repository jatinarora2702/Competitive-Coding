#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[2], q, x, y, m, d;
	cin >> q;
	while(q--) {
		cin >> a[1] >> a[0];
		m = a[0] <= a[1] ? 0 : 1;
		if (a[m] * 3 + 1 >= a[m^1]) {
			cout << "YES\n";
			if (m == 1) {
				x = 2;
				y = 2;
			}
			else {
				x = 2;
				y = 1;
			}
			cout << x << " " << y << "\n";
			a[m^1]--;
			y += 1;
			while(a[m] > 0) {
				cout << x << " " << y << "\n";
				a[m]--;
				if (a[m] == 0 && a[m^1] == 0) {
					break;
				}
				d = a[m^1] - a[m];
				d = min(d, 3);
				d = max(d, 1);
				cout << x << " " << y+1 << "\n";
				d--;
				a[m^1]--;
				if (d > 0) {
					cout << x-1 << " " << y << "\n";
					d--;
					a[m^1]--;
				}
				if (d > 0) {
					cout << x+1 << " " << y << "\n";
					d--;
					a[m^1]--;
				}
				y += 2;
			}
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}