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
	int n, f;
	lli ans, v;
	scanf("%d", &n);
	ans = 1;
	v = (lli)n;
	f = 0;
	for(int i = 0 ; i < 5 ; i++){
		ans *= v;
		if(f == 0 && ans % 120 == 0){
			ans /= (lli)120;
			f = 1;
		}
		v--;
	}
	v = (lli)n;
	for(int i = 0 ; i < 5 ; i++){
		ans *= v;
		if(f == 0 && ans % 120 == 0){
			ans /= (lli)120;
			f = 1;
		}
		v--;
	}
	if(f == 0){
		ans /= (lli)120;
	}
	cout << ans << endl;
	// n1 = (lli)n * (lli)n;
	// ans = n1;
	// val = 2LL * (lli)n - 1LL;
	// for(int i = 0 ; i < 4 ; i++){
	// 	n1 -= val;
	// 	ans *= n1;
	// 	val -= 2LL;
	// }
	// ans /= (lli)120;
	// cout << ans << endl;
	return 0; 
}