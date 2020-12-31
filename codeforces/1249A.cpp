#include <bits/stdc++.h>
#define N 105
using namespace std;

int main() {
	int q;
	cin >> q;
	while(q--) {
		int a[N], n, x, f;
		for(int i = 0; i < N; i++) {
			a[i] = 0;
		}
		cin >> n;
		f = 1;
		for(int i = 0; i < n; i++) {
			cin >> x;
			a[x]++;
			if (a[x-1] > 0 || a[x+1] > 0) {
				f = 2;
			}
		}
		cout << f << "\n";
	}
	return 0;
}