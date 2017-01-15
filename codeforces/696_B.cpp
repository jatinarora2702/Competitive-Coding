#include <bits/stdc++.h>
#define PB push_back
#define N 100005
using namespace std;
typedef long long int lli;
typedef long double ld;
vector < int > g[N], g1[N], g2[N];
int a[N], n;
ld b[N];

int dfs_visit(int s) {
	int i, k, sum;
	sum = 0;
	for(i = 0 ; i < g[s].size() ; i++) {
		k = dfs_visit(g[s][i]);
		g1[s].PB(k);
		sum += k;
	}
	for(i = 0 ; i < g[s].size() ; i++) {
		g2[s].PB(sum-g1[s][i]);
	}
	sum++;
	return sum;
}
void dfs_exp_visit(int s, ld exp) {
	int i, m;
	m = g[s].size();
	for(i = 0 ; i < g[s].size() ; i++) {
		b[g[s][i]] = exp + 1.0L + g2[s][i] / 2.0L;
		dfs_exp_visit(g[s][i], b[g[s][i]]);
	}
}
int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 1 ; i < n ; i++) {
		scanf("%d", &a[i]);
		a[i]--;
		g[a[i]].PB(i);
	}
	dfs_visit(0);
	// cout << "g:" << endl;
	// for(i = 0 ; i < n ; i++) {
	// 	cout << i << ": ";
	// 	for(j = 0 ; j < g[i].size() ; j++) {
	// 		cout << g[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << "g1:" << endl;
	// for(i = 0 ; i < n ; i++) {
	// 	cout << i << ": ";
	// 	for(j = 0 ; j < g[i].size() ; j++) {
	// 		cout << g1[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << "g2:" << endl;
	// for(i = 0 ; i < n ; i++) {
	// 	cout << i << ": ";
	// 	for(j = 0 ; j < g[i].size() ; j++) {
	// 		cout << g2[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	b[0] = 1.0L;
	dfs_exp_visit(0, 1.0);
	for(i = 0 ; i < n ; i++) {
		cout.precision(12);
		cout << fixed << b[i] << " ";
	}
	cout << "\n";
	return 0;
}