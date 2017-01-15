#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define N 100005
using namespace std;
typedef long long int lli;

int a[N], b[N];
int main() {
	int i, n, q, k;
	scanf("%d", &n);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a+n);
	scanf("%d", &q);
	for(i = 0 ; i < q ; i++) {
		scanf("%d", &b[i]);
	}
	for(i = 0 ; i < q ; i++) {
		k = upper_bound(a, a+n, b[i]) - a;
		printf("%d\n", k);
	}
	return 0;
}