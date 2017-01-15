#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define N 100

using namespace std;

typedef long long int lli;
typedef long double ld;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

int r, c, s, a[N][N], v[N][N];

void dfs_visit(int xi, int xj) {
	int ni, nj;
	vector < pair < int, int > > vec;
	v[xi][xj] = 1;
	ni = xi+1;
	nj = xj;
	if(ni >= 0 && ni < r && nj >= 0 && nj < c && rt[ni][nj] == 0 && v[ni][nj] == 0) {
		vec.PB(MP(ni, nj));
	}
}

void dfs() {
	int i, j;
	for(i = 0 ; i < r ; i++) {
		for(j = 0 ; j < c ; j++) {
			v[i][j] = 0;
		}
	}
	for(i = 0 ; i < r ; i++) {
		for(j = 0 ; j < c ; j++) {
			if(v[i][j] == 0) {
				dfs_visit(i, j);
			}
		}
	}
}

int main() {
	int t, i, j, h;
	scanf("%d", &t);
	h = 0;
	while(t--) {
		h++;
		scanf("%d%d", &r, &c);
		for(i = 0 ; i < r ; i++) {
			for(j = 0 ; j < c ; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		s = 0;
		dfs();
		printf("Case #%d: %d\n", h, s);
	}
	return 0;
}