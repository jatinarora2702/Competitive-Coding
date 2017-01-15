#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define N 2005

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef pair < int, int > pii;

map < pii, pii > mpsegs;
map < pii, int > mpdone;
int a[N][N], r, c;

void dfs_segs(int xi, int xj, int ri, int rj) {
	int ni, nj;
	v[xi][xj] = 1;
	ni = xi+1;
	nj = xj;
	if(ni >= 0 && ni < r && nj >= 0 && nj < c) {
		if(a[ri][rj] == a[ni][nj] && v[ni][nj] == 0) {
			dfs_segs(ni, nj, ri, rj);
		}
		else if(a[ni][nj] > a[ri][rj]) {
			mpsegs[ri][rj].SS = min(mpsegs[ri][rj].SS, a[ni][nj]);
		}
	}
	else {
		mpdone[MP(ri, rj)] = 1;
	}
	ni = xi-1;
	nj = xj;
	if(ni >= 0 && ni < r && nj >= 0 && nj < c) {
		if(a[ri][rj] == a[ni][nj] && v[ni][nj] == 0) {
			dfs_segs(ni, nj, ri, rj);
		}
		else if(a[ni][nj] > a[ri][rj]) {
			mpsegs[ri][rj].SS = min(mpsegs[ri][rj].SS, a[ni][nj]);
		}
	}
	else {
		mpdone[MP(ri, rj)] = 1;
	}
	ni = xi;
	nj = xj+1;
	if(ni >= 0 && ni < r && nj >= 0 && nj < c) {
		if(a[ri][rj] == a[ni][nj] && v[ni][nj] == 0) {
			dfs_segs(ni, nj, ri, rj);
		}
		else if(a[ni][nj] > a[ri][rj]) {
			mpsegs[ri][rj].SS = min(mpsegs[ri][rj].SS, a[ni][nj]);
		}
	}
	else {
		mpdone[MP(ri, rj)] = 1;
	}
	ni = xi;
	nj = xj-1;
	if(ni >= 0 && ni < r && nj >= 0 && nj < c) {
		if(a[ri][rj] == a[ni][nj] && v[ni][nj] == 0) {
			dfs_segs(ni, nj, ri, rj);
		}
		else if(a[ni][nj] > a[ri][rj]) {
			mpsegs[ri][rj].SS = min(mpsegs[ri][rj].SS, a[ni][nj]);
		}
	}
	else {
		mpdone[MP(ri, rj)] = 1;
	}
}

void segupd(pii p, int oh, int nh) {
	int i, j;
	if(p.FF >= 0 && p.FF < r && p.SS >= 0 && p.SS < c && a[p.FF][p.SS] == oh) {
		a[p.FF][p.SS] = nh;
		i = p.FF + 1;
		j = p.SS;
		segupd(MP(i, j), oh, nh);
		i = p.FF - 1;
		j = p.SS;
		segupd(MP(i, j), oh, nh);
		i = p.FF;
		j = p.SS + 1;
		segupd(MP(i, j), oh, nh);
		i = p.FF;
		j = p.SS - 1;
		segupd(MP(i, j), oh, nh);
	}

}

void isdone(pii p, pii pr, int val) {
	int i, j;
	i = p.FF;
	j = p.SS;
	if(mpdone[pr] == 1)
		return;
	if(i >= 0 && i < r && j >= 0 && j < c) {
		if(v[i][j] != val && a[i][j] == a[pr.FF][pr.SS]) {
			v[i][j] = val;
			isdone(MP(i, j+1), pr, val);
			isdone(MP(i, j-1), pr, val);
			isdone(MP(i+1, j), pr, val);
			isdone(MP(i-1, j), pr, val);
		}
	}
	else {
		mpdone[pr] = 1;
	}
}

void getsegs() {
	int i, s, cnt;
	s = 0;
	cnt = 2;
	for(i = 0 ; i < r ; i++) {
		for(j = 0 ; j < c ; j++) {
			v[i][j] = 0;
		}
	}
	for(i = 0 ; i < r ; i++) {
		for(j = 0 ; j < c ; j++) {
			if(v[i][j] == 0) {
				p = MP(i, j);
				mpsegs[p] = MP(0, INF);
				mpdone[p] = 0;
				dfs_segs(i, j, i, j);
				if(mpdone[p] == 0) {
					pq.push({p, a[i][j]});
				}
			}
		}
	}
	while(!pq.empty()) {
		qn = pq.top();
		pq.pop();
		if(isdone(qn.pr, cnt++)) {
			s += (qn.nh - a[qn.pr.FF][qn.pr.SS]) * mpsegs[qn.pr].FF;
			segupd(qn.pr, a[qn.pr.FF][qn.pr.SS], qn.nh);
		}
	}
	return s;
}

int main() {
	int t, h, i, j, ans;
	scanf("%d", &t);
	h = 0;
	while(t--) {
		h++;
		scanf("%d%d", &r, &c);
		for(i = 0 ; i < r ; i++) {
			for(j = 0 ; j < c ; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		ans = getsegs();
		printf("Case #%d: %d\n", h, ans);
	}
	return 0;
}