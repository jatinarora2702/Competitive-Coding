#include <bits/stdc++.h>
#define N 200005
using namespace std;

int a[N];

int main() {
	int n, k, i, m, d, t, v;
	cin >> n >> k;
	for(i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	m = n / 2;
	v = a[m];
	for(i = m; i < n-1; i++) {
		d = k / (i - m + 1);
		t = min(d, a[i+1] - a[i]);
		k -= t * (i - m + 1);
		v += t;
	}
	d = k / (i - m + 1);
	k -= d * (i - m + 1);
	v += d;
	cout << v << "\n";
	return 0;
}