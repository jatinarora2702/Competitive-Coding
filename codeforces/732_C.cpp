#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long int lli;
typedef long double ld;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

#define N 1005

int main() {
	lli a[3], k;
	int s, l, i;
	cin >> a[0] >> a[1] >> a[2];
	s = 0;
	l = 0;
	for(i = 1 ; i < 3 ; i++) {
		if(a[s] < a[i]) {
			s = i;
		}
		if(a[l] <= a[i]) {
			l = i;
		}
	}
	// if(s == 0 && l == 2) {
	// 	if(a[0] > a[1]) {
	// 		k += (lli)(4 - l + s)
	// 	}
	// }
	k = a[s] - 2LL;
	k *= 3LL;
	k += (lli)min((4 - s + l), (7 - l + s));
	k -= a[0] + a[1] + a[2];
	cout << max(0LL, k) << endl;
	return 0;
}