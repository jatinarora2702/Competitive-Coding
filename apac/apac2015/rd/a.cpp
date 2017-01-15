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

#define N 1000005
#define M 1005
int a[N], dp[N], b[M][M];

void check(int xi, int xj, int s) {
	int ni, nj;
	ni = xi+1;
	nj = xj;
	if(ni >= 0 && ni < s && nj >= 0 && nj < s && b[ni][nj] - b[xi][xj] == 1) {
		a[b[xi][xj]-1] = 1;
		return;
	}
	ni = xi-1;
	nj = xj;
	if(ni >= 0 && ni < s && nj >= 0 && nj < s && b[ni][nj] - b[xi][xj] == 1) {
		a[b[xi][xj]-1] = 1;
		return;
	}
	ni = xi;
	nj = xj+1;
	if(ni >= 0 && ni < s && nj >= 0 && nj < s && b[ni][nj] - b[xi][xj] == 1) {
		a[b[xi][xj]-1] = 1;
		return;
	}
	ni = xi;
	nj = xj-1;
	if(ni >= 0 && ni < s && nj >= 0 && nj < s && b[ni][nj] - b[xi][xj] == 1) {
		a[b[xi][xj]-1] = 1;
		return;
	}
	a[b[xi][xj]-1] = 0;
}

void calc(int x) {
	if(dp[x] == -1) {
		if(a[x] == 1) {
			calc(x+1);
			dp[x] = dp[x+1] + 1;
		}
		else {
			dp[x] = 0;
		}
	}
}

void solve(int n) {
	rep(i, 0, n) {
		dp[i] = -1;
	}
	rep(i, 0, n) {
		if(dp[i] == -1) {
			calc(i);
		}
	}
}

int main() {
	int t, h, s, n, maxm;
	S(t);
	h = 0;
	while(t--) {
		h++;
		S(s);
		n = s * s;
		rep(i, 0, s) {
			rep(j, 0, s) {
				S(b[i][j]);
			}
		}
		rep(i, 0, s) {
			rep(j, 0, s) {
				check(i, j, s);
			}
		}
		solve(n);
		maxm = 0;
		rep(i, 1, n) {
			if(dp[maxm] < dp[i]) {
				maxm = i;
			}
		}
		cout << "Case #" << h << ": " << maxm+1 << " " << dp[maxm]+1 << endl;
	}
	return 0;
}