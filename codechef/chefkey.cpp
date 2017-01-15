#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, c, t, i, cnt, k, nmin;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &n, &m, &c);
		cnt = 0;
		for(i = 1 ; i <= c ; i++) {
			if(c % i == 0 && i > 0 && i <= n) {
				k = c / i;
				if(k > 0 && k <= m) {
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}