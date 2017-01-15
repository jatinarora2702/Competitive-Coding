#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
	lli f, l1, r1, k, l2, r2, templ, tempr;
	cin >> l1 >> r1 >> l2 >> r2 >> k;
	templ = max(l1, l2);
	tempr = min(r1, r2);
	f = tempr - templ + 1;
	if(f < 0)
		f = 0;
	if(f > 0) {
		if(k >= templ && k <= tempr) {
			f--;
		}
	}
	cout << f << endl;
	return 0;
}