#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
using namespace std;

typedef long long int lli;
typedef long double ld;

#define N 505

int a[N], b[N], c[N];
int main() {
	int n, k, i, s;
	scanf("%d%d", &n, &k);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
		c[i] = a[i];
	}
	s = 0;
	for(i = 0 ; i < n-1 ; i++) {
		s += max(0, k - c[i] - c[i+1]);
		c[i+1] += max(0, k - c[i] - c[i+1]);
	}
	printf("%d\n", s);
	for(i = 0 ; i < n ; i++) {
		printf("%d ", c[i]);
	}
	printf("\n");
	return 0;
}