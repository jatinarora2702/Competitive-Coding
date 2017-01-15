#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second

using namespace std;
typedef long long int lli;
typedef long double ld;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;
map < int, int > mp;
int b[15], c[15];

int fn(lli n) {
	int s;
	if(n < 10LL)
		return (int)n;
	s = 0;
	while(n > 0LL) {
		s += (int)(n % 10LL);
		n /= 10LL;
	}
	return fn((lli)s);
}

int main() {
	int t, a, d, t1, t2, t3, f, i, j, s;
	lli l, r, temp, ans;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%lld%lld", &a, &d, &l, &r);
		mp.clear();
		for(i = 0 ; i < 9 ; i++) {
			temp = (lli)a + (lli)i * (lli)d;
			b[i] = fn(temp);
			mp[b[i]] = i;
		}
		// printf("\n");
		// for(i = 0 ; i < 9 ; i++) {
		// 	printf("%d ", b[i]);
		// }
		// printf("\n");
		temp = (lli)a;
		t1 = fn(temp);
		temp = (lli)d;
		t3 = fn(temp);
		temp = l - 1LL;
		t2 = fn(temp);
		temp = (lli)t2 * (lli)t3;
		t2 = fn(temp);
		temp = (lli)t1 + (lli)t2;
		f = fn(temp);
		i = mp[f];
		s = 0;
		// printf("\n");
		for(j = 0 ; j < 9 ; j++) {
			c[j] = s + b[i];
			s = c[j];
			// printf("%d ", s);
			i = (i+1) % 9;
		}
		// printf("\n");
		temp = r - l + 1LL;
		ans = (temp / 9LL) * (lli)c[8];
		f = temp % 9LL;
		if(f > 0)
			ans += (lli)c[f-1];
		printf("%lld\n", ans);
	}
	return 0;
}