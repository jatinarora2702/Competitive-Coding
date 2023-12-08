#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector < int > v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for(int i = 0; i < v.size() - 2; i++) {	// will fail for v.size() = 1 (keep note of this!! - unsigned int issue)
		cout << v[i] << "\n";
	}
	return 0;
}