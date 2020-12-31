#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define N 100005

using namespace std;

typedef long long lli;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;

int a[N], b[N];
int main() {
	int t, n, d, f, x, ans;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for(int i = 0; i < n; i++) {
			cin >> b[i];
			b[i] -= a[i];
		}
		f = 0;
		ans = 1;
		for(int i = 0; i < n; i++) {
			if (b[i] > 0) {
				if (f == 0) {
					f = 1;
					d = b[i];
				}
				else if (f == 1) {
					if (d != b[i]) {
						ans = 0;
						break;
					}
				}
				else {
					ans = 0;
					break;
				}
			}
			else if (b[i] < 0) {
				ans = 0;
				break;
			}
			else {
				if (f == 1) {
					f = 2;
				}
			}
		}
		if (ans == 1) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}