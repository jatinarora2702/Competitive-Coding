#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	long long n, k;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		n /= k;
		cout << ((n % k == 0) ? "NO\n" : "YES\n");
	}
	return 0;
}