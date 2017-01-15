#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define N 100005

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

int main() {
	int t, l, r, h, minm;
	lli ans;
	scanf("%d", &t);
	h = 0;
	while(t--) {
		h++;
		scanf("%d%d", &l, &r);
		minm = min(l, r);
		ans = minm * 1LL * (minm+1);
		ans /= 2LL;
		cout << "Case #" << h << ": " << ans << endl;
	}
	return 0;
}