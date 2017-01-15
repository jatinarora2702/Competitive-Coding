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
#define M 1005


int a[N][N], n, m;
int d[] = {-1, 0, 1};
char b[N][N];

void getadj(int xi, int xj) {
	int cnt, ni, nj;
	if(b[xi][xj] == '*') {
		a[xi][xj] = -1;
		return;
	}
	cnt = 0;
	rep(i, 0, 3) {
		ni = xi + d[i];
		if(ni >= 0 && ni < n) {
			rep(j, 0, 3) {
				nj = xj + d[j];
				if(nj >= 0 && nj < m && b[ni][nj] == '*')
					cnt++;
			}
		}
	}
	a[xi][xj] = cnt;
}

int main() {
	boost;
	int k;
	k = 0;
	while(1) {
		cin >> n >> m;
		if(n == 0 && m == 0)
			break;
		rep(i, 0, n) {
			cin >> b[i];
		}
		rep(i, 0, n) {
			rep(j, 0, m) {
				getadj(i, j);
			}
		}
		cout << "Field #" << k++ << ":" << endl;
		rep(i, 0, n) {
			rep(j, 0, m) {
				if(a[i][j] == -1)
					cout << "*";
				else
					cout << a[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}