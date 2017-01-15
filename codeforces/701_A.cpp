#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define N 105

using namespace std;

vector < int > v[N];
vector < pair < int, int > > ans;
int a[N], b[N];

int main() {
	int n, x, i, j, s, y;
	scanf("%d", &n);
	s = 0;
	for(i = 0 ; i < n ; i++){
		scanf("%d", &x);
		v[x].PB(i+1);
		a[i] = x;
		b[i] = 0;
		s += x;
	}
	y = (2 * s) / n;
	for(i = 0 ; i < n ; i++) {
		if(b[i] == 0) {
			b[i] = 1;
			x = y - a[i];
			for(j = 0 ; j < v[x].size() ; j++) {
				if(b[v[x][j]-1] == 0) {
					b[v[x][j]-1] = 1;
					ans.PB(MP(i+1, v[x][j]));
					break;
				}
			}
		}
	}
	for(i = 0 ; i < ans.size() ; i++)
		printf("%d %d\n", ans[i].FF, ans[i].SS);
	return 0;
}