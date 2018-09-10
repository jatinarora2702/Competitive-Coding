#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long int lli;
const int INF = 1e9 + 7;

#define N 100005
#define M 205

int l[N], d[N], cleneng[N], lencnt[N], clencnt[N], eng[M][N];

int main() {
	int n, m, i, j, k, mincost, cost;
	scanf("%d", &n);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &l[i]);
	}
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &d[i]);
	}
	for(i = 0 ; i < n ; i++) {
		cleneng[l[i]] += d[i];
		lencnt[l[i]]++;
		clencnt[l[i]]++;
		eng[d[i]][l[i]] += 1;
	}
	for(i = N-2 ; i >= 0 ; i--) {
		cleneng[i] += cleneng[i+1];
		clencnt[i] += clencnt[i+1];
	}
	for(i = 0 ; i < M ; i++) {
		for(j = 1 ; j < N ; j++) {
			eng[i][j] += eng[i][j-1];
		}
	}
	mincost = INF;
	for(i = 0 ; i < N-1 ; i++) {
		if(lencnt[i] > 0) {
			m = 2 * lencnt[i] - 1;
			cost = cleneng[i+1];
			m = (n - clencnt[i+1]) - m;
			for(j = 0 ; j < M ; j++) {
				if(m <= 0)
					break;
				if(eng[j][i-1] > 0) {
					k = min(m, eng[j][i-1]);
					cost += j*k;
					m -= k;
				}
			}
			mincost = min(mincost, cost);
		}
	}
	printf("%d\n", mincost);
	return 0;
}