#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main() {
	int a, b, x, y, n, i, v, s;
	float s1, m, ans;
	m = INF;
	scanf("%d%d%d", &a, &b, &n);
	for(i = 0 ; i < n ; i++) {
		scanf("%d%d%d", &x, &y, &v);
		s = (x-a)*(x-a) + (y-b)*(y-b);
		s1 = s / (1.0 * (v*v));
		m = min(m, s1);
	}
	printf("%.12f\n", sqrt(m));
	return 0;
}
