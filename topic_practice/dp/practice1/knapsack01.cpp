#include <bits/stdc++.h>
#define FF first
#define SS second
#define pb push_back
#define mp make_pair

#define rep(i, a, n) for(int i = (a) ; i < (n) ; ++i)
#define repr(i, a, n) for(int i = (a) ; i >= (n) ; --i)
#define sci(a) scanf("%d", &(a))
#define sci2(a, b) scanf("%d%d", &(a), &(b))
#define sci3(a, b, c) scanf("%d%d%d", &(a), &(b), &(c))
#define scf(a) scanf("%f", &(a))
#define scf2(a, b) scanf("%f%f", &(a), &(b))
#define scf3(a, b, c) scanf("%f%f%f", &(a), &(b), &(c))
#define scl(a) scanf("%lld", &(a))
#define scl2(a, b) scanf("%lld%lld", &(a), &(b))
#define scl3(a, b, c) scanf("%lld%lld%lld", &(a), &(b), &(c))
#define pri(a) printf("%d ", (a))
#define prni(a) printf("%d\n", (a))
#define prf(a) printf("%f ", (a))
#define prnf(a) printf("%f\n", (a))
#define prl(a) printf("%lld ", (a))
#define prnl(a) printf("%lld\n", (a))
#define pr(a) printf((a))

#define N 1000
#define M 10000
using namespace std;
typedef long long int lli;
const int mod = 1e9+7;

int wt[N], v[N], dp[M][N];
int main(){
	int w, n;
	pr("Enter the max. wt. of the sack: ");
	sci(w);
	pr("Enter the no. of comodities: ");
	sci(n);
	pr("Enter the comodity wt. and price:\n");
	rep(i, 0, n)
		sci2(wt[i], v[i]);
	// pr("The values entered are: ");
	// rep(i, 0, n){
	// 	pri(wt[i]);
	// 	prni(v[i]);
	// }
	rep(j, 0, n)
		dp[0][j] = 0;
	rep(i, 0, w+1){
		if(i >= wt[0])
			dp[i][0] = v[0];
		else
			dp[i][0] = 0;
	}
	rep(i, 1, w+1){
		rep(j, 1, n){
			dp[i][j] = dp[i][j-1];
			if(i-wt[j] >= 0)
				dp[i][j] = max(dp[i][j], dp[i-wt[j]][j-1] + v[j]);
		}
	}
	pr("Max. value obtainable is: ");
	prni(dp[w][n-1]);
	return 0;
}