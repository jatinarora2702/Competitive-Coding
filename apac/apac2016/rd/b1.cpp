#include <bits/stdc++.h>
#define M 1005
#define N 105
using namespace std;
const int INF = 1000000;
int p[N], h[N], v[M];
int main() {
	int t, n, m, q, h1, hi, lo, mid, minm, s, i, j;
	scanf("%d", &t);
	h1 = 0;
	while(t--) {
		h1++;
		scanf("%d%d%d", &n, &m, &q);
		for(i = 0 ; i < m ; i++) {
			scanf("%d", &v[i]);
		}
		for(i = 0 ; i < n ; i++) {
			scanf("%d%d", &p[i], &h[i]);
		}
		hi = INF;
		lo = 0;
		while(lo < hi) {
			mid = (hi + lo) / 2;
			s = 0;
			for(i = 0 ; i < n ; i++) {
				minm = (p[i] == 0) ? 0 : INF;
				if(p[i] != 0) {
					for(j = 0 ; j < m ; j++) {
						if(p[i] * v[j] < 0 && mid * abs(v[j]) >= abs(p[i])) {
							minm = min(minm, abs(h[i]-j));
						}
					}
				}
				s += minm;
			}
			if(s <= q)
				hi = mid;
			else
				lo = mid + 1;
		}
		printf("Case #%d: ", h1);
		if(hi == INF) 
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", hi);
	}
	return 0;
}