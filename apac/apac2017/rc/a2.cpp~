#include <bits/stdc++.h>
using namespace std;

#define N 25

int n, m, a[N][N], visited[N][N];
int d[2][4] = {{-1, 1, 0, 0}, {0, 0, 1, -1}};
double prob[2], powProb[2][N];

double dfs(int si, int sj, int k) {
	double ret, curr;
	int f, ni, nj, i, v;
	if(k <= 0) {
		return 0;
	}
	ret = 0;
	for(i = 0 ; i < 4 ; i++) {
		ni = si + d[0][i];
		nj = sj + d[1][i];
		if(ni >= 0 && ni < n && nj >= 0 && nj < m) {
			f = a[ni][nj];
			v = visited[ni][nj];
			curr = powProb[f][v];
			visited[ni][nj]++;
			curr += dfs(ni, nj, k-1);
			ret = max(ret, curr);
			visited[ni][nj]--;
		}
	}
	return ret;
}

void solve() {
	int i, j, si, sj, k;
	double ans;
	char ch;
	scanf("%d%d%d%d%d", &n, &m, &si, &sj, &k);
	cin >> prob[0] >> prob[1];
	powProb[0][0] = prob[0];
	powProb[1][0] = prob[1];
	for(i = 1 ; i < k ; i++) {
		powProb[0][i] = powProb[0][i-1] * (1 - prob[0]);
		powProb[1][i] = powProb[1][i-1] * (1 - prob[1]);
	}
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < m ; j++) {
			scanf(" %c", &ch);
			a[i][j] = (ch == '.') ? 1 : 0;
		}
	}
	memset(visited, 0, sizeof(visited));
	ans = dfs(si, sj, k);
	cout << setprecision(7) << fixed << ans << endl;
}

int main() {
	int t, h;
	scanf("%d", &t);
	h = 0;	
	while(t--) {
		h++;		
		cout << "Case #" << h << ": ";
		solve();
	}
	return 0;
}
