#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define N 100005

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

typedef struct _elem{
	int pos;
	int sym;
	int num;

	bool operator < (const _elem& e) const {
		if(pos == e.pos) {
			return sym < e.sym;
		}
		return pos < e.pos;
	}
}elem;

typedef struct _elem1 {
	int ecount;
	int cnt;
	int index;

	bool operator < (const _elem1& e) const {
		if(ecount == e.ecount) {
			return cnt > e.cnt;
		}
		else ecount < e.ecount;
	}
}elem1;

vector <pii> intv;
vector <elem> ve;
vector <elem1> ve1;
map < int, int > mp;
int n, l1, r1, a, b, c1, c2, m;


void gen() {
	lli temp;
	int xprev, yprev, x, y, l, r, i;
	
	intv.clear();
	intv.PB(MP(l1, r1));
	
	xprev = l1;
	yprev = r1;

	for(i = 2 ; i <= n ; i++) {
		temp = a * 1LL * xprev + b * 1LL * yprev + c1 * 1LL;
		x = temp % m;
		temp = a * 1LL * yprev + b * 1LL * xprev + c2 * 1LL;
		y = temp % m;
		l = min(x, y);
		r = max(x, y);
		intv.PB(MP(l, r));
		xprev = x;
		yprev = y;
	}

	// for(i = 0 ; i < intv.size() ; i++) {
	// 	printf("(%d, %d) ", intv[i].FF, intv[i].SS);
	// }
	// printf("\n");
}

void test() {
	intv.clear();
	intv.PB(MP(1, 2));
	intv.PB(MP(3, 5));
}

void getelems() {
	int i;
	ve.clear();
	for(i = 0 ; i < intv.size() ; i++) {
		ve.PB({intv[i].FF, 0, i});
		ve.PB({intv[i].SS, 1, i});
	}
	sort(ve.begin(), ve.end());

	// for(i = 0 ; i < ve.size() ; i++) {
	// 	printf("(%d, %d, %d) ", ve[i].pos, ve[i].sym, ve[i].num);
	// }
	// printf("\n");
}

void simulate() {
	int i, c, s, prev;
	c = 0;
	s = 0;
	prev = 0;
	ve1.clear();
	for(i = 0 ; i < ve.size() ; i++) {
		if(ve[i].sym == 0) {
			ve1.PB({c, ve[i].pos - prev, s});
			c++;
			s += ve[i].num;
			prev = ve[i].pos;
		}
		else {
			ve1.PB({c, ve[i].pos - prev + 1, s});
			c--;
			s -= ve[i].num;
			prev = ve[i].pos + 1;
		}
	}
	
	// for(i = 0 ; i < ve1.size() ; i++) {
	// 	printf("[%d, %d, %d] ", ve1[i].ecount, ve1[i].cnt, ve1[i].index);
	// }
	// printf("\n");

	// sort(ve1.begin(), ve1.end());

	// for(i = 0 ; i < ve1.size() ; i++) {
	// 	printf("[%d, %d, %d] ", ve1[i].ecount, ve1[i].cnt, ve1[i].index);
	// }
	// printf("\n");
}

int getarea() {
	int tot, i, maxm;
	tot = 0;
	for(i = 0 ; i < ve1.size() ; i++) {
		if(ve1[i].ecount == 0)
			tot += ve1[i].cnt;
	}
	maxm = ve[ve.size()-1].pos + 1;
	// printf("max=%d | tot=%d\n", maxm, tot);
	return maxm - tot;
}

int getans() {
	int maxm, i;
	mp.clear();
	for(i = 0 ; i < ve1.size() ; i++) {
		if(ve1[i].ecount == 1) {
			mp[ve1[i].index] += ve1[i].cnt;
		}
	}
	maxm = 0;
	for(auto it : mp) {
		maxm = max(maxm, it.SS);
	}
	// printf("maxm=%d\n", maxm);
	return maxm;
}

int main() {
	int t, ans, tot, h;
	scanf("%d", &t);
	h = 0;
	while(t--) {
		h++;
		scanf("%d%d%d%d%d%d%d%d", &n, &l1, &r1, &a, &b, &c1, &c2, &m);
		gen();
		// test();
		getelems();
		simulate();
		tot = getarea();
		ans = getans();
		printf("Case #%d: %d\n", h, tot - ans);
	}
	return 0;
}