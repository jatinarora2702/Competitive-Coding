#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	int b[2];
	cin >> n;
	b[0] = 0;
	b[1] = 0;
	for(int i = 0; i < n; i++) {
		cin >> x;
		b[x%2]++;
	}
	cout << min(b[0], b[1]) << "\n";
	return 0;
}