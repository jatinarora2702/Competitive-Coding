#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int INF = 1e9 + 7;

set < int > lst, ust;
int a[N];

int main() {
	int n, i, m, minm, imin;
	scanf("%d", &n);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
		ust.insert(a[i]);
	}
	minm = INF;
	imin = -1;
	for(i = 0 ; i < n ; i++) {
		m = ust.upper_bound(a[0]) - ust.begin();
		lst.insert(a[i]);
		ust.erase(a[i]);
		if (i == 0 || m < minm) {
			minm = m;
			imin = i;
		}
	}
	printf("%d\n", a[imin]);
	return 0;
}