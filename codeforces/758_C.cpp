#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long int lli;
const int INF = 1e9 + 7;

int main() {
	lli n, m, x, y, k, tot, glob, r, c, f, ans, maxm, minm;
	cin >> n >> m >> k >> x >> y;
	x--, y--;
	tot = n * m;
	if(n <= 2) {
		glob = k / tot;
		minm = maxm = glob;
		k = k % tot;
		if(k > 0)
			maxm++;
		r = k / m;
		c = k % m;
		ans = minm;
		if(x < r)
			ans = maxm;
		else if(x == r){
			if(y < c)
				ans = maxm;
		}
	}
	else {
		glob = k / (2LL * tot);
		minm = glob;
		glob *= 2LL;
		maxm = glob;
		k = k % (2LL * tot);
		f = 0;
		if(k > m)
			maxm++;
		if(k >= tot) {
			f = 1;
			minm++;
			k -= tot;
			if(k > 0)
				maxm++;
		}
		r = k / m;
		c = k % m;
		if(x == 0 || x == n-1) {
			ans = minm;
			if(k > 0) {
				if(f == 0) {
					if(r > x)
						ans++;
					else if(r == x){
						if(c >= y)
							ans++;
					}
				}
				else {
					if(r > n-x)
						ans++;
					else if(r == n-x){
						if(c >= y)
							ans++;
					}
				}
			}
		}
		else {
			ans = maxm;
			if(k > 0) {
				if(f == 0) {
					if(r < x)
						ans--;
					else if(r == x){
						if(c < y)
							ans--;
					}
				}
				else {
					if(r < n-x)
						ans--;
					else if(r == n-x){
						if(c < y)
							ans--;
					}
				}
			}
		}
	}
	cout << maxm << " " << minm << " " << ans << endl;
	return 0;
}