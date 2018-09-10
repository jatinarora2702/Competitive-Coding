#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define FF first
#define SS second

using namespace std;

typedef long long ll;

const int N = 20;

int a[N], c[N][N], p[N];
map < int, ll > mp1[2];
map < int, int > mp2[2];

int main() {
	int n, m, x, y, z, i, j, k, f;
	ll t, v;
	scanf("%d%d%d", &n, &m, &k);
	for(i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	for(i = 0 ; i < k ; i++) {
		scanf("%d%d%d", &x, &y, &z);
		x--;
		y--;
		c[x][y] = z;
	}
	mp1[0][0] = 0;
	mp2[0][0] = -1;
	for(i = 0 ; i < m ; i++) {
		f = i % 2;
		mp1[f^1].clear();
		mp2[f^1].clear();
		for(auto &it : mp1[f]) {
			x = it.FF;
			v = it.SS;
			if (!(x & p[j])) {
				z = x + p[j];
				k = mp2[f][x];
				t = v + (ll)a[j] + (ll)c[k][j];
				if (mp1[f^1][z] < t) {
					mp1[f^1][z] = t;
					mp2[f^1][z] = j;
				}
			}
		}
	}
}