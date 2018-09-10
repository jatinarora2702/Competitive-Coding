#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
using namespace std;

typedef long long ll;

const int N = 3005;

int v[N];
vector < int > g[N], gt;
map < int, int > mp;

ll counter(int s) {
	int i, j, c1, c2;
	ll cnt = 0LL;
	mp.clear();
	for(i = 0 ; i < g[s].size() ; i++) {
		c1 = g[s][i];
		if(c1 != s) {
			for(j = 0 ; j < g[c1].size() ; j++) {
				c2 = g[c1][j];
				if(c2 != s && c2 != c1)
					mp[c2]++;
			}
		}
	}
	for(auto &it : mp) {
		c1 = it.SS;
		cnt += ((ll)c1 * (ll)(c1-1)) / 2LL;
	}
	return cnt;
}

int main() {
	int n, m, i, x, y;
	ll cnt = 0LL;
	scanf("%d%d", &n, &m);
	for(i = 0 ; i < m ; i++) {
		scanf("%d%d", &x, &y);
		x--;
		y--;
		g[x].PB(y);
	}
	for(i = 0 ; i < n ; i++)
		cnt += counter(i);
	printf("%lld\n", cnt);
	return 0;
}