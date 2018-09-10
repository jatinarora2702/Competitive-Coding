#include <bits/stdc++.h>
using namespace std;

inline int getdir(int newpt, int oldpt) {
	int dir = newpt - oldpt;
	return (dir == 0) ? 0 : (dir / abs(dir));
}

int main() {
	int n, i, cnt, a[2][2], d[2][2];
	scanf("%d", &n);
	scanf("%d%d", &a[0][0], &a[0][1]);
	scanf("%d%d", &a[1][0], &a[1][1]);
	d[0][0] = getdir(a[1][0], a[0][0]);
	d[0][1] = getdir(a[1][1], a[0][1]);
	a[0][0] = a[1][0];
	a[0][1] = a[1][1];
	cnt = 0;
	for(i = 2 ; i <= n ; i++) {
		scanf("%d%d", &a[1][0], &a[1][1]);
		d[1][0] = getdir(a[1][0], a[0][0]);
		d[1][1] = getdir(a[1][1], a[0][1]);
		if (d[0][0] * d[1][1] - d[0][1] * d[1][0] > 0)
			cnt++;
		d[0][0] = d[1][0];
		d[0][1] = d[1][1];
		a[0][0] = a[1][0];
		a[0][1] = a[1][1];
	}
	printf("%d\n", cnt);
	return 0;
}