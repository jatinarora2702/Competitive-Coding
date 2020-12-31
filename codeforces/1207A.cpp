#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, b, p, f, h, c, s, d;
	cin >> t;
	while(t--) {
		cin >> b >> p >> f >> h >> c;
		s = 0;
		if (h >= c) {
			d = min(b/2, p);
			s += h * d;
			b -= 2*d;
			h = -1;
		}
		else {
			d = min(b/2, f);
			s += c * d;
			b -= 2*d;
			c = -1;
		}
		if (h >= c) {
			d = min(b/2, p);
			s += h * d;
			b -= 2*d;
			h = -1;	
		}
		else {
			d = min(b/2, f);
			s += c * d;
			b -= 2*d;
			c = -1;	
		}
		cout << s << "\n";
	}
	return 0;
}