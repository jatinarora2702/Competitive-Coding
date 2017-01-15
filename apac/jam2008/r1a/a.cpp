#include <bits/stdc++.h>
#define N 805 
using namespace std;
typedef long long int lli;

int a[N], b[N];
int main() {
	int t, n, i, h;
	lli s;
	scanf("%d", &t);
	h = 0;
	while(t--) {
		h++;
		scanf("%d", &n);
		for(i = 0 ; i < n ; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a+n);
		for(i = 0 ; i < n ; i++) {
			scanf("%d", &b[i]);
		}
		sort(b, b+n);
		s = 0LL;
		for(i = 0 ; i < n ; i++) {
			s += (lli)a[i] * (lli)b[n-i-1];
		}
		cout << "Case #" << h << ": " << s << "\n";
	}
	return 0;
}