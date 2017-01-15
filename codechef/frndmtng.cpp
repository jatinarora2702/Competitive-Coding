#include <iostream>
#include <cstdio>
using namespace std;
typedef long double ld;
typedef long long int lli;
int main(){
	lli t, t1, t2, T1, T2, ans, x1, x2;
	ld ansd;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld%lld%lld%lld", &T1, &T2, &t1, &t2);
		ans = 0;
		x1 = max((lli)0, T1-t2);
		x1 = min(x1, T2);
		if(x1 == T2)
			ans += T2 * (T1-T2-t2);
		// cout << ans << endl;
		x2 = max((lli)0, T2-t1);
		x2 = min(T1, x2);
		if(x2 == T1)
			ans += T1 * (T2-T1-t1);
		// cout << ans << endl;
		ans = (T1 * T2) - ans;
		// cout << ans << endl;
		// cout << x1 << " " << x2 << endl;
		ansd = (ld)ans - (ld)((x1 * x1 + x2 * x2) / 2.0);
		ans = T1 * T2;
		ansd /= (ld)ans;
		printf("%.9Lf\n", ansd);
	}
	return 0;
}