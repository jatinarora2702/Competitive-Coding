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

vi g[N];
stack < pii > stk;
vector < vi > vcomp;
int n, m, visit[N], minreach[N], parent[N], isart[N], gbcnt, last_art;

void dfs_visit(int s, int ps) {
	int cnt;
	visit[s] = gbcnt++;
	parent[s] = ps;
	minreach[s] = visit[s];
	cnt = 0;
	isart[s] = 0;
	vrep(i, g[s]) {
		if(visit[*i] == 0) {
			cnt++;
			dfs_visit(*i, s);
			minreach[s] = min(minreach[s], minreach[*i]);
			if(ps != -1 && minreach[*i] >= visit[s])
				isart[s] = 1;
			else if(ps == 1 && cnt >= 2)
				isart[s] = 1;
		}
		else if(*i != ps) {
			minreach[s] = min(minreach[s], visit[*i]);
		}
	}
}

void getartpts() {
	gbcnt = 1;
	rep(i, 0, n) {
		visit[i] = 0;
		isart[i] = 0;
	}
	rep(i, 0, n) {
		if(visit[i] == 0) {
			dfs_visit(i, -1);
		}
	}
	rep(i, 0, n) {
		error2(visit[i], minreach[i]);
	}
}

void dfs_visit1(int s) {
	pii pr;
	visit[s] = 1;
	vrep(i, g[s]) {
		stk.push(MP(s, *i));
		if(visit[*i] == 0) {
			dfs_visit1(*i);
			if(isart[s]) {
				while(1) {
					pr = stk.top();
					stk.pop();
					errorp(pr);
					if(pr.FF == s || pr.SS == *i) {
						errorp(MP(s, *i));
						break;
					}
				}
				cout << "-----------------" << endl;
			}
		}
	}
}

void getbicons() {
	rep(i, 0, n) { 
		visit[i] = 0;
	}
	rep(i, 0, n) {
		if(visit[i] == 0) {
			dfs_visit1(i);
		}
	}
}

int main() {
	int x, y;
	S2(n, m);
	rep(i, 0, m) {
		S2(x, y);
		g[x].PB(y);
		g[y].PB(x);
	}
	getartpts();
	rep(i, 0, n) {
		error(isart[i]);
	}
	getbicons();
	vrep(i, vcomp) {
		vrep(j, *i) {
			Pr(*j);
		}
		Pn;
	}
	return 0;
}