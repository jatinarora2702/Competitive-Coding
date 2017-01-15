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

#define N 1005
#define M 15

typedef struct {
	string args[M];
	string var;
	int numargs, val;
}expr;

expr a[N];
int n;
map < string, int > mp;

void printex(expr ex) {
	error(ex.var);
	rep(i, 0, ex.numargs) {
		cout << "[" << ex.args[i] << "] ";
	}
	cout << endl;
	error(ex.val);
}

int eval(expr ex) {
	int ans;
	ans = 0;
	rep(i, 0, ex.numargs) {
		if(mp[ex.args[i]] == 0) {
			ans += 100000;
		}
	}
	return ans;
}

void update(int m) {
	rep(i, m, n) {
		a[i].val = eval(a[i]);
	}
}

bool cmp(expr a, expr b) {
	return a.val < b.val;
}

int isvalid() {
	int m, i;
	m = 0;
	while(m < n) {
		update(m);
		sort(a+m, a+n, cmp);
		i = m;
		while(i < n && a[i].val == 0) {
			mp[a[i].var] = 1;
			i++;
		}
		if(i == m) {
			return 0;
		}
		m = i;
	}
	return 1;
}

void parse(string s, int m) {
	int k, k1;
	k = s.find("=");
	a[m].var = s.substr(0, k);
	mp[a[m].var] = 0;
	k = s.find("(");
	a[m].numargs = 0;
	while(1) {
		k1 = s.find(",", k+1);
		if(k1 == string::npos) {
			if(s[k+1] != ')') {
				a[m].args[a[m].numargs] = s.substr(k+1, s.length()-k-2);
				mp[a[m].args[a[m].numargs]] = 0;
				(a[m].numargs)++;
			}
			break;
		}
		a[m].args[a[m].numargs] = s.substr(k+1, k1-k-1);
		mp[a[m].args[a[m].numargs]] = 0;
		k = k1;
		(a[m].numargs)++;
	}
}

int main() {
	int t, h;
	string ex;
	S(t);
	h = 0;
	while(t--) {
		h++;
		S(n);
		mp.clear();
		rep(i, 0, n) {
			cin >> ex;
			parse(ex, i);
			// printex(a[i]);
		}
		printf("Case #%d: ", h);
		if(isvalid()) {
			printf("GOOD\n");
		}
		else {
			printf("BAD\n");
		}
	}
}