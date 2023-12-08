#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		int px, py;
		cin >> px >> py;
		int l, r, u, d;
		l = r = u = d = 0;
		cin >> s;
		for(int i = 0; i < s.length(); i++) {
			if (s[i] == 'U') {
				u++;
			}
			else if (s[i] == 'D') {
				d++;
			}
			else if (s[i] == 'L') {
				l++;
			}
			else if (s[i] == 'R') {
				r++;
			}
		}
		int fx, fy;
		fx = fy = 0;
		if (-l <= px && px <= r) {
			fx = 1;
		}
		if (-d <= py && py <= u) {
			fy = 1;
		}
		if (fx == 1 && fy == 1) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}