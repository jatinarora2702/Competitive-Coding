#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long int lli;
typedef long double ld;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

#define N 100005
int a[N], b[N], c[N], d[N], n, m;
pair < int, int > p[N];

int check(int k) {
	int i, j, cnt;
	for(i = 0 ; i < m ; i++) {
		c[i] = -1;
	}
	for(i = 0 ; i <= k ; i++) {
		if(a[i] > 0)
			c[a[i]-1] = i;
	}
	for(i = 0 ; i < m ; i++) {
		if(c[i] == -1) {
			return 0;
		}
	}
	for(i = 0 ; i < m ; i++) {
		p[i] = MP(c[i], i);
	}
	sort(p, p+m);
	for(i = 0 ; i < m ; i++) {
		// printf("(%d, %d) ", p[i].FF, p[i].SS);
	}
	// printf("\n");
	for(i = 0 ; i <= k ; i++) {
		d[i] = 1;
	}
	for(i = 0 ; i < m ; i++) {
		d[c[i]] = 0;
	}
	j = 0;
	for(i = 0 ; i < m ; i++) {
		cnt = 0;
		while(j <= k && cnt < b[p[i].SS]) {
			if(d[j] == 1)
				cnt++;
			j++;
		}
		if(j-1 >= p[i].FF) {
			return 0;
		}
		if(cnt < b[p[i].SS]) {
			return 0;
		}
	}
	return 1;
}

int getmindays() {
	int f, l, mid, k;
	f = 0;
	l = n;
	while(f < l) {
		mid = (f + l) / 2;
		// printf("mid=%d | val=", mid);
		k = check(mid);
		// printf("%d\n", k);
		if(k == 0) {
			f = mid + 1;
		}
		else {
			l = mid;
		}
	}
	return (l > n-1) ? -1 : l+1;
}

int main() {
	int k, i;
	scanf("%d%d", &n, &m);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
	}
	for(i = 0 ; i < m ; i++) {
		scanf("%d", &b[i]);
	}
	k = getmindays();
	printf("%d\n", k);
	return 0;
}