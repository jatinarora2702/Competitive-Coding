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

vector < int > g[N];
pii p[N];
map < int, map < int, int > > mp;
int visited[N], ans;

void dfs(int s, int x, int y) {
	int i, nx, ny, f, k;
	visited[s] = 1;
	p[s] = MP(x, y);
	mp[x][y] = 1;
	if(g[s].size() > 4) {
		ans = 0;
		return;
	}
	for(i = 0 ; i < g[s].size() ; i++) {
		if(visited[g[s][i]] == 0 && ans == 1) {
			f = 0;
			k = 100;
			while(f == 0 && k > 0) {
				nx = x + k;
				ny = y;
				if(mp[nx][ny] != 1) {
					f = 1;
					dfs(g[s][i], nx, ny);
					break;
				}
				nx = x;
				ny = y - k;
				if(mp[nx][ny] != 1) {
					f = 1;
					dfs(g[s][i], nx, ny);
					break;
				}
				nx = x - k;
				ny = y;
				if(mp[nx][ny] != 1) {
					f = 1;
					dfs(g[s][i], nx, ny);
					break;
				}
				nx = x;
				ny = y + k;
				if(mp[nx][ny] != 1) {
					f = 1;
					dfs(g[s][i], nx, ny);
					break;
				}
				k--;
			}
			if(f == 0) {
				ans = 0;
				break;
			}
		}
	}
}

int main() {
	int n, m, i, x, y;
	ans = 1;
	scanf("%d", &n);
	for(i = 0 ; i < n-1 ; i++) {
		scanf("%d%d", &x, &y);
		x--, y--;
		g[x].PB(y);
		g[y].PB(x);
	}
	for(i = 0 ; i < n ; i++)
		visited[i] = 0;
	dfs(0, 0, 0);
	if(ans == 0) {
		printf("NO\n");
	}
	else {
		printf("YES\n");
		for(i = 0 ; i < n ; i++) {
			printf("%d %d\n", p[i].FF, p[i].SS);
		}
	}
	return 0;
}