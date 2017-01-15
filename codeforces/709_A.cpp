#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define N 1000005

typedef long long int lli;
typedef long double ld;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

int a[N];
int main() {
	int n, b, d, s, cnt, i;
	scanf("%d%d%d", &n, &b, &d);
	s = 0;
	cnt = 0;
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
		if(a[i] > b)
			continue;
		s += a[i];
		if(s > d) {
			cnt++;
			s = 0;
		}
	}
	printf("%d\n", cnt);
	return 0;
}