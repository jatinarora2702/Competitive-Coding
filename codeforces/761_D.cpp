#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long int lli;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;

#define N 100005

int a[N], b[N];
pii p[N];

int main() {
	int n, l, r, i, j, d, ans;
	scanf("%d%d%d", &n, &l, &r);
	for(i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &p[i].FF);
		p[i].SS = i;
	}
	sort(p, p+n);
	d = INF;
	ans = 1;
	for(i = n-1 ; i >= 0 ; i--) {
		j = p[i].SS;
		b[j] = min(r, a[j] + d);
		if((b[j] < l) || (b[j] > r)) {
			ans = 0;
			break;
		}
		d = b[j] - a[j] - 1;
	}
	if(ans == 0)
		printf("-1\n");
	else {
		for(i = 0 ; i < n ; i++)
			printf("%d ", b[i]);
		printf("\n");
	}
	return 0;
}
