#include <bits/stdc++.h>
#define N 100
#define FF first
#define SS second
using namespace std;
typedef long long int lli;
map < lli, lli > mp, mpc[2];
int main() {
	int q, i, ch, f;
	lli u, v, w, x, s;
	scanf("%d", &q);
	mp[1] = 0LL;
	for(i = 0 ; i < q ; i++) {
		scanf("%d", &ch);
		if(ch == 1) {
			cin >> u >> v >> w;
			mpc[0].clear();
			mpc[1].clear();
			x = u;
			while(x >= 1LL) {
				mpc[0][x] = 1LL;
				x /= 2LL;
			}
			x = v;
			while(x >= 1LL) {
				mpc[1][x] = 1LL;
				x /= 2LL;
			}
			x = 0LL;
			for(auto it : mpc[0]) {
				if(mpc[1].find(it.FF) == mpc[1].end()) {
					break;
				}
				x = it.FF;
			}
			f = 0;
			for(auto it : mpc[0]) {
				if(f == 1) {
					mp[it.FF] += w;
				}
				if(it.FF == x)
					f = 1;
			}
			f = 0;
			for(auto it : mpc[1]) {
				if(f == 1) {
					mp[it.FF] += w;
				}
				if(it.FF == x)
					f = 1;
			}
		}
		else {
			cin >> u >> v;
			mpc[0].clear();
			mpc[1].clear();
			x = u;
			s = 0LL;
			while(x >= 1LL) {
				mpc[0][x] = s;
				s += mp[x];
				x /= 2LL;
			}
			x = v;
			s = 0LL;
			while(x >= 1LL) {
				mpc[1][x] = s;
				s += mp[x];
				x /= 2LL;
			}
			x = 0LL;
			for(auto it : mpc[0]) {
				if(mpc[1].find(it.FF) == mpc[1].end()) {
					break;
				}
				x = it.FF;
			}
			s = mpc[0][x] + mpc[1][x];
			cout << s << "\n";
		}
	}
	return 0;
}