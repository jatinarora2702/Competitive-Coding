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
#define Pn printf("\n");
#define Pr(a) printf("%d ", a);
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

#define N 105
#define M 10005

typedef struct {
	int v, c, pos;
}edge;

typedef struct _node {
	int v, pos;
	lli c;
	bool operator < (const _node& _n) const {
		return c > _n.c;
	}
}node;

vector < edge > g[N];
vi a[M];
priority_queue < node > pq;
map < pair < pii, int >, int > ump;
int n, visit[N], evisit[M];
lli dist[N];

void getspath(int s) {
	while(!pq.empty()) {
		pq.pop();
	}
	rep(i, 0, n) {
		visit[i] = 0;
		dist[i] = LINF;
	}
	dist[s] = 0;
	pq.push({s, -1, 0LL});
	while(!pq.empty()) {
		node n1 = pq.top();
		// error3(n1.v, n1.pos, n1.c);
		pq.pop();
		if(visit[n1.v] == 0) {
			visit[n1.v] = 1;
			if(n1.pos >= 0) {
				// error(n1.pos);
				evisit[n1.pos] = 1;
				vrep(i, a[n1.pos]) {
					evisit[*i] = 1;
				}
			}
			vrep(i, g[n1.v]) {
				if(visit[i->v] == 0 && dist[i->v] > dist[n1.v] + i->c) {
					dist[i->v] = dist[n1.v] + i->c;
					// error(i->pos);
					pq.push({i->v, i->pos, dist[i->v]});
				}
			}
		}
	}
	// rep(i, 0, n) {
	// 	error(dist[i]);
	// }
}

int main() {
	int h, t, m, x, y, z;
	pair < pair < int, int >, int > ptemp;
	S(t);
	h = 0;
	while(t--){
		h++;
		S2(n, m);
		rep(i, 0, n) {
			g[i].clear();
		}
		ump.clear();
		rep(i, 0, m) {
			a[i].clear();
		}
		rep(i, 0, m) {
			evisit[i] = 0;
			S3(x, y, z);
			ptemp = MP(MP(x, y), z);
			if(ump.find(ptemp) != ump.end()) {
				a[ump[ptemp]].PB(i);
				continue;
			}
			ptemp = MP(MP(y, x), z);
			if(ump.find(ptemp) != ump.end()) {
				a[ump[ptemp]].PB(i);
				continue;
			}
			ump[ptemp] = i;
			g[x].PB({y, z, i});
			g[y].PB({x, z, i});
		}
		rep(i, 0, n) {
			getspath(i);
		}
		printf("Case #%d:\n", h);
		rep(i, 0, m) {
			if(evisit[i] == 0)
				P(i);
		}
	}
	return 0;
}