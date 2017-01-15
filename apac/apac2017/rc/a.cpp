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

#define N 25
char a[N][N];
int r, c;
ld dp[N][N][15], p, q;

ld getval(int xi, int xj, int k) {
	if(xi >= 0 && xi < r && xj >= 0 && xj < c && k > 0) {
		return dp[xi][xj][k];
	}
	return 0.0L;
}

ld getprob(int xi, int xj) {
	if(xi >= 0 && xi < r && xj >= 0 && xj < c) {
		if(a[xi][xj] == 'A') {
			return q;
		}
		else {
			return p;
		}
	}
	return 0.0L;
}

int main() {
	int t, h, rs, cs, s;
	S(t);
	h = 0;
	while(t--) {
		h++;
		S2(r, c);
		S2(rs, cs);
		S(s);
		scanf("%LF%LF", &p, &q);
		rep(i, 0, r) {
			rep(j, 0, c) {
				getchar();
				scanf("%c", &a[i][j]);
				// printf("[%c]", a[i][j]);
			}
		}
		rep(k, 1, s+1) {
			rep(i, 0, r) {
				rep(j, 0, c) {
					dp[i][j][k] = .25 * (getval(i-1, j, k-1) + getprob(i-1, j)); 
					dp[i][j][k] += .25 * (getval(i+1, j, k-1) + getprob(i+1, j)); 
					dp[i][j][k] += .25 * (getval(i, j-1, k-1) + getprob(i, j-1)); 
					dp[i][j][k] += .25 * (getval(i, j+1, k-1) + getprob(i, j+1));
				}
			}
		}
		cout << "Case #" << h << ": ";
		coud(dp[rs][cs][s], 8);
	}
	return 0;
}