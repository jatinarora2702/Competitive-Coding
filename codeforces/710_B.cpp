#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define N 300005
using namespace std;

typedef long long int lli;
typedef long double ld;

const int INF = 1e9 + 7LL;
const lli LINF = 1e18 + 7LL;

pair < int, int > p[N];
lli a[N], b[N];
int main() {
	int n, i, minm, m;
	lli x, y;
	scanf("%d", &n);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &m);
		p[i] = MP(m, i);
	}
	sort(p, p+n);
	a[0] = 0;
	for(i = 1 ; i < n ; i++) {
		a[i] = a[i-1] + (lli)(p[i].FF - p[0].FF);
		// cout << a[i] << " ";
	}
	// cout << endl;
	for(i = 0 ; i < n ; i++) {
		x = a[n-1] - a[i];
		x -= (lli)(n-1-i) * (lli)(p[i].FF - p[0].FF);
		y = (lli)(p[i].FF - p[0].FF) * (lli)(i+1) - a[i];
		b[i] = x + y;
		// cout << b[i] << " ";
	}
	// cout << endl;
	minm = 0;
	for(i = 1 ; i < n ; i++) {
		if(b[minm] > b[i]) {
			minm = i;
		}
	}
	printf("%d\n", p[minm].FF);
	return 0;
}