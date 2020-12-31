#include <bits/stdc++.h>
using namespace std;

vector < string > v1, v2;

int main() {
	int n, m, q, d;
	string x;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> x;
		v1.push_back(x);
	}
	for(int i = 0; i < m; i++) {
		cin >> x;
		v2.push_back(x);
	}
	cin >> q;
	for(int i = 0; i < q; i++) {
		cin >> d;
		cout << (v1[(d-1) % v1.size()] + v2[(d-1) % v2.size()]) << "\n";
	}
	return 0;
}