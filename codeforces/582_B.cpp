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

#define N 10000005
#define M 105

int a[M], b[N], dp[N], m, n;
map < int, int > mp;

int getlen() {
	int l, k;
	dp[0] = b[0];
	l = 1;
	rep(i, 1, m) {
		if(b[i] < dp[0]) {
			dp[0] = b[i];
		}
		else if(b[i] >= dp[l-1]) {
			dp[l++] = b[i];
		}
		else {
			k = upper_bound(dp, dp+l, b[i]) - dp;
			dp[k] = b[i];
		}
	}
	return l;
}

int mygetlen() {
	int maxm;
	error(m);
	rep(i, 0, m) {
		maxm = 0;
		rep(j, 0, i) {
			if(b[j] <= b[i] && maxm < dp[j]) {
				maxm = dp[j];
			}
		}
		dp[i] = maxm + 1;
	}
	maxm = 0;
	rep(i, 0, m) {
		maxm = max(maxm, dp[i]);
	}
	return maxm;
}

int getmaxcnt() {
	mp.clear();
	rep(i, 0, n) {
		mp[a[i]]++;
	}
	vrepn(i, mp) {
		return i->SS;
	}
	return 0;
}

int main() {
	int t, k, t1;
	S2(n, t);
	rep(i, 0, n) {
		S(a[i]);
	}
	m = min(n*n, t);
	t1 = t - m;
	k = 0;
	rep(i, 0, m) {
		rep(j, 0, n) {
			b[k++] = a[j];
		}
	}
	m = k;
	int ans = mygetlen();
	error(ans);
	error(t1);
	P(ans + t1 * getmaxcnt());
	return 0;
}