#include <bits/stdc++.h>
using namespace std;

#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define umap unordered_map
#define boost ios_base::sync_with_stdio(false)

#define vrep(i, c) for(__typeof((c).begin()) i = (c).begin() ; i != (c).end() ; ++i)
#define vrepn(i, c) for(__typeof((c).rbegin()) i = (c).rbegin() ; i != (c).rend() ; ++i)
#define rep(i, a, b) for(int (i) = (a) ; (i) < (b) ; ++(i))
#define repn(i, a, b) for(int (i) = (a) ; (i) >= (b) ; --(i))
#define For(i, c) for(auto &(i) : (c))
#define all(c) c.begin(), c.end()
#define sz(c) (int)((c).size())

#define L(a) (((a) << 1) + 1)
#define R(a) (((a) << 1) + 2)
#define myread() freopen("inp.in", "r", stdin)
#define mywrite() freopen("ans.out", "w", stdout)

#define S(a) scanf("%d", &a)
#define S2(a, b) scanf("%d%d", &a, &b)
#define S3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define P(a) printf("%d\n", a)
#define P2(a, b) printf("%d %d\n", a, b)
#define Pr(a) printf("%d ", a)
#define Pn printf("\n")
#define error(a) cerr << #a << " = " << (a) << endl
#define error2(a, b) cerr << "(" << #a << ", " << #b << ") = (" << (a) << ", " << (b) << ")" << endl
#define error3(a, b, c) cerr << "(" << #a << ", " << #b << ", " << #c << ") = (" << (a) << ", " << (b) << ", " << (c) << ")" << endl
#define error4(a, b, c, d) cerr << "(" << #a << ", " << #b << ", " << #c << ", " << #d << ") = (" << (a) << ", " << (b) << ", " << (c) << ", " << (d) << ")" << endl
#define errorp(a) cerr << #a << " = (" << ((a).FF) << ", " << ((a).SS) << ")" << endl
#define debug(a) cerr << "DEBUG: Reached Here: " << (a) << endl
#define coud(a, b) cout << fixed << setprecision((b)) << (a) << endl

typedef long long int lli;
typedef long double ld;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < pii > vpi;
typedef complex < double > point;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;
const ld pi = acos(-1.0);

#define N 10000

typedef struct _node {
	int x, px, lx;
	bool operator < (const _node &_n) const {
		return lx > _n.lx;
	}
}node;

priority_queue < node > pq;
vpi g[N];
int p[N], n;

void getmst() {
	node ntemp;
	while(!pq.empty()) {
		pq.pop();
	}
	rep(i, 0, n) {
		p[i] = -1;
	}
	pq.push({0, 0, 0});
	while(!pq.empty()) {
		ntemp = pq.top();
		pq.pop();
		if(p[ntemp.x] == -1) {
			p[ntemp.x] = ntemp.px;
			vrep(i, g[ntemp.x]) {
				if(p[i->FF] == -1) {
					pq.push({i->FF, ntemp.x, i->SS});
				}
			}
		}
	}
}

int main() {
	int m, x, y, z;
	S2(n, m);
	rep(i, 0, m) {
		S3(x, y, z);
		g[x].PB(MP(y, z));
		g[y].PB(MP(x, z));
	}
	getmst();
	rep(i, 0, n) {
		error2(i, p[i]);
	}
	return 0;
}

