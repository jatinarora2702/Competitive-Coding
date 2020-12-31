#include <bits/stdc++.h>
#define N 155
using namespace std;

int a[N], b[N];

int main() {
	int t, n, maxm;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for(int i = 0; i < n; i++) {
			cin >> b[i];
		}
		maxm = 0;
		for(int i = 0; i < n; i++) {
			int s = max(0, a[i] * 20 - b[i] * 10);
			maxm = max(maxm, s);
		}
		cout << maxm << "\n";
	}
	return 0;
}