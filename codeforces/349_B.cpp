#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define N 1000005

using namespace std;
const int INF = 1e9+7;

int a[10], b[N];
int main() {
	int v, i, j, minm, d, n;
	scanf("%d", &v);
	minm = INF;
	for(i = 0 ; i < 9 ; i++) {
		scanf("%d", &a[i]);
		minm = min(minm, a[i]);
	}
	for(i = 9 ; i >= 0 ; i--) {
		if(a[i] == minm) {
			d = i;
			break;
		}
	}
	n = v / a[d];
	if(n == 0) {
		printf("-1");
	}
	else {
		v -= (a[d] * n);
		for(i = 0 ; i < n ; i++) {
			for(j = 8 ; j > d ; j--) {
				if(v >= (a[j] - a[d])) {
					v -= (a[j] - a[d]);
					break;
				}
			}
			b[i] = j + 1;
		}
		for(i = 0 ; i < n ; i++) {
			printf("%d", b[i]);
		}
	}
	printf("\n");
	return 0;
}