#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
using namespace std;

const int N = 55;
const int INF = 10000;

typedef pair < int, int > pii;

int a[N][N], n, m;
vector < pair < int, pii > > v;

int count(int si, int sj) {
	int cnt, c;
	if (si < 0 || si >= n || sj < 0 || sj >= m)
		return INF;
	if (a[si][sj] != 0)
		return 0;
	a[si][sj] = 1;
	return 1 + count(si + 1, sj) + count(si - 1, sj) + count(si, sj + 1) + count(si, sj - 1);
}

void fill(int si, int sj) {
	if (si < 0 || si >= n || sj < 0 || sj >= m || a[si][sj] < 0)
		return;
	a[si][sj] = -1;
	fill(si + 1, sj);
	fill(si - 1, sj);
	fill(si, sj + 1);
	fill(si, sj - 1);
}

int main() {
	int k, i, j, cnt, c;
	string s;
	scanf("%d%d%d", &n, &m, &k);
	for(i = 0 ; i < n ; i++) {
		cin >> s;
		for(j = 0 ; j < s.length() ; j++)
			a[i][j] = (s[j] == '.') ? 0 : -1;
	}
	cnt = 0;
	for(i = 1 ; i < n-1 ; i++) {
		for(j = 1 ; j < m-1 ; j++) {
			if (a[i][j] == 0) {
				c = count(i, j);
				if (c < INF)
					v.PB(MP(c, MP(i, j)));
			}
		}
	}
	sort(v.begin(), v.end());
	// for(i = 0 ; i < v.size() ; i++) {
	// 	printf("%d(%d, %d) ", v[i].FF, v[i].SS.FF, v[i].SS.SS);
	// }
	// printf("\n");
	cnt = v.size();
	c = 0;
	for(i = 0 ; i < v.size()-k ; i++) {
		c += v[i].FF;
		fill(v[i].SS.FF, v[i].SS.SS);
	}
	printf("%d\n", c);
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < m ; j++)
			printf("%c", ((a[i][j] == -1) ? '*' : '.'));
		printf("\n");
	}
	return 0;
}