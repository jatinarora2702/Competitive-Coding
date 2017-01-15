#include <bits/stdc++.h>
#define N 100005

using namespace std;

int a[N], segt[4*N], lazy[4*N];

void build(int ss, int se, int si) {
	if(ss == se) {
		segt[si] = a[ss];
		return;
	}
	int m = (ss + se) / 2;
	build(ss, m, 2*si+1);
	build(m+1, se, 2*si+2);
	segt[si] = segt[2*si+1] + segt[2*si+2];
}

void update(int ss, int se, int us, int ue, int val, int si) {
	if(us > se || ue < ss)
		return;
	if(ss >= us && se <= ue) {
		segt[si] += (se-ss+1) * val;
		if(ss != se){
			lazy[2*si+1] += val;
			lazy[2*si+2] += val;
		}
		return;
	}
	int m = (ss + se) / 2;
	update(ss, m, us, ue, val, 2*si+1);
	update(m+1, se, us, ue, val, 2*si+2);
	segt[si] = segt[2*si+1] + segt[2*si+2];
}

int query(int ss, int se, int qs, int qe, int si) {
	if(ss > qe || se < qs)
		return 0;
	int m = (ss + se) / 2;
	int ans;
	if(ss >= qs && se <= qe) {
		segt[si] += (se-ss+1) * lazy[si];
		if(ss != se) {
			lazy[2*si+1] += lazy[si];
			lazy[2*si+2] += lazy[si];
		}
		lazy[si] = 0;
		return segt[si];
	}
	return query(ss, m, qs, qe, 2*si+1) + query(m+1, se, qs, qe, 2*si+2);
}

void printt(int ss, int se, int si) {
	printf("(%d, %d) : [%d, %d]\n", ss, se, segt[si], lazy[si]);
	if(ss == se)
		return;
	int m = (ss + se) / 2;
	printt(ss, m, 2*si+1);
	printt(m+1, se, 2*si+2);
}

int main() {
	int n, m, x, y, z, i, ans, q;
	scanf("%d%d", &n, &m);
	for(i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	build(0, n-1, 0);
	printt(0, n-1, 0);
	for(i = 0 ; i < m ; i++) {
		scanf("%d", &q);
		if(q == 1) {
			scanf("%d%d%d", &x, &y, &z);
			update(0, n-1, x, y, z, 0);
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