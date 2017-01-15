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
	int t, k, j, jj, cnt, n;
	ld tot, totsq, a, b, xa, xb, y, ans, l;
	scanf("%d", &t);
	jj = 0;
	while(t--){
		jj++;
		ans = 0;
		scanf("%d%LF%LF", &n, &a, &b);
		for(int i = 0 ; i < n ; i++){
			scanf("%LF", &c[i]);
		}
		tot = 0;
		totsq = 0;
		for(int i = 0 ; i < n ; i++){
			tot += c[i];
			totsq += c[i] * c[i];
			d[i] = tot;
			f[i] = totsq;
		}
		xa = a - tot * floor(a / tot);
		xb = b - tot * floor(b / tot);
		j = upper_bound(d, d+n, xa) - d;
		k = upper_bound(d, d+n, xb) - d;
		j--;
		k--;
		l = b - a;
		if(j < n-1 && l < d[j+1] - xa){
			ans = (xb - xa) * (xb - xa);
		}
		else{
			if(j < n-1){
				ans += (d[j+1] - xa) * (d[j+1] - xa);
				l -= (d[j+1] - xa);
				xb -= d[k];
				y = f[k] + (xb * xb);
				if(l < d[n-1] - d[j+1]){
					ans += (y - f[j+1]);
					ans /= (b-a);
					printf("Case #%d: %LF\n", jj, ans);
					continue;
				}
				else{
					ans += (f[n-1] - f[j+1]);
					l -= (d[n-1] - d[j+1]);
				}
			}
			cnt = l / d[n-1];
			l -= (cnt * d[n-1]);
			ans += (cnt * f[n-1]);
			if(l > 0)
				ans += y;
		}
		ans /= (b-a);
		printf("Case #%d: %LF\n", jj, ans);
	}
	return 0;
}