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

#define N 50005

int a[30], n, l, q;
char s[N];

int check() {
	int zc = 0;
	rep(i, 0, 26) {
		if(a[i] > 1) {
			return 0;
		}
		else if(a[i] == 0) {
			zc++;
		}
	}
	if(zc == q) {
		return 1;
	}
	else {
		return 0;
	}
}

void form() {
	vi v;
	v.clear();
	rep(i, 0, 26) {
		if(a[i] == 0) {
			v.PB(i);
		}
	}
	int j = 0;
	rep(i, l, l+26) {
		if(s[i] == '?') {
			s[i] = 'A' + v[j];
			j++;
		}
	}
	rep(i, 0, n) {
		if(s[i] == '?') {
			s[i] = 'A';
		}
	}
}

int main() {
	cin >> s;
	rep(i, 0, 26) {
		a[i] = 0;
	}
	n = strlen(s);
	if(n < 26) {
		P(-1);
		return 0;
	}
	q = 0;
	rep(i, 0, 26) {
		if(s[i] == '?') {
			q++;
		}
		else{
			a[s[i]-'A']++;
		}		
	}
	l = 0;
	if(check()) {
		form();
		cout << s << "\n";
		return 0;
	}
	rep(i, 26, n) {
		if(s[l] == '?') {
			q--;
		}
		else {
			a[s[l]-'A']--;
		}
		l++;
		if(s[i] == '?') {
			q++;
		}
		else {
			a[s[i]-'A']++;
		}
		if(check()) {
			form();
			cout << s << "\n";
			return 0;
		}
	}
	P(-1);
	return 0;
}