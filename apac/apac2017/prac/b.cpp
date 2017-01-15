#include <bits/stdc++.h>
#define PB push_back
#define FF first
#define SS second
using namespace std;
typedef long long int lli;
vector < int > v[4];
map < int, int > mp[4];
map < int, lli > mp1[2];
int main() {
	int t, n, k, h, x, i, j;
	lli ans;
	scanf("%d", &t);
	h = 0;
	while(t--) {
		h++;
		scanf("%d%d", &n, &k);
		for(i = 0 ; i < 4 ; i++)
			mp[i].clear();
		mp1[0].clear();
		mp1[1].clear();
		for(i = 0 ; i < 4 ; i++) {
			for(j = 0 ; j < n ; j++) {
				scanf("%d", &x);
				v[i].PB(x);
				mp[i][x]++;
			}
		}
		for(auto it1 : mp[0]) {
			for(auto it2 : mp[1]) {
				mp1[0][it1.FF^it2.FF] += (lli)it1.SS * (lli)it2.SS;
			}
		}
		for(auto it1 : mp[2]) {
			for(auto it2 : mp[3]) {
				mp1[1][it1.FF^it2.FF^k] += (lli)it1.SS * (lli)it2.SS;
			}
		}
		ans = 0LL;
		for(auto it : mp1[0]) {
			if(mp1[1].find(it.FF) != mp1[1].end()) {
				ans += it.SS * mp1[1][it.FF];
			}
		}
		cout << "Case #" << h << ": " << ans << "\n";
	}
	return 0;
}