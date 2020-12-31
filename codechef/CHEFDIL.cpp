#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, f;
	string s;
	cin >> t;
	while(t--) {
		cin >> s;
		n = s.length();
		f = 1;
		for(int i = 0; i < n; i++) {
			if (s[i] == '0') {
				f = 0;
			}
			else {
				f = 1;
				if (i+1 < n) {
					s[i+1] = '0' + ((s[i+1] - '0') ^ 1);
				}
			}
		}
		cout << (f == 1 ? "WIN\n" : "LOSE\n");
	}
	return 0;
}