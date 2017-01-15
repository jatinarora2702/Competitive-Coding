#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long int lli;
typedef long double ld;
const int MOD = 1e9+7;
const int ONF = 1e9+7;

int main(){
	double ans;
	int l, d, v1, v2;
	scanf("%d%d%d%d", &d, &l, &v1, &v2);
	l = l - d;
	ans = l / (1.0 * (v1 + v2));
	printf("%lf\n", ans);
	return 0;
}