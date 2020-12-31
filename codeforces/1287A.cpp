#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		int n, cnt, maxm, f;
		
		cin >> n >> s;
		f = 0;
		cnt = 0;
		maxm = 0;
		
		for(int i = 0; i < n; i++) {
			if (s[i] == 'A') {
				maxm = max(maxm, cnt);
				cnt = 0;
				f = 1;
			}
			else if (f == 1) {
				cnt++;
			}
		}
		if (f == 1) {
			maxm = max(maxm, cnt);
		}
		cout << maxm << "\n";
	}
	return 0;
}