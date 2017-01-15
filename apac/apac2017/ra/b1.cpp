#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define N 105

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

int h[N][N], v[N][N], r, c, s;

void update(int xi, int xj, int p) {
	// printf("i=%d | j=%d | p=%d\n", xi, xj, p);
	if(h[xi][xj] < p) {
		// printf("kkk\n");
		s += (p - h[xi][xj]);
		h[xi][xj] = p;
	}
}

int getmin(int si, int prev) {
	int i, j, minm;
	minm = INF;
	update(si, si, prev);
	for(i = si ; i < r-si ; i++) {
		if(i > si && i < r-si-1){
			printf("i=%d | j=%d\n", i, si);
			minm = min(minm, h[i][si]);
		}
		update(i, si, prev);
	}
	for(i = si ; i < r-si ; i++) {
		if(i > si && i < r-si-1){
			printf("i=%d | j=%d\n", i, c-si-1);
			minm = min(minm, h[i][c-si-1]);
		}
		update(i, c-si-1, prev);
	}
	for(j = si ; j < c-si ; j++) {
		if(j > si && j < c-si-1){
			printf("i=%d | j=%d\n", si, j);
			minm = min(minm, h[si][j]);
		}
		update(si, j, prev);
	}
	for(j = si ; j < c-si ; j++) {
		if(j > si && j < c-si-1){
			printf("i=%d | j=%d\n", r-si-1, j);
			minm = min(minm, h[r-si-1][j]);
		}
		update(r-si-1, j, prev);
	}
	return minm;
}
int main() {
	int t, i, j, h1, prev;
	scanf("%d", &t);
	h1 = 0;
	while(t--) {
		h1++;
		scanf("%d%d", &r, &c);
		for(i = 0 ; i < r ; i++) {
			for(j = 0 ; j < c ; j++) {
				scanf("%d", &h[i][j]);
			}
		}
		prev = 0;
		s = 0;
		for(i = 0 ; i < r ; i++) {
			prev = getmin(i, prev);
			cout << "prev:" << prev << endl;
			if(prev == INF)
				break;
		}
		printf("Case #%d: %d\n", h1, s);
	}
	return 0;
}