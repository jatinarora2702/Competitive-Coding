#include <bits/stdc++.h>
#define N 1000005
using namespace std;

int a[N], segt[N];

void build(int ss, int se, int si) {
	if(ss == se){
		segt[si] = a[ss];
		return;
	}
	int m = (ss + se) / 2;
	build(ss, m, 2*si+1);
	build(m+1, se, 2*si+2);
	segt[si] = segt[2*si+1] + segt[2*si+2];
}

int query(int ss, int se, int qs, int qe, int si) {
	int m = (ss + se) / 2;
	if(qe < ss || qs > se)
		return 0;
	if(ss >= qs && se <= qe)
		return segt[si];
	return query(ss, m, qs, qe, 2*si+1) + query(m+1, se, qs, qe, 2*si+2);
}

void update(int ss, int se, int si, int index) {
	int m = (ss + se) / 2;
	if(ss == se && ss == index) {
		segt[si] = a[index];
		return;
	}
	if(ss <= index && se >= index) {
		update(ss, m, 2*si+1, index);
		update(m+1, se, 2*si+2, index);
		segt[si] = segt[2*si+1] + segt[2*si+2];
	}
}

void printt(int ss, int se, int si) {
	printf("(%d, %d) : %d\n", ss, se, segt[si]);
	if(ss == se)
		return;
	int m = (ss + se) / 2;
	printt(ss, m, 2*si+1);
	printt(m+1, se, 2*si+2);
}

int main() {
	int n, m, i, x, y, ans, q, j;
	scanf("%d%d", &n, &m);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
	}
	build(0, n-1, 0);
	for(i = 0 ; i < m ; i++) {
		scanf("%d", &q);
		if(q == 1) {
			scanf("%d%d", &x, &y);
			a[x] = y;
			update(0, n-1, 0, x);
			printt(0, n-1, 0);
		}
		else {
			scanf("%d%d", &x, &y);
			ans = query(0, n-1, x, y, 0);
			printf("%d\n", ans);
		}
	}
	return 0;
}