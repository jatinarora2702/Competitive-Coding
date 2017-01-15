#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
using namespace std;

typedef long long int lli;
typedef long double ld;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

#define N 100005
pair < int, int > p[N];
map < pair < int, int >, int > mpline;
lli a[N];
int seen[N], n, m;
vector < int > b[2][4*N];

int getdist(pair < int, int > p1, pair < int, int > p2) {
	return min(abs(p1.FF - p2.FF), abs(p1.SS - p2.SS));
}

pair < int, int > getnewprev(pair < int, int > prev, pair < int, int > line, pair < int, int > &newline, int &d) {
	pair < int, int > curr;
	if(prev.SS == 0) {
		if(line.FF == 0) {
			// printf("in\n");
			d = min(n-prev.FF, m);
			curr.FF = prev.FF + d;
			curr.SS = prev.SS + d;
			newline.FF = 1;
			newline.SS = curr.FF + curr.SS;
		}
		else if(line.FF == 1) {
			d = min(prev.FF, m);
			curr.FF = prev.FF - d;
			curr.SS = prev.SS + d;
			newline.FF = 0;
			newline.SS = curr.SS - curr.FF;
		}
	}
	else if(prev.SS == m) {
		if(line.FF == 0) {
			d = min(prev.FF, m);
			curr.FF = prev.FF - d;
			curr.SS = prev.SS - d;
			newline.FF = 1;
			newline.SS = curr.FF + curr.SS;
		}
		else if(line.FF == 1) {
			d = min(n-prev.FF, m);
			curr.FF = prev.FF + d;
			curr.SS = prev.SS - d;
			newline.FF = 0;
			newline.SS = curr.SS - curr.FF;
		}	
	}
	else if(prev.FF == 0) {
		if(line.FF == 0) {
			d = min(n, m-prev.SS);
			curr.FF = prev.FF + d;
			curr.SS = prev.SS + d;
			newline.FF = 1;
			newline.SS = curr.FF + curr.SS;
		}
		else if(line.FF == 1) {
			d = min(n, prev.SS);
			curr.FF = prev.FF + d;
			curr.SS = prev.SS - d;
			newline.FF = 0;
			newline.SS = curr.SS - curr.FF;
		}	
	}
	else if(prev.FF == n) {
		if(line.FF == 0) {
			d = min(n, prev.SS);
			curr.FF = prev.FF - d;
			curr.SS = prev.SS - d;
			newline.FF = 1;
			newline.SS = curr.FF + curr.SS;
		}
		else if(line.FF == 1) {
			// printf("tt\n");
			d = min(n, m-prev.SS);
			curr.FF = prev.FF - d;
			curr.SS = prev.SS + d;
			newline.FF = 0;
			newline.SS = curr.SS - curr.FF;
		}	
	}
	// printf("got(%d, %d) | %d\n", newline.FF, newline.SS, d);
	return curr;
}

int corner(pair < int, int > pr) {
	if(pr.FF == 0 && pr.SS == 0)
		return 1;
	if(pr.FF == 0 && pr.SS == m)
		return 1;
	if(pr.FF == n && pr.SS == 0)
		return 1;
	if(pr.FF == n && pr.SS == m)
		return 1;
	return 0;
}

int main() {
	int k, x, y, i, dist;
	lli d;
	pair < int, int > pprev, ptemp, pnewline, pnewpt;
	scanf("%d%d%d", &n, &m, &k);
	for(i = 0 ; i < k ; i++) {
		scanf("%d%d", &x, &y);
		p[i] = MP(x, y);
		b[0][2*N+y-x].PB(i);
		b[1][2*N+y+x].PB(i);
		// printf("done i=%d\n", i);
	}
	for(i = 0 ; i < k ; i++) {
		a[i] = -1;
		seen[i] = 0;
	}
	d = 0LL;
	pprev = MP(0, 0);
	ptemp = MP(0, 0);
	while(1) {
		// printf("(%d, %d) (%d, %d) %d\n", pprev.FF, pprev.SS, ptemp.FF, ptemp.SS, d);
		if(mpline.find(ptemp) != mpline.end()) {
			break;
		}
		mpline[ptemp] = 1;
		vector < int > &vtemp = b[ptemp.FF][2*N+ptemp.SS];
		for(i = 0 ; i < vtemp.size() ; i++) {
			if(!seen[vtemp[i]]) {
				a[vtemp[i]] = d + (lli)getdist(p[vtemp[i]], pprev);
				seen[vtemp[i]] = 1;
			}
		}
		pnewpt = getnewprev(pprev, ptemp, pnewline, dist);
		// printf("d(%d, %d) | %d\n", pnewline.FF, pnewline.SS, dist);
		d += (lli)dist;
		ptemp.FF = pnewline.FF;
		ptemp.SS = pnewline.SS;
		pprev.FF = pnewpt.FF;
		pprev.SS = pnewpt.SS;
		if(corner(pprev)) {
			break;
		}
	}
	for(i = 0 ; i < k ; i++) {
		cout << a[i] << endl;
	}
	return 0;
}