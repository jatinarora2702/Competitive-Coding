#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define N 1000005
using namespace std;

typedef long long int lli;
typedef pair < int, int > pii;
typedef pair < lli, int > pllii;
typedef long double ld;
const int MOD = 1e9 + 7;

ld c[N], d[N], f[N];
int main(){
	int t, n, cnt, j;
	ld a, b, tot, x, xa, xb, ar, ans;
	scanf("%d", &t);
	j = 0;
	while(t--){
		j++;
		scanf("%d%LF%LF", &n, &a, &b);
		for(int i = 0 ; i < n ; i++){
			scanf("%LF", &c[i]);
		}
		tot = 0;
		for(int i = 0 ; i < n ; i++){
			tot += c[i];
			d[i] = tot;
		}
		xa = a - tot * floor(a / tot);
		cout << "xa: " << xa << endl;
		xb = b - tot * floor(b / tot);
		cout << "xb: " << xb << endl;
		cnt = floor((b - a - xa) / tot);
		cout << "cnt: " << cnt << endl;
		ar = xa + xb + ((ld)cnt * tot);
		ar /= (b - a);
		cout << "ar: " << ar << endl;
		f[0] = ar;
		for(int i = 1 ; i < n ; i++){
			f[i] = ar - d[i-1];
		}
		ans = 0;
		for(int i = 0 ; i < n ; i++){
			x = (f[i] * c[i]) / tot;
			ans += x;
		}
		printf("Case #%d: %.8LF\n", j, ans);
	}
	return 0;
}