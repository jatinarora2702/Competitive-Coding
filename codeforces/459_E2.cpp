#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int dp[N], tmp[N];
vector < pair < int, int > > w[N];
int main(){
	int n, m, x, y, wt, u, v;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d%d", &x, &y, &wt);
		w[wt].push_back(make_pair(x, y));
	}
	for(int i = 0 ; i <= n ; i++)
		dp[i] = 0;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < w[i].size() ; j++){
			u = w[i][j].first; v = w[i][j].second;
			dp[v] = max(dp[v], dp[u]+1);
		}
	}
	int maxm = 0;
	for(int i = 0 ; i <= n ;i++)
		if(maxm < dp[i])
			maxm = dp[i];
	printf("%d", maxm);
	return 0;
}