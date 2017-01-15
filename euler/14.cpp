#include <bits/stdc++.h>
#define N 50000000
using namespace std;
typedef long long int lli;
int a[N];

int numterms(lli n) {
	int m;
	if(n >= (lli)N) {
		if(n % 2LL == 0)
			m = numterms(n/2LL)+1;
		else
			m = numterms((lli)3*n+1LL)+1;
		return m;
	}
	if(a[n] == 0) {
		if(n % 2LL == 0)
			a[n] = numterms(n/2LL)+1;
		else
			a[n] = numterms((lli)3*n+1LL)+1;
	}
	return a[n];
}

int main() {
	int n, k;
	lli i, m;
	a[1] = 1;
	m = 1LL;
	scanf("%d", &n);
	for(i = 2LL ; i < (lli)n ; i++) {
		k = numterms(i);
		if(k > a[m]) {
			m = i;
		}
	}
	printf("%lld\n", m);
	return 0;
}