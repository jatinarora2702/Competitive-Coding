#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define N 105
#define M 100000

using namespace std;

typedef long long int lli;
typedef long double ld;

int a[N], n;

ld eval(ld x) {
	int i;
	ld ans;
	ans = -(ld)a[0];
	for(i = 1 ; i <= n ; i++) {
		ans = (ans * x) + (ld)a[i];
	}
	return ans;
}

ld deval(ld x) {
	int i;
	ld ans;
	lli temp;
	temp = -a[0] * 1LL * n;
	ans = (ld)temp;
	for(i = 1 ; i < n ; i++) {
		temp = a[i] * 1LL * (n-i);
		ans = (ans * x) + (ld)temp;
	}
	return ans;
}

ld getx(ld s) {
	int i;
	ld x, tempd, temp, xprev;
	x = s;
	for(i = 0 ; i < M ; i++) {
		temp = eval(x);
		tempd = deval(x);
		xprev = x;
		x = x - temp / tempd;
		if(fabs(x-xprev) < 0.00000000000001L)
			break;
	}
	return x;
}

int main() {
	int t, i, h, f;
	ld ans, x;
	scanf("%d", &t);
	h = 0;
	while(t--) {
		cout.precision(12);
		h++;
		scanf("%d", &n);
		for(i = 0 ; i <= n ; i++) {
			scanf("%d", &a[i]);
		}
		f = 0;
		x = -1.0L;
		for(i = 0 ; i < 410 ; i++) {
			ans = getx(x);
			if((ans-0) > 0.0000000001 && ans < 2) {
				// cout << "ans:" << ans << endl;
				f = 1;
				break;
			}
			x += 0.01L;
		}
		if(f == 1) {
			cout << "Case #" << h << ": " << fixed << ans-1.0 << /*" " << a[n] << */endl;
		}
	}
	return 0;
}