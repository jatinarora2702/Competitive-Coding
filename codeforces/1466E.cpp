#include<bits/stdc++.h>
#define N 100005
using namespace std;

const int INF = 1e9 + 7;

int a[N], b[N], c[N];
int main() {
	int t;
	cin >> t;
	while(t--) {
		int s, n;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		b[n-1] = a[n-1];
		for(int i = n-2; i >= 0; i--) {
			b[i] = b[i+1] + a[i];
			b[i] %= INF;
		}
		int tot = b[0];
		c[n-1] = a[n-1] * a[n-1];
		for(int i = n-2; i >= 0; i--) {
			c[i] = c[i+1] + a[i] * a[i];
			c[i] %= INF;
		}
		s = 0;
		for(int i = 0; i < n; i++) {
			s += a[i] * (a[i] | tot);
			s %= INF;
		}
		for(int i = 0; i < n; i++) {
			s += (a[i] * (((n-i) * a[i] + b[i]) | tot)) & (((a[i] * b[i]) | tot) + (c[i] | tot));
			s %= INF;
		}
		cout << s << "\n";
	}
	return 0;
}