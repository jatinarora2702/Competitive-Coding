#include <bits/stdc++.h>
using namespace std;

typedef map < int, int > mpii;
typedef map < int, int > :: iterator it;

mpii mp;

int main() {
	int m, n, c, d, k;
	scanf("%d%d%d", &m, &n, &c);
	k = 0;
	d = -1;
	m = (m % n) * 10;
	while(d != c && mp[m] != 1) {
		k++;
		mp[m] = 1;
		d = m / n;
		m = (m % n) * 10;
	}
	if (d == c)
		printf("%d\n", k);
	else
		printf("-1\n");
	return 0;
}