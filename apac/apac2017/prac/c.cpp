#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int main() {
	int t, a, b, c, n, x, k, h, i, j;
	ld pa, pb, pc, p1, pans;
	scanf("%d", &t);
	h = 0;
	while(t--) {
		h++;
		scanf("%d%d%d%d%d%d", &n, &x, &k, &a, &b, &c);
		pa = a / 100.0;
		pb = b / 100.0;
		pc = c / 100.0;
		pans = 0.0;
		for(i = 0 ; i < 32 ; i++) {
			p1 = (x & (1 << i)) ? 1.0 : 0.0;
			for(j = 0 ; j < n ; j++) {
				if(k & (1 << i)) {
					p1 = pa * p1 + pb + pc * (1-p1);	
				}
				else {
					p1 = pb * p1 + pc * p1;
				}
			}
			pans += p1 * (1 << i);
		}
		printf("Case #%d: %.10LF\n", h, pans);
	}
	return 0;
}