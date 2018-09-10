#include <bits/stdc++.h>
using namespace std;

#define N 1000005

const int INF = 1e9 + 7;

vector < int > g[N];
int dp[N], p[N], temp[N], visited[N];

void dfs(int s) {
	int i, val;
	if(dp[s] == INF) {
		val = temp[s];
		for(i = 0 ; i < g[s].size() ; i++) {
			dfs(g[s][i]);
			val += dp[g[s][i]];
		}
		// cout << "s: " << s << " dp: " << val << endl;
		dp[s] = val;
	}
}

void invalidate(int s) {
	int i;
	visited[s] = 1;
	for(i = 0 ; i < g[s].size() ; i++) {
		if(visited[g[s][i]] == 0) {
			invalidate(g[s][i]);
		}
	}
	dp[s] = INF;
}

int getvalid(int s, int val) {
	int i, stat;
	visited[s] = 1;
	stat = 0;
	for(i = 0 ; i < g[s].size() ; i++) {
		if(visited[g[s][i]] == 0) {
			stat = getvalid(g[s][i], val);
			if(stat != 0)
				return stat;
		}
	}
	if(dp[s] == val)
		stat = s;
	return stat;
}

int main() {
	int root, n, i, x, y, ans1, ans2, s;
	cin >> n;
	root = 1;
	for(i = 0 ; i < n ; i++) {
		cin >> x >> y;
		p[i+1] = x;
		temp[i+1] = y;
		if(x == 0)
			root = i+1;
		g[x].push_back(i+1);
	}
	dp[0] = INF;
	visited[0] = 0;
	for(i = 0 ; i < n ; i++) {
		dp[i+1] = INF;
		visited[i+1] = 0;
	}
	// int j;
	// for(i = 0 ; i < n ; i++) {
	// 	cout << i+1 << ": ";
	// 	for(j = 0 ; j < g[i+1].size() ; j++)
	// 		cout << g[i+1][j] << " ";
	// 	cout << endl;
	// }
	dfs(root);
	// cout << "dp: ";
	// for(i = 0 ; i < n ; i++) {
	// 	cout << dp[i+1] << " ";
	// }
	// cout << endl;
	if(dp[root] % 3 != 0)
		cout << "-1" << endl;
	else {
		s = dp[root] / 3;
		ans1 = getvalid(root, s);
		if(ans1 == 0)
			cout << "-1" << endl;
		else {
			x = p[ans1];
			while(x != 0) {
				dp[x] -= s;
				x = p[x];
			}
			// invalidate(ans1);
			dp[ans1] = INF;
			ans2 = 0;
			for(i = 0 ; i < n ; i++) {
				if(dp[i+1] == s) {
					ans2 = i+1;
					break;
				}
			}
			if(ans2 == 0)
				cout << "-1" << endl;
			else
				cout << ans1 << " " << ans2 << endl;
		}
	}
	return 0;
}