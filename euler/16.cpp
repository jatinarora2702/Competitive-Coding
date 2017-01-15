#include <bits/stdc++.h>
#define N 10000
using namespace std;
typedef long long int lli;
int a[N];
int main() {
	int n, s, m, c, i, j;
	scanf("%d", &m);
	n = 1;
	a[0] = 1;
	for(i = 1 ; i <= m ; i++) {
		c = 0;
		for(j = 0 ; j < n ; j++) {
			a[j] += c + a[j];
			c = a[j] / 10;
			a[j] %= 10;
		}
		while(c > 0) {
			a[n++] = c % 10;
			c /= 10;
		}
	}
	s = 0;
	for(i = 0 ; i < n ; i++)
		s += a[i];
	printf("%d\n", s);
	return 0;
}