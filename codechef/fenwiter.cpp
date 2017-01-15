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

#define N 100005

int getcnt1(string s) {
	int cnt = 0;
	vrep(i, s) {
		cnt += *i - '0';
	}
	return cnt;
}

int sufcnt1(string s) {
	int cnt = 0;
	vrepn(i, s) {
		if(*i == '0')
			break;
		cnt++;
	}
	return cnt;
}

int main() {
	int t, n, c[3], suf[3], ctot, suftot;
	string l[3];
	S(t);
	while(t--) {
		rep(i, 0, 3) {
			cin >> l[i];
		}
		S(n);
		rep(i, 0, 3) {
			c[i] = getcnt1(l[i]);
			suf[i] = sufcnt1(l[i]);
		}
		ctot = c[0] + n * c[1] + c[2];
		if(suf[2] < l[2].length())
			suftot = suf[2];
		else if(suf[1] < l[1].length()) 
			suftot = suf[2] + suf[1];
		else
			suftot = suf[2] + n * suf[1] + suf[0];
		P(ctot - suftot + 1);
	}
	return 0;
}