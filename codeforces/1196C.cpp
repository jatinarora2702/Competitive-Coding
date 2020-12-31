#include <bits/stdc++.h>
#define N 100000
using namespace std;

int main() {
	int q, n, i, x, y, f1, f2, f3, f4, xs, xe, ys, ye;
	cin >> q;
	while(q--) {
		cin >> n;
		xs = ys = -N;
		xe = ye = N;
		for(i = 0; i < n; i++) {
			cin >> x >> y >> f1 >> f2 >> f3 >> f4;
			if (f1 == 0) {
				xs = max(xs, x);
			}
			if (f2 == 0) {
				ye = min(ye, y);
			}
			if (f3 == 0) {
				xe = min(xe, x);
			}
			if (f4 == 0) {
				ys = max(ys, y);
			}
		}
		if (xs <= xe && ys <= ye) {
			cout << "1 " << xs << " " << ys << "\n";
		}
		else {
			cout << "0\n";
		}
	}
	return 0;
}