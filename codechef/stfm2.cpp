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

lli a[N];
int b[N];
int main() {
	int n, m, i;
	lli ans, s, temp;
	scanf("%d%d", &n, &m);
	b[0] = 1 % m;
	for(i = 1 ; i < m ; i++) {
		temp = (lli)b[i-1] * (lli)i;
		b[i] = temp % (lli)m;
	}
	ans = 0LL;
	for(i = 0 ; i < n ; i++) {
		scanf("%lld", &a[i]);
		s = 0LL;
		if((a[i]+1LL) < (lli)m) {
			s += (lli)b[a[i]+1];
			s %= (lli)m;
		}
		// printf("a=%lld | s=%lld\n", a[i], s);
		if(a[i] % 2 == 0) {
			temp = a[i] / 2LL;
			temp %= (lli)m;
			temp *= ((a[i]+1LL) % (lli)m);
			temp %= (lli)m;
		}
		else {
			temp = (a[i]+1LL) / 2LL;
			temp %= (lli)m;
			temp *= (a[i] % (lli)m);
			temp %= (lli)m;
		}
		temp *= (a[i] % (lli)m);
		temp %= (lli)m;
		s += temp;
		s %= (lli)m;
		s -= 1LL;
		s += (lli)m;
		s %= (lli)m;
		// printf("s=%lld\n", s);
		ans += s;
		ans %= (lli)m;
	}
	printf("%lld\n", ans);
	return 0;
}