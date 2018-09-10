#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
const lli LINF = 1e18 + 7LL;


int main() {
	int n, i;
	lli ts, tf, t, x, px, d, ansv, anst;
	cin >> ts >> tf >> t >> n;
	
	cin >> x;
	anst = max(0LL, x-1);
	ansv = ts - anst;
	if(x > ts) {
		anst = x-1;
		cout << anst << endl;
		return 0;
	}
	d = t;
	px = x;
	for(i = 1 ; i < n ; i++) {
		cin >> x;
		if(x != px && ansv > d) {
			ansv = max(d, 0LL);
			anst = max(ts, px-1);	
		}
		d = d - (x-px);
		if(d < 0) {
			ansv = 0;
			anst = max(ts, x-1);
		}
		d = max(d, 0LL);
		d += t;
		px = x;
	}
	x = tf-t;
	d = d - (x-px);
	if(ansv > d) {
		ansv = max(d, 0LL);
		anst = max(ts, x);	
	}
	cout << anst << endl;
	return 0;
}