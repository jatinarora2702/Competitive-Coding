#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
	int n, m;
	lli p1, p2;
	scanf("%d", &n);
	if(n % 2 == 0) {
		m = n / 2;
		p1 = (lli)m * (lli)m;
		p2 = p1 + 1LL;
		p1--;
		if(p1 == 0) {
			printf("-1\n");
		}
		else {
			printf("%lld %lld\n", p1, p2);
		}
	}
	else {
		
		p1 = (lli)n * (lli)n;
		p2 = (p1 + 1LL) / 2LL;
		if(p2-1LL == 0LL) {
			printf("-1\n");
		}
		else
			printf("%lld %lld\n", p2, p2-1LL);
	}
	return 0;
}