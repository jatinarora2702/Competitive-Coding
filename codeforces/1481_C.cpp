#include <bits/stdc++.h>
#define N 100005
using namespace std;

int a[N], b[N], c[N];
vector<int> g[N];

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		for(int i = 1; i <= n; i++) {
			g[i].clear();
		}
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for(int i = 0; i < n; i++) {
			cin >> b[i];
			if (a[i] != b[i]) {
				g[b[i]].push_back(i);
			}
		}
		for(int i = 0; i < m; i++) {
			cin >> c[i];
		}
		vector<int> ans(m);
		int pos = -1;
		if(g[c[m-1]].size() > 0) {
			pos = g[c[m-1]].back();
			g[c[m-1]].pop_back();
		}
		else {
			for(int i = 0; i < n; i++) {
				if (b[i] == c[m-1]) {
					pos = i;
					break;
				}
			}
		}
		if (pos == -1) {
			cout << "NO\n";
			continue;
		}
		ans[m-1] = pos + 1;
		for(int i = 0; i < m-1; i++) {
			if (g[c[i]].size() > 0) {
				ans[i] = g[c[i]].back() + 1;
				g[c[i]].pop_back();
			}
			else {
				ans[i] = pos + 1;
			}
		}
		int f = 1;
		for(int i = 1; i <= n; i++) {
			if(g[i].size() > 0) {
				f = 0;
				break;
			}
		}
		if (f == 0) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
			for(int i = 0; i < ans.size(); i++) {
				cout << ans[i] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}