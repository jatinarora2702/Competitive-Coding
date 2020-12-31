#include <bits/stdc++.h>
#define N 100005
using namespace std;

typedef long long int lli;

int a[N];

int main() {
	int n, i, m;
	lli s = 0LL;
	cin >> n;
	m = 0;
	for(i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
		m = max(m, a[i]);
	}
	if (s % 2 != 0) {
		cout << "NO\n";
		return 0;
	}
	s /= 2LL;
	if (s >= m) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
	return 0;
}