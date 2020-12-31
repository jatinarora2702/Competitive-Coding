#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, cnt, f, seen;
	string s;
	cin >> t;
	while(t--) {
		cin >> s;
		cnt = 0;
		f = 1;
		seen = 0;
		int n = s.size();
		for(int i = 0; i < n; i++) {
			if (s[i] == '(') {
				cnt++;
			}
			else if (s[i] == ')') {
				if (cnt == 0) {
					f = 0;
					break;
				}
				else {
					cnt--;
				}
			}
			else {
				cnt++;
			}
		}
		if (f == 0 || cnt % 2 == 1 || s[n-1] == '(') {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
	}
	return 0;
}
