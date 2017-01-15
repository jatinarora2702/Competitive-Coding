#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define N 2005

using namespace std;
typedef long long int lli;
typedef long double ld;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

int ap[N], ae[N], at[N], c[4], fr[4];
map < int, int > mp[2];

pii red(int p, int q) {
	int g;
	while(1) {
		g = __gcd(p, q);
		if(g == 1) {
			break;
		}
		p /= g;
		q /= g;
	}
	return MP(p, q);
}

int main() {
	int t, h, np, ne, nt, i, j, k, temp, f, v, m, p, q, ans;
	pii pr;
	scanf("%d", &t);
	h = 0;
	while(t--) {
		h++;
		printf("Case #%d:\n", h);
		scanf("%d%d%d", &np, &ne, &nt);
		for(i = 0 ; i < np ; i++) {
			scanf("%d", &ap[i]);
		}
		for(i = 0 ; i < ne ; i++) {
			scanf("%d", &ae[i]);
		}
		for(i = 0 ; i < nt ; i++) {
			scanf("%d", &at[i]);
		}
		c[0] = c[1] = 0;
		mp[0].clear();
		mp[1].clear();
		for(i = 0 ; i < np ; i++) {
			for(j = 0 ; j < ne ; j++) {
				temp = ap[i]*ae[j];
				if(mp[0].find(temp) == mp[0].end()) {
					mp[0][temp] = ae[j];
					c[0]++;
				}
				else {
					mp[0][temp] = 0;
				}
			}
		}
		for(i = 0 ; i < nt ; i++) {
			for(j = 0 ; j < ne ; j++) {
				temp = at[i]*ae[j];
				if(mp[1].find(temp) == mp[1].end()) {
					mp[1][temp] = ae[j];
					c[1]++;
				}
				else {
					mp[1][temp] = 0;
				}
			}
		}
		f = (c[0] > c[1]) ? 1 : 0;
		scanf("%d", &m);
		for(i = 0 ; i < m ; i++) {
			scanf("%d%d", &p, &q);
			pr = red(p, q);
			fr[0] = pr.FF;
			fr[1] = pr.SS;
			ans = 0;
			for(auto it : mp[f]) {
				if(it.FF % fr[f] == 0) {
					k = it.FF / fr[f];
					k *= fr[f^1];
					v = (it.SS == 0) ? -1 : it.SS;
					if(mp[f^1].find(k) != mp[f^1].end() && mp[f^1][k] != v) {
						ans = 1;
						break;
					}
				}
			}
			if(ans == 1) {
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}
		}
	}
	return 0;
}