#include <bits/stdc++.h>
#define N 1005
using namespace std;

int main() {
	int n, k, x, m, r, d, i;
	vector < int > v(N, 0);
	cin >> n >> k;
	for(i = 0; i < n; i++) {
		cin >> x;
		v[x-1]++;
	}
	m = 0;
	r = 0;
	for(i = 0; i < k; i++) {
		d = v[i] % 2;
		m += v[i] - d;
		r += d;	
	}
	cout << (m + (r+1)/2) << "\n";
	return 0;
}