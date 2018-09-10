#include <bits/stdc++.h>
#define PB push_back
using namespace std;

typedef vector < int > vi;
typedef long long int lli;

const int N = 15;

vi p, pc;
int a[N];

int getprimes(int n) {
	int i, j;
	p.PB(2);
	for(i = 3 ; i <= n ; i += 2) {
		if (a[i] == 0) {
			p.PB(i);
			for(j = 3*i ; j <= n ; j += 2*i)
				a[j] = 1;
		}
	}
}

int getpowercnt(int n, int m) {
	int p = 0;
	while(n % m == 0) {
		p++;
		n /= m;
	}
	return p;
}

lli getlcm(int n) {
	int i, j;
	lli s;
	getprimes(n);
	for(i = 0 ; i < p.size() ; i++) {
		pc.PB(0);
		for(j = 2 ; j <= n ; j++)
			pc[i] = max(pc[i], getpowercnt(j, p[i]));
	}
	s = 1LL;
	for(i = 0 ; i < pc.size() ; i++) {
		while(pc[i] > 0) {
			s *= (lli)p[i];
			pc[i]--;
		}
	}
	return s;
}

int main() {
	lli n, m;
	m = getlcm(10);
	scanf("%lld", &n);
	printf("%lld\n", n / m);
	return 0;
}