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

#define N 1000005

int reduce(int a, int b, int c, int goal, int k) {
	error3(a, b, c);
	int maxm, temp, minm, i;
	maxm = max(a, b);
	maxm = max(maxm, c);
	switch(k) {
		case 1: 
			temp = ((a + b + c)/3) - goal;
			temp /= 3;
			temp++;
			break;
		case 2: 
			temp = ((a + b + c)/3) - goal;
			temp /= 3;
			break;
		case 3: 
			temp = ((a + b + c)/3) - goal;
			temp /= 2;
			temp++;
			break;
		case 4: 
			temp = ((a + b + c)/3) - goal;
			temp /= 2;
			break;
		case 5: 
			temp = maxm - goal;
			temp /= 3;
			temp++;
			break;
		case 6: 
			temp = maxm - goal;
			temp /= 3;
			break;
		case 7: 
			temp = maxm - goal;
			temp /= 2;
			temp++;
			break;
		case 8: 
			temp = maxm - goal;
			temp /= 2;
			break;
	}
	temp = max(temp, goal);
	if(maxm == goal)
		return 0;
	if(maxm == a) {
		temp = max(temp, abs(b-c) + 1);
		a = max(goal, temp);
	}
	else if(maxm == b) {
		temp = max(temp, abs(a-c) + 1);
		b = max(goal, temp);
	}
	else if(maxm == c) {
		temp = max(temp, abs(b-a) + 1);
		c = max(goal, temp);
	}
	minm = INF;
	for(i = 1 ; i <= 8 ; i++) {
		minm = min(minm, reduce(a, b, c, goal, i));
	}
	return minm + 1;
}

int main() {
	int x, y, a, b, c, d, i, minm;
	S2(x, y);
	minm = INF;
	for(i = 1 ; i <= 8 ; i++) {
		a = b = c = x;
		minm = min(minm, reduce(a, b, c, y, i));
	}
	printf("%d\n", minm);
	return 0;
}