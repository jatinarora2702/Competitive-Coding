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
lli a[N], dp[N][N], dp1[N];
int n;

void calc() {
	rep(s, 0, n) {
		rep(i, 0, n) {
			if(a[i] < a[s]) {
				dp[s][i] = -INF;
				continue;
			}
			dp[s][i] = 1;
			rep(j, 0, i) {
				if(a[j] <= a[i]) {
					dp[s][i] = max(dp[s][i], dp[s][j] + 1);
				}
			}
		}
	}
}

void matcpy(lli arr[][N], lli temp[][N], int m) {
	rep(i, 0, m) {
		rep(j, 0, m) {
			arr[i][j] = temp[i][j];
		}
	}
}

void matmult(lli arr1[][N], lli arr2[][N], int m) {
	lli arr[N][N];
	rep(i, 0, m) {
		rep(j, 0, m) {
			arr[i][j] = -INF;
			rep(k, 0, m) {
				arr[i][j] = max(arr[i][j], arr1[i][k] + arr2[k][j]);
			}
		}
	}
	matcpy(arr1, arr, m);
}

void matexp(lli arr[][N], int m, int p) {
	lli arr1[N][N];
	// cout << "p=" << p << endl;
	// rep(i, 0, m) {
	// 	rep(j, 0, m) {
	// 		cout << arr[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << "-----------------------------------------\n";
	assert(p >= 0);
	if(p == 0) {
		rep(i, 0, m) {
			rep(j, 0, m) {
				arr[i][j] = 0;
			}
			arr[i][i] = 1;
		}
		return;
	}
	else if(p == 1) {
		return;
	}
	matcpy(arr1, arr, m);
	matmult(arr, arr, m);
	matexp(arr, m, p >> 1);
	if(p % 2 != 0) {
		matmult(arr, arr1, m);
	}
}

lli getmaxm() {
	lli maxm = 0;
	rep(i, 0, n) {
		rep(j, 0, n) {
			maxm = max(maxm, dp[i][j]);
		}
	}
	return maxm;
}

int main() {
	int t;
	S2(n, t);
	rep(i, 0, n) {
		cin >> a[i];
	}	
	calc();
	matexp(dp, n, t);
	cout << getmaxm() << endl;
	return 0;
}