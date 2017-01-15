#include <bits/stdc++.h>
#define PB push_back
#define FF first
#define SS second
#define MP make_pair
using namespace std;
#define N 10005
#define M 105

const int INF = 1e9 + 7;

vector < pair < int, int > > vht[N];
int a[M][M], b[M][M], visited[M][M], n, m;
int d[][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};

int dfs_getmin(int si, int sj, int h) {
	// cerr << "inmin\n";
	int minm, ni, nj, i;
	visited[si][sj] = h;
	minm = INF;
	for(i = 0 ; i < 4 ; i++) {
		ni = si + d[0][i];
		nj = sj + d[1][i];
		if(ni >= 0 && ni < n && nj >= 0 && nj < m) {
			if(b[ni][nj] == b[si][sj]) {
				if(visited[ni][nj] != h) {
					minm = min(minm, dfs_getmin(ni, nj, h));
				}
			}
			else {
				minm = min(minm, b[ni][nj]);
			}
		}
		else {
			minm = 0;
		}
	}
	return minm;
}

void dfs_assign(int si, int sj, int val) {
	int ni, nj, i;
	// cerr << "inassign\n";
	visited[si][sj] = 0;
	for(i = 0 ; i < 4 ; i++) {
		ni = si + d[0][i];
		nj = sj + d[1][i];
		if(ni >= 0 && ni < n && nj >= 0 && nj < m && visited[ni][nj] != 0 && b[ni][nj] == b[si][sj]) {
			dfs_assign(ni, nj, val);
		}
	}
	b[si][sj] = val;
	vht[val].PB(MP(si, sj));
}

int main() {
	int t, h, i, j, sum, minm, xi, xj;
	scanf("%d", &t);
	h = 0;
	while(t--) {
		h++;
		scanf("%d%d", &n, &m);
		for(i = 0 ; i < N ; i++) {
			vht[i].clear();
		}
		for(i = 0 ; i < n ; i++) {
			for(j = 0 ; j < m ; j++) {
				scanf("%d", &a[i][j]);
				b[i][j] = a[i][j];
				vht[b[i][j]].PB(MP(i, j));
			}
		}
		for(i = 0 ; i < n ; i++) {
			for(j = 0 ; j < m ; j++) {
				visited[i][j] = 0;
			}
		}
		for(i = 0 ; i < N ; i++) {
			for(j = 0 ; j < vht[i].size() ; j++) {
				xi = vht[i][j].FF;
				xj = vht[i][j].SS;
				// cerr << "xi=" << xi << " xj=" << xj << " h=" << i << endl;
				if(visited[xi][xj] == 0) {
					minm = dfs_getmin(xi, xj, i);
					if(minm > b[xi][xj]) {
						dfs_assign(xi, xj, minm);
					}
				}
				// cerr << "minm=" << minm << endl;
			}
		}
		sum = 0;
		for(i = 0 ; i < n ; i++) {
			for(j = 0 ; j < m ; j++) {
				sum += (b[i][j] - a[i][j]);
			}
		}
		if(h == 12) {
			cerr << "Case: " << h << endl;
			cerr << "a:\n";
			for(i = 0 ; i < n ; i++) {
				for(j = 0 ; j < m ; j++) {
					cerr << a[i][j] << " ";
				}
				cerr << "\n";
			}
			cerr << "b:\n";
			for(i = 0 ; i < n ; i++) {
				for(j = 0 ; j < m ; j++) {
					cerr << b[i][j] << " ";
				}
				cerr << "\n";
			}
			cerr << "sum=" << sum << endl;
			cerr << "-------------------------------\n";
		}
		cout << "Case #" << h << ": " << sum << endl;
	}
	return 0;
}