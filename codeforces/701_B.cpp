#include <bits/stdc++.h>

#define MP make_pair
#define FF first
#define SS second
#define PB push_back

#define N 100005

using namespace std;

typedef long long int lli;

int row[N], col[N];
lli ans[N];
int main() {
	int n, m, xr, xc, i, x, y;
	scanf("%d%d", &n, &m);
	xr = xc = n;
	for(i = 0 ; i < m ; i++) {
		scanf("%d%d", &x, &y);
		if(row[x] == 0) {
			row[x] = 1;
			xr--;
		}
		if(col[y] == 0) {
			col[y] = 1;
			xc--;
		}
		// printf("[%d %d]\n", xc, xr);
		ans[i] = (lli)xr * (lli)xc;
	}
	for(i = 0 ; i < m ; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}