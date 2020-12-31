#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define N 1005

using namespace std;

typedef pair < int, int > pii;

pii a[N];

int main() {
	int n, x, m;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x;
		a[i] = MP(x, i+1);
	}
	sort(a, a+n);
	m = 0;
	for(int i = n-1; i >= 0; i--) {
		m += (n-1-i) * a[i].FF + 1;
	}
	cout << m << "\n";
	for(int i = n-1; i >= 0; i--) {
		cout << a[i].SS << " ";
	}
	cout << "\n";
	return 0;
}