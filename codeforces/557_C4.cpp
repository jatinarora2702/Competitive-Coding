#include <bits/stdc++.h>
#define FF first
#define SS second
#define N 100005
#define M 205

using namespace std;
const int INF = 1e9+7;

int l[N], d[N], a[M][N], b[N];
map < int, int > mplc;
map < int, int > mplc1;
map < int, int > mple;
map < int, int > :: reverse_iterator it;
int main() {
	int n, m, x, s, t, i, j, k;
	scanf("%d", &n);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &l[i]);
		mplc[l[i]]++;
	}
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &d[i]);
	}
	for(i = 0 ; i < n ; i++) {
		a[d[i]][l[i]]++;
	}
	for(i = 0 ; i < M ; i++) {
		s = 0;
		for(j = 1 ; j < N ; j++) {
			m = s + a[i][j];
			a[i][j] = s;
			s = m;
		}
	}
	s = 0;
	for(it = mplc.rbegin() ; it != mplc.rend() ; it++) {
		m = s + it->SS;
		mplc1[it->FF] = s;
		s = m;
	}
	for(i = 0 ; i < n ; i++) {
		mple[l[i]] += d[i];
	}
	s = 0;
	for(it = mple.rbegin() ; it != mple.rend() ; it++) {
		m = it->SS + s;
		it->SS = s;
		s = m;
	}
	k = INF;
	for(it = mplc.rbegin() ; it != mplc.rend() ; it++) {
		m = 2 * it->SS - 1;
		s = mple[it->FF];
		x = mplc1[it->FF];
		x = n - x;
		for(i = 0 ; i < M ; i++) {
			if(x > m) {
				t = min(x-m, a[i][it->FF]);
				x -= t;
				s += t * i;
			}
			else {
				break;
			}
		}
		k = min(k, s);
	}
	printf("%d\n", k);
	return 0;
}