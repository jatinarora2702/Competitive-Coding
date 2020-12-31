#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x[3], a[3], b[2], f;
	cin >> n;
	a[0] = a[1] = a[2] = b[0] = b[1] = 0;
	x[0] = x[1] = -1;
	for(int i = 0; i < n; i++) {
		cin >> x[2];
		if (x[1] == 0) {
			f = (x[1] % 2) + (x[2] % 2);
			if (x[0] > 0) {
				f += (x[0] % 2);
			}
			a[f]++;
		}
		else if (x[2] == 0) {
			b[x[2] % 2]++;
		}
		x[0] = x[1];
		x[1] = x[2];
	}
	f = min(a[0], b[0]);
	a[0] -= f;
	b[0] -= f;
	f = min(a[2], b[1]);
	a[2] -= f;
	b[1] -= f;
	f = 2 * (a[0] + a[2]) + a[1];
	cout << f << "\n";

	// this approach will not work.. haven't considered the case where you have streak of 0's together, like, 502000004000507 - need to rethink the algorithm
	return 0;
}