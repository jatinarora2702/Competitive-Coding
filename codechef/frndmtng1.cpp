#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define N 10000005

using namespace std;
typedef long long int lli;
typedef long double ld;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

int main() {
	int t, T1, T2, t1, t2;
	ld p, p1, p2;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d%d", &T1, &T2, &t1, &t2);
		p1 = max(0.0L, ((T2 - T1 - t1) / (ld)T2));
		p2 = max(0.0L, ((T1 - T2 - t2) / (ld)T1));
		p = 1.0L - (p1 + p2);
		printf("%.12LF\n", p);
	}
	return 0;
}