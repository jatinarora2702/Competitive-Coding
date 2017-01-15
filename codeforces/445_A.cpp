#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define N 105
using namespace std;

typedef long long int lli;

char a[N][N];
int v[N][N], n, m;

void dfs_visit(int xi, int xj, int pi, int pj, int f) {
	int nj, ni;
	v[xi][xj] = 1;
	a[xi][xj] = (f == 0) ? 'B' : 'W';
	nj = xj-1;
	ni = xi;
	if(nj >= 0 && ni >= 0 && nj < m && ni < n && !(nj == pj && ni == pi) && v[ni][nj] == 0 && a[ni][nj] == '.')
		dfs_visit(ni, nj, xi, xj, f^1);
	nj = xj+1;
	ni = xi;
	if(nj >= 0 && ni >= 0 && nj < m && ni < n && !(nj == pj && ni == pi) && v[ni][nj] == 0 && a[ni][nj] == '.')
		dfs_visit(ni, nj, xi, xj, f^1);
	nj = xj;
	ni = xi-1;
	if(nj >= 0 && ni >= 0 && nj < m && ni < n && !(nj == pj && ni == pi) && v[ni][nj] == 0 && a[ni][nj] == '.')
		dfs_visit(ni, nj, xi, xj, f^1);
	nj = xj;
	ni = xi+1;
	if(nj >= 0 && ni >= 0 && nj < m && ni < n && !(nj == pj && ni == pi) && v[ni][nj] == 0 && a[ni][nj] == '.')
		dfs_visit(ni, nj, xi, xj, f^1);
}

void dfs() {
	int i, j;
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < m ; j++) {
			if(a[i][j] == '.')
				dfs_visit(i, j, -1, -1, 0);
		}
	}
}

int main() {
	int i;
	scanf("%d%d", &n, &m);
	for(i = 0 ; i < n ; i++) {
		scanf("%s", a[i]);
	}
	dfs();
	for(i = 0 ; i < n ; i++) {
		printf("%s\n", a[i]);
	}
	return 0;
}