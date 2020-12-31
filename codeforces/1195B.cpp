#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	cout << n - ((((long long)sqrt(9LL + 8LL * (k + n))) - 3LL) / 2LL) << "\n";
	return 0;
}