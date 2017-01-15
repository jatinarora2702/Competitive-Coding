#include <bits/stdc++.h>
using namespace std;

#define N 1000

int bsearch(int *a, int n, int k) {
	int l, r, m;
	l = 0;
	r = n-1;
	while(l <= r) {
		m = (l + r) / 2;
		if(a[m] < k) {
			l = m+1;
		}
		else if(a[m] > k) {
			r = m-1;
		}
		else {
			return m;
		}
	}
	return -1;
}

int main() {
	int n, i, k, *a, pos;
	scanf("%d", &n);
	a = new int[n];
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &k);
	pos = bsearch(a, n, k);
	if(pos == -1) {
		printf("Not Found\n");
	}
	else {
		printf("Found at pos: %d\n", pos+1);
	}
	return 0;
}