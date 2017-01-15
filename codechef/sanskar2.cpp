#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define N 25

using namespace std;
typedef long long int lli;
typedef long double ld;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

lli a[N];
int b[N], n;

int check(lli s, int p) {
	int i, f;
	if(s == 0)
		return 1;
	if(p == n)
		return 0;
	if(b[p] == 0) {
		b[p] = 1;
		if(check(s-a[p], p+1))
			return 1;
		b[p] = 0;
	}
	return check(s, p+1);
}

int main() {
	int k, t, i, f;
	lli temp, s, m, maxm;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &k);
		s = 0LL;
		maxm = -1LL;
		for(i = 0 ; i < n ; i++) {
			scanf("%lld", &a[i]);
			s += a[i];
			maxm = max(maxm, a[i]);
		}
		if(n >= k && s % (lli)k == 0LL) {
			m = s / (lli)k;
			if(maxm <= m) {
				for(i = 0 ; i < n ; i++)
					b[i] = 0;
				// printf("m=%lld\n", m);
				for(i = 0 ; i < k ; i++) {
					f = check(m, 0);
					// printf("i=%d | f=%d\n", i, f);
					if(f == 0) {
						break;
					}
				}
				if(f == 0) {
					printf("no\n");
				}
				else {
					printf("yes\n");
				}
			}
			else {
				printf("no\n");
			}
		}
		else {
			printf("no\n");
		}
	}
	return 0;
}