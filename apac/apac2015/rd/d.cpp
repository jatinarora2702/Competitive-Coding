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

#define N 8

char a[N][N];
int ans;

void decode(string s) {
	int i, j;
	i = s[0] - 'A';
	j = s[1] - '1';
	a[i][j] = s[3];
}

int isvalid(int xi, int xj, int& f) {
	if(xi >= 0 && xi < N && xj >= 0 && xj < N && a[xi][xj] != '.' && f == 1) {
		f = 0;
		return 1;
	}
	return 0;
}

void move(int xi, int xj, char s) {
	int ni, nj, fm[N];
	rep(i, 0, N) {
		fm[i] = 1;
	}
	switch(s) {
		case 'K':
			ans += isvalid(xi+1, xj+1, fm[0]);
			ans += isvalid(xi+1, xj, fm[1]);
			ans += isvalid(xi+1, xj-1, fm[2]);
			ans += isvalid(xi, xj+1, fm[3]);
			ans += isvalid(xi, xj-1, fm[4]);
			ans += isvalid(xi-1, xj+1, fm[5]);
			ans += isvalid(xi-1, xj, fm[6]);
			ans += isvalid(xi-1, xj-1, fm[7]);
			break;
		case 'Q':
			rep(i, 1, N+1) {
				ans += isvalid(xi+i, xj+i, fm[0]);
				ans += isvalid(xi+i, xj, fm[1]);
				ans += isvalid(xi+i, xj-i, fm[2]);
				ans += isvalid(xi, xj+i, fm[3]);
				ans += isvalid(xi, xj-i, fm[4]);
				ans += isvalid(xi-i, xj+i, fm[5]);
				ans += isvalid(xi-i, xj, fm[6]);
				ans += isvalid(xi-i, xj-i, fm[7]);
			}
			break;
		case 'R':
			rep(i, 1, N+1) {
				ans += isvalid(xi+i, xj, fm[1]);
				ans += isvalid(xi, xj+i, fm[3]);
				ans += isvalid(xi, xj-i, fm[4]);
				ans += isvalid(xi-i, xj, fm[6]);
			}
			break;
		case 'B':
			rep(i, 1, N+1) {
				ans += isvalid(xi+i, xj+i, fm[0]);
				ans += isvalid(xi+i, xj-i, fm[2]);
				ans += isvalid(xi-i, xj+i, fm[5]);
				ans += isvalid(xi-i, xj-i, fm[7]);
			}
			break;
		case 'P':
			ans += isvalid(xi+1, xj+1, fm[0]);
			ans += isvalid(xi+1, xj-1, fm[2]);
			break;
		case 'N':
			ans += isvalid(xi+1, xj+2, fm[0]);
			ans += isvalid(xi+1, xj-2, fm[1]);
			ans += isvalid(xi-1, xj+2, fm[2]);
			ans += isvalid(xi-1, xj-2, fm[3]);
			ans += isvalid(xi+2, xj-1, fm[4]);
			ans += isvalid(xi+2, xj+1, fm[5]);
			ans += isvalid(xi-2, xj-1, fm[6]);
			ans += isvalid(xi-2, xj+1, fm[7]);
			break;
	}
}

void calc() {
	ans = 0;
	rep(i, 0, N) {
		rep(j, 0, N) {
			if(a[i][j] != '.') {
				move(i, j, a[i][j]);
				// error4(i, j, a[i][j], ans);
			}
		}
	}
}

int main() {
	int t, h, n;
	string s;
	S(t);
	h = 0;
	while(t--) {
		h++;
		S(n);
		rep(i, 0, N) {
			rep(j, 0, N) {
				a[i][j] = '.';
			}
		}
		rep(i, 0, n) {
			cin >> s;
			decode(s);
		}
		calc();
		cout << "Case #" << h << ": " << ans << endl;
	}
	return 0;
}