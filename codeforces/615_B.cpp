#include <bits/stdc++.h>
#define N 100005
#define PB push_back
using namespace std;
typedef long long int lli;
vector < int > g[N];
int a[N], dp[N];
lli b[N];
int main() {
	int n, m, x, y;	
	lli maxm;
	scanf("%d%d", &n, &m);
	// cout << "yy\n";
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d", &x, &y);
		x--, y--;
		// cout << "i=" << i << endl;
		a[x]++;
		a[y]++;
		if(x < y)
			g[y].PB(x);
		else
			g[x].PB(y);
	}
	// cout << "uu\n";
	for(int i = 0 ; i < n ; i++){
		dp[i] = 0;
		for(int j = 0 ; j < g[i].size() ; j++)
			dp[i] = max(dp[i], dp[g[i][j]]);
		dp[i]++;
		// cout << "ll\n";
		b[i] = (lli)dp[i] * (lli)a[i];
	}
	maxm = 0;
	// for(int i = 0 ; i < n ; i++){
	// 	cout << b[i] << " ";
	// }
	// cout << endl;
	// cout << "here\n";
	for(int i = 0 ; i < n ; i++)
		maxm = max(maxm, b[i]);
	cout << maxm;
	return 0;
}