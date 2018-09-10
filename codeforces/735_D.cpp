#include <bits/stdc++.h>
#define PB push_back
#define S(n) scanf("%d", &n)
#define P(n) printf("%d\n", n)

using namespace std;

typedef vector < int > vi;

const int N = 100005;
const int M = 10005;

vi p;
int a[N], n;

void getprimes() {
	int i, j, m;
	m = min(n + 1, N);
	p.PB(2);
	for(i = 3 ; i < m ; i += 2) {
		if (a[i] == 0) {
			p.PB(i);
			for(j = i * 2 ; j < m ; j += i)
				a[j] = 1;
		}
	}
}

int maxprime() {
	int i, m;
	if (n < N) {
		m = (upper_bound(p.begin(), p.end(), n) - p.begin()) - 1;
		return n == p[m] ? p[m] : (n - p[m] > 1 ? p[m] : p[m-1]);
	}
	for(i = 0 ; i <= M ; i++)
		a[i] = 0;
	for(i = 0 ; i < p.size() ; i++) {
		m = M - (n % p[i]);
		while(m >= 0) {
			a[m] = 1;
			m -= p[i];
		}
	}
	if (a[M] == 0)
		return n;
	for(i = M-2 ; i >= 0 ; i--) {
		if (a[i] == 0) {
			return n - (M - i);
		}
	}
}

int main() {
	int s;
	S(n);
	if (n % 2 == 0 && n > 2) {
		P(2);
		return 0;
	}
	getprimes();
	s = 0;
	while(n > 0) {
		n -= maxprime();
		s++;
	}
	P(s);
	return 0;
}