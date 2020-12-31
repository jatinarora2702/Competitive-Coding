#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define N 200005

using namespace std;

typedef long long lli;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;

int a[N];
lli s[N];
int main() {
	int n, d, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	for(int i = 0; i < n; i++) {
		s[i] = (lli)a[i];
		if (i-1 >= 0) {
			s[i] += s[i-1];
		}
		if (i-m >= 0) {
			s[i] += s[i-m];
		}
		if (i-m-1 >= 0) {
			s[i] -= s[i-m-1];
		}
		cout << s[i] << " ";
	}
	cout << "\n";
	return 0;
}