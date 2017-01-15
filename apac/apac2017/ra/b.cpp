#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define N 105

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

int h[N][N], v[N][N], r, c, s;

int dfs_visit(int xi, int xj, int prev) {
	int ni, nj, minm;
	if(v[xi][xj] == 1)
		return INF;
	v[xi][xj] = 1;
	minm = h[xi][xj];
	if(minm < prev) {
		s += (minm-prev);
		minm = prev;
	}
	ni = xi+1;
	nj = xj;
	if(ni >= 0 && ni < r && nj >= 0 && nj < c && v[ni][nj] == 0)
		minm = min(minm, dfs_visit(ni, nj, prev));
	ni = xi-1;
	nj = xj;
	if(ni >= 0 && ni < r && nj >= 0 && nj < c && v[ni][nj] == 0)
		minm = min(minm, dfs_visit(ni, nj, prev));
	ni = xi;
	nj = xj+1;
	if(ni >= 0 && ni < r && nj >= 0 && nj < c && v[ni][nj] == 0)
		minm = min(minm, dfs_visit(ni, nj, prev));
	ni = xi;
	nj = xj-1;
	if(ni >= 0 && ni < r && nj >= 0 && nj < c && v[ni][nj] == 0)
		minm = min(minm, dfs_visit(ni, nj, prev));
	return minm;
}

int main() {
	int t, i, j, h1, minm, prev;
	scanf("%d", &t);
	h1 = 0;
	while(t--) {
		h1++;
		scanf("%d%d", &r, &c);
		for(i = 0 ; i < r ; i++) {
			for(j = 0 ; j < c ; j++) {
				scanf("%d", &h[i][j]);
				v[i][j] = 0;
			}
		}
		s = 0;
		prev = 0;
		for(i = 0 ; i < r ; i++) {
			if(i >= c)
				break;
			prev = dfs_visit(i, i, prev);
			cout << "prev:" << prev << endl;
			if(prev == INF)
				break;
		}
		// for(i = 1 ; i < r-1 ; i++) {
		// 	for(j = 1 ; j < c-1 ; j++) {
		// 		minm = h[i-1][j];
		// 		minm = min(minm, h[i+1][j]);
		// 		minm = min(minm, h[i][j+1]);
		// 		minm = min(minm, h[i][j-1]);	
		// 		if(h[i][j] < minm) {
		// 			s += (minm-h[i][j]);
		// 			h[i][j] = minm;
		// 		}
		// 	}
		// }
		printf("Case #%d: %d\n", h1, s);
	}
	return 0;
}