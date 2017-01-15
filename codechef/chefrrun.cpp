#include <bits/stdc++.h>
#define N 1000005
using namespace std;

int a[N], b[N], c[N], n, cnt;
void dfs_visit(int s, int k, int m) {
	int ns;
	b[s] = k;
	c[s] = m;
	ns = (s + a[s] + 1) % n;
	if(b[ns] == 0)
		dfs_visit(ns, k, m+1);
	else if(b[ns] == k){
		cnt += (c[s] - c[ns] + 1);
	}
}

int dfs() {
	int i, k;
	cnt = 0;
	for(i = 0 ; i < n ; i++) {
		b[i] = 0;
		c[i] = 0;
	}
	k = 1;
	for(i = 0 ; i < n ; i++) {
		if(b[i] == 0) {
			dfs_visit(i, k, 0);
			k++;
		}
	}
}

int main() {
	int t, i;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(i = 0 ; i < n ; i++) {
			scanf("%d", &a[i]);
		}
		dfs();
		printf("%d\n", cnt);
	}
	return 0;
}