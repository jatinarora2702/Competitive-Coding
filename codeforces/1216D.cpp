#include <bits/stdc++.h>
#define N 200005

using namespace std;

typedef long long ll;

int a[N];

int gcd(int x, int y) {
	if (x < y) {
		int t = x;
		x = y;
		y = t;
	}
	while(y > 0) {
		int r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int main() {
	int n, m;
	cin >> n;
	m = -1;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		m = max(m, a[i]);
	}
	int z = -1;
	for(int i = 0; i < n; i++) {
		a[i] = m - a[i];
		if (a[i] > 0) {
			z = z == -1 ? a[i] : gcd(z, a[i]);
		}
	}
	ll y = 0LL;
	for(int i = 0; i < n; i++) {
		y += (ll)a[i] / z;
	}
	cout << y << " " << z << "\n";
	return 0;
}