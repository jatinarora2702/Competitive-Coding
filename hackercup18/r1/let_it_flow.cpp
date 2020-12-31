#include <bits/stdc++.h>
#define N 1005

using namespace std;
typedef long long int lli;

const int MOD = 1e9 + 7;

int ans[N];
string g[3];

void precalc() {
	int i;
	lli tmp;
	ans[0] = 1;
	for(i = 1; i < N; i++) {
		tmp = ans[i-1] * 2LL;
		tmp %= MOD;
		ans[i] = tmp;
	}
}

int main() {
	int t, h, i, cnt, f, n, m;
	cin >> t;
	precalc();
	for(h = 1; h <= t; h++) {
		cin >> n;
		for(i = 0; i < 3; i++)
			cin >> g[i];
		if(n % 2 != 0) {
			cout << "Case #" << h << ": 0" << endl;
			continue;
		}
		if(g[0][0] == '#' || g[1][0] == '#' || g[1][n-1] == '#' || g[2][n-1] == '#') {
			cout << "Case #" << h << ": 0" << endl;
			continue;
		}
		cnt = 0;
		f = 1;
		for(i = 1; i < n-1; i += 2) {
			if(g[1][i] == '.' && g[1][i+1] == '.') {
				m = 0;
				if(g[0][i] == '.' && g[0][i+1] == '.')
					m++;
				if(g[2][i] == '.' && g[2][i+1] == '.')
					m++;
				if(m == 0) {
					f = 0;
					break;
				}
				if(m == 2)
					cnt++;
			}
			else {
				f = 0;
				break;
			}
		}
		if(f == 0) {
			cout << "Case #" << h << ": 0" << endl;
			continue;	
		}
		cout << "Case #" << h << ": " << ans[cnt] << endl;
	}
	return 0;
}