#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long int lli;
const int INF = 1e9 + 7;

#define N 100005

int a[N], pcount[N], mcount[N];

int main() {
	int n, i, minm;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
	}
	pcount[0] = (a[0] >= 0) ? 1 : 0;
	for(i = 1 ; i < n ; i++) {
		pcount[i] = pcount[i-1] + ((a[i] >= 0) ? 1 : 0);
	}
	mcount[n-1] = (a[n-1] <= 0) ? 1 : 0;
	for(i = n-2 ; i >= 0 ; i--) {
		mcount[i] = mcount[i+1] + ((a[i] <= 0) ? 1 : 0);
	}
	minm = 0;
	for(i = 1 ; i < n-1 ; i++) {
		if((pcount[i] + mcount[i+1]) < (pcount[minm] + mcount[minm+1]))
			minm = i;
	}
	printf("%d\n", pcount[minm] + mcount[minm+1]);
	return 0;
}