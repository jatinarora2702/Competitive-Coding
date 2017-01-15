#include <bits/stdc++.h>
#define PB push_back
#define FF first
#define SS second
#define MP make_pair
#define N 1000
using namespace std;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9+7;
const int MOD = 1e9+7;

int main(){
	int a, b, c;
	ld t, ans1, ans2;
	scanf("%d%d%d", &a, &b, &c);
	if(a == 0){
		ans1 = (ld)(-c) / (ld)(b);
		cout.precision(10);
		cout << fixed << ans1 << endl << fixed << ans1 << endl;
		return 0;
	}
	int mid = (b*b) - (4*a*c);
	t = sqrt(mid);
	ans1 = (-(ld)b + t) / (ld)(2*a);
	ans2 = (-(ld)b - t) / (ld)(2*a);
	cout.precision(10);
	cout << fixed << ans1 << endl << fixed << ans2 << endl;
	return 0;
}