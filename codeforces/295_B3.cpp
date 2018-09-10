// correct but inefficient
#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;

const int N = 505;
const int INF = 1e9 + 7;

int a[N][N], c[N], d[N], n;
ll s[N];
priority_queue < pii, vector < pii > , greater < pii > > pq;

ll getdist(int s, int m) {
	int i, j, k;
	pii p;
	ll sum;
	while(!pq.empty())
		pq.pop();
	for(i = 0 ; i <= m ; i++)
		d[i] = INF;
	j = 0;
	pq.push(MP(0, s));
	while(j <= m && !pq.empty()) {
		p = pq.top();
		pq.pop();
		if(p.FF < d[p.SS]) {
			j++;
			d[p.SS] = p.FF;
			for(i = 0 ; i <= m ; i++) {
				k = p.FF + a[c[p.SS]][c[i]];
				if(d[i] > k)
					pq.push(MP(k, i));
			}
		}
	}
	sum = 0LL;
	for(i = 0 ; i <= m ; i++)
		sum += (ll)d[i];
	return sum;
}

int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < n ; j++)
			scanf("%d", &a[i][j]);
	}
	for(i = n-1 ; i >= 0 ; i--) {
		scanf("%d", &c[i]);
		c[i]--;
	}
	for(i = 0 ; i < n ; i++) {
		s[i] = 0LL;
		for(j = 0 ; j <= i ; j++)
			s[i] += getdist(j, i);
	}
	for(i = n-1 ; i >= 0 ; i--)
		printf("%lld ", s[i]);
	printf("\n");
	return 0;
}