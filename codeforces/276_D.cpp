#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main() {
	lli l, r, x, y;
	cin >> l >> r;
	x = l^r;
	y = 1LL;
	while(x > 0LL) {
		y *= 2LL;
		x = x >> 1LL;
	}
	cout << y-1LL << "\n";
	return 0;
}