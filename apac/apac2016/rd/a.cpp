#include <bits/stdc++.h>
#define N 105
using namespace std;
int v[N][N], r, c;
char a[N][N];

void dfs_visit(int ci, int cj, int pi, int pj) {
	int ni, nj;
	v[ci][cj] = 1;
	ni = ci-1;
	nj = cj;
	if(ni >= 0 && ni < r && nj >= 0 && nj < c && !(ni == pi && nj == pj) && a[ni][nj] == '1' && v[ni][nj] == 0) {
		dfs_visit(ni, nj, ci, cj);
	}
	ni = ci+1;
	nj = cj;
	if(ni >= 0 && ni < r && nj >= 0 && nj < c && !(ni == pi && nj == pj) && a[ni][nj] == '1' && v[ni][nj] == 0) {
		dfs_visit(ni, nj, ci, cj);
	}
	ni = ci;
	nj = cj-1;
	if(ni >= 0 && ni < r && nj >= 0 && nj < c && !(ni == pi && nj == pj) && a[ni][nj] == '1' && v[ni][nj] == 0) {
		dfs_visit(ni, nj, ci, cj);
	}
	ni = ci;
	nj = cj+1;
	if(ni >= 0 && ni < r && nj >= 0 && nj < c && !(ni == pi && nj == pj) && a[ni][nj] == '1' && v[ni][nj] == 0) {
		dfs_visit(ni, nj, ci, cj);
	}
}

int dfs() {
	int i, j, cnt;
	cnt = 0;
	for(i = 0 ;i < r ; i++) {
		for(j = 0 ; j < c ; j++) {
			v[i][j] = 0;
		}
	}
	for(i = 0 ; i < r ; i++) {
		for(j = 0 ; j < c ; j++) {
			if(a[i][j] == '1' && v[i][j] == 0) {
				cnt++;
				dfs_visit(i, j, -1, -1);
			}
		}
	}
	return cnt;
}

int main() {
	int t, n, h, x, y, i;
	char ch, z;
	scanf("%d", &t);
	h = 0;
	while(t--) {
		h++;
		printf("Case #%d:\n", h);
		scanf("%d%d", &r, &c);
		for(i = 0 ; i < r ; i++) {
			scanf("%s", a[i]);
		}
		scanf("%d", &n);
		for(i = 0 ; i < n ; i++) {
			scanf(" %c", &ch);
			if(ch == 'M') {
				scanf("%d%d %c", &x, &y, &z);
				a[x][y] = z;
			}
			else {
				printf("%d\n", dfs());
			}
		}
	}
}