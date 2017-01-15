#include <bits/stdc++.h>
#define N 1005
using namespace std;
typedef long long int lli;
char a[N];
int main() {
	int n, i, f, k;
	lli p, m;
	scanf("%d", &n);
	for(i = 0 ; i < 20 ; i++) {
		scanf("%s", a+(50*i));
	}
	f = 0;
	m = 0LL;
	p = 1LL;
	for(i = 0 ; i < n ; i++) {
		k = a[i] - '0';
		if(k == 0) {
			f++;
		}
		else {
			p *= (lli)k;
		}
	}
	m = max(m, (f == 0) ? p : 0LL);
	for(i = n ; a[i] != '\0' ; i++) {
		k = a[i-n] - '0';
		if(k == 0)
			f--;
		else
			p /= (lli)k;
		k = a[i] - '0';
		if(k == 0)
			f++;
		else
			p *= (lli)k;
		m = max(m, (f == 0) ? p : 0LL);
	}
	cout << m << "\n";
	return 0;
}