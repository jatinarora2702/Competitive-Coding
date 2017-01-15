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

umap < string, int > mp;
vi g[N];
int v[N], n;

int dfs_visit(int s, int c) {
	v[s] = c;
	vrep(i, g[s]) {
		if(v[*i] == -1) {
			dfs_visit(*i, c^1);
		}
		else if(v[*i] == c) {
			return 0;
		}
	}
	return 1;
}

int color() {
	int f;
	n = mp.size();
	rep(i, 0, n) {
		v[i] = -1;
	}
	f = 1;
	rep(i, 0, n) {
		if(v[i] == 0) {
			f &= dfs_visit(i, 0);
			if(f == 0)
				return f;
		}
	}
	return f;
}

int main() {
	int t, h, m, k, x, y, ans;
	string s;
	S(t);
	h = 0;
	while(t--) {
		h++;
		S(m);
		getchar();
		k = 0;
		mp.clear();
		rep(i, 0, m) {
			cin >> s;
			if(mp.find(s) == mp.end()) {
				mp[s] = k++;
			}
			x = mp[s];
			cin >> s;
			if(mp.find(s) == mp.end()) {
				mp[s] = k++;
			}
			y = mp[s];
			g[x].PB(y);
			g[y].PB(x);
		}
		vrep(i, g) {
			cout << "i=" << *i << ": ";
			vrep(j, g[*i]) {
				cout << *j << " ";
			}
			cout << endl;
		}
		if(color()) {
			printf("Case #%d: Yes\n", h);
		}
		else {
			printf("Case #%d: No\n", h);
		}
	}
	return 0;
}