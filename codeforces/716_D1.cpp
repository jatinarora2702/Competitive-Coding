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

#define N 1005
#define M 10005

typedef struct _qnode {
	int u, ei, d;
	bool operator < (const struct _qnode &q) const {
		return d > q.d;
	}
} qnode;

int n, m, dist[N], visited[N], marked[M];
vector < pair < pii, int > > g[N];
pair < pii, int > edge[M];
vi path;
priority_queue < qnode > pq;

int getpath(int s, int t) {
	qnode q;
	path.clear();
	while(!pq.empty()) {
		pq.pop();
	}
	rep(i, 0, n) {
		dist[i] = INF;
		visited[i] = 0;
	}
	pq.push({s, -1, 0});
	dist[s] = 0;
	while(!pq.empty()) {
		q = pq.top();
		pq.pop();
		if(visited[q.u] == 0) {
			if(q.ei >= 0)
				path.PB(q.ei);
			visited[q.u] = 1;
			vrep(i, g[q.u]) {
				if(visited[i->FF.FF] == 0 && dist[i->FF.FF] > dist[q.u] + i->FF.SS) {
					dist[i->FF.FF] = dist[q.u] + i->FF.SS;
					pq.push({i->FF.FF, i->SS, dist[i->FF.FF]});
				}
			}
		}
	}
	return dist[t];
}

int main() {
	int l, s, t, j, len, f, x, y, z, k;
	S2(n, m);
	S3(l, s, t);
	rep(i, 0, m) {
		marked[i] = 0;
	}
	rep(i, 0, m) {
		S3(x, y, z);
		if(z == 0) {
			marked[i] = 1;
			z = 1;
		}
		g[x].PB(MP(MP(y, z), i));
		g[y].PB(MP(MP(x, z), i));
		edge[i] = MP(MP(x, y), z);
	}
	len = getpath(s, t);
	// error(len);
	if(len > l) {
		printf("NO\n");
		return 0;
	}
	f = 0;
	vrep(i, path) {
		if(marked[*i] == 1) {
			edge[*i].SS += (l-len);
			f = 1;
			break;
		}
	}
	if(f == 0 && len != l) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	rep(i, 0, m) {
		printf("%d %d %d\n", edge[i].FF.FF, edge[i].FF.SS, edge[i].SS);
	}
	return 0;
}