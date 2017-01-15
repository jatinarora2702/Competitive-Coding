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

#define N 3005
int a[N][N], dp[N][N];
int n, m;

int getval(int xi, int xj) {
	if(xi >= 0 && xi < n && xj >= 0 && xj < m) {
		return dp[xi][xj];
	}
	return 0;
}

int main() {
	int t, k, h, xi, xj;
	lli ans;
	S(t);
	h = 0;
	while(t--) {
		h++;
		S3(n, m, k);
		rep(i, 0, n) {
			rep(j, 0, m) {
				a[i][j] = 0;
			}
		}
		rep(i, 0, k) {
			S2(xi, xj);
			a[xi][xj] = 1;
		}
		ans = 0LL;
		repn(i, n-1, 0) {
			repn(j, m-1, 0) {
				if(a[i][j] == 0) {
					dp[i][j] = min(getval(i+1, j), getval(i, j+1));
					dp[i][j] = min(dp[i][j], getval(i+1, j+1));
					dp[i][j]++;
					ans += dp[i][j];
				}
				else {
					dp[i][j] = 0;
				}
			}
		}
		cout << "Case #" << h << ": " << ans << endl;
	}
	return 0;
}