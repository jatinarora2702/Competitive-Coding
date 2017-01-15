#include <bits/stdc++.h>
#define N 100005
using namespace std;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9+1;
ld a[N];
int l[N], r[N];
vector < int > v;
int main(){
	int n, p, x1, x2, x;
	// lli k;
	ld ans;
	scanf("%d%d", &n, &p);
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &l[i], &r[i]);
	}
	// k = (lli)p;
	// while(k < INF){
	// 	v.push_back(k);
	// 	k *= (lli)p;
	// }
	for(int i = 0 ; i < n ; i++){
		// x1 = lower_bound(v.begin(), v.end(), l[i]) - v.begin();
		// x2 = upper_bound(v.begin(), v.end(), r[i]) - v.begin();
		x1 = ceil(l[i] / (p * 1.0));
		x2 = floor(r[i] / (p * 1.0));
		x = x2 - x1 + 1;
		// cout << "x;" << x << endl;
		a[i] = x / ((r[i] - l[i] + 1) * 1.0);
	}
	ans = 0;
	for(int i = 0 ; i < n-1 ; i++){
		ans += 2000 * (a[i] + a[i+1] - a[i] * a[i+1]);
	}
	ans += 2000 * (a[n-1] + a[0] - a[n-1] * a[0]);
	cout.precision(15);
	cout << fixed << ans << endl;
	return 0;
}