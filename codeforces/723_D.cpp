#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
using namespace std;

const int N = 55;

typedef pair < int, int > pii;

int a[N][N], visit[N][N], n, m;
vector < pair < int, pii > > v;

int count(int si, int sj) {
	int cnt, ni, nj, c;
	visit[si][sj] = 1;
	cnt = 1;
	ni = si + 1;
	nj = sj;
	if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
		if (a[ni][nj] == 0 && visit[ni][nj] == 0) {
			c = count(ni, nj);
			if (c == -1)
				return -1;
			cnt += c;
		}
	}
	else
		return -1;
	ni = si - 1;
	nj = sj;
	if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
		if (a[ni][nj] == 0 && visit[ni][nj] == 0) {
			c = count(ni, nj);
			if (c == -1)
				return -1;
			cnt += c;
		}
	}
	else
		return -1;
	ni = si;
	nj = sj + 1;
	if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
		if (a[ni][nj] == 0 && visit[ni][nj] == 0) {
			c = count(ni, nj);
			if (c == -1)
				return -1;
			cnt += c;
		}
	}
	else
		return -1;
	ni = si;
	nj = sj - 1;
	if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
		if (a[ni][nj] == 0 && visit[ni][nj] == 0) {
			c = count(ni, nj);
			if (c == -1)
				return -1;
			cnt += c;
		}
	}
	else
		return -1;
	return cnt;
}

void fill(int si, int sj) {
	int ni, nj;
	visit[si][sj] = 1;
	a[si][sj] = 1;
	ni = si + 1;
	nj = sj;
	// printf("[%d, %d]\n", ni, nj);
	if (ni >= 0 && ni < n && nj >= 0 && nj < m && a[ni][nj] == 0 && visit[ni][nj] == 0)
		fill(ni, nj);
	ni = si - 1;
	nj = sj;
	// printf("[%d, %d]\n", ni, nj);
	if (ni >= 0 && ni < n && nj >= 0 && nj < m && a[ni][nj] == 0 && visit[ni][nj] == 0)
		fill(ni, nj);
	ni = si;
	nj = sj + 1;
	// printf("[%d, %d]\n", ni, nj);
	if (ni >= 0 && ni < n && nj >= 0 && nj < m && a[ni][nj] == 0 && visit[ni][nj] == 0)
		fill(ni, nj);
	ni = si;
	nj = sj - 1;
	// printf("[%d, %d]\n", ni, nj);
	if (ni >= 0 && ni < n && nj >= 0 && nj < m && a[ni][nj] == 0 && visit[ni][nj] == 0)
		fill(ni, nj);
}

int main() {
	int k, i, j, cnt, c;
	string s;
	scanf("%d%d%d", &n, &m, &k);
	for(i = 0 ; i < n ; i++) {
		cin >> s;
		for(j = 0 ; j < s.length() ; j++)
			a[i][j] = (s[j] == '.') ? 0 : 1;
	}
	cnt = 0;
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < m ; j++) {
			if (a[i][j] == 0 && visit[i][j] == 0) {
				cnt = count(i, j);
				if (cnt > 0)
					v.PB(MP(cnt, MP(i, j)));
			}
		}
	}
	sort(v.begin(), v.end());
	// for(i = 0 ; i < v.size() ; i++) {
	// 	printf("%d(%d, %d) ", v[i].FF, v[i].SS.FF, v[i].SS.SS);
	// }
	// printf("\n");
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < m ; j++)
			visit[i][j] = 0;
	}
	cnt = v.size();
	// cout << cnt << endl;	
	c = 0;
	i = 0;
	while(cnt > k) {
		c += v[i].FF;
		fill(v[i].SS.FF, v[i].SS.SS);
		cnt--;
		i++;
	}
	printf("%d\n", c);
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < m ; j++)
			printf("%c", ((a[i][j] == 0) ? '.' : '*'));
		printf("\n");
	}
	return 0;
}