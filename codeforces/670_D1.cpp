#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
using namespace std;

typedef pair < int, int > pii;

const int N = 100005;

int a[N], b[N];
pii p[N];

int main() {
	int n, m, i, j, k, f, s, c;
	scanf("%d%d", &n, &k);
	for(i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &b[i]);
		f = b[i] / a[i];
		p[i] = MP(f, i);
	}
	sort(p, p + n);
	s = 0;
	m = 0;
	for(i = 0 ; i < n-1 ; i++) {
		j = p[i].SS;
		s += a[j];
		m += b[j] - p[i].FF * a[j];
		f = (p[i+1].FF - p[i].FF) * s - m;
		if (f < 0)
			continue;
		if (f <= k) {
			k -= f;
			m = 0;
		}
		else
			break;
	}
	if (i == n-1) {
		j = p[i].SS;
		s += a[j];
		m += b[j] - p[i].FF * a[j];
	}
	f = s - m;
	c = p[i].FF;
	if (k >= f) {
		c++;
		k -= f;
		c += k / s;
	}
	printf("%d\n", c);
	return 0;
}