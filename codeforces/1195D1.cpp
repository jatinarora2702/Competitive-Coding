#include <bits/stdc++.h>
#define N 100005
#define M 25

using namespace std;

typedef long long lli;

const int MOD = 998244353;

int n, a[N], b[N][M], c[M], d[M], cs[M];

void readinp() {
	int i;
	cin >> n;
	for(i = 0; i < n; i++) {
		cin >> a[i];
	}
}

void parsenum(int num, int index) {
	int i, r;
	i = 0;
	while(num > 0) {
		r = num % 10;
		b[index][i] = r;
		c[i] = (c[i] + r) % MOD;
		d[i]++;
		num /= 10;
		i++;
	}
}

void init() {
	int i, j;
	for(i = 0; i < M; i++) {
		c[i] = 0;
		d[i] = 0;
		for(j = 0; j < n; j++) {
			b[j][i] = 0;
		}
	}
}

void preprocess() {
	int i;
	lli s;
	init();
	s = 0LL;
	for(i = 0; i < n; i++) {
		parsenum(a[i], i);
		s += a[i];
	}
	i = 0;
	while(s > 0LL) {
		cs[i] = s % MOD;
		s -= c[i];
		s /= 10LL;
		i++;
	}
}

int calc() {
	int i;
	lli s;
	s = 0LL;
	for(i = M-1; i >= 0; i--) {
		s = (s * 10) % MOD;
		s = (s + ((lli)d[i] * c[i])) % MOD;
		s = (s * 10) % MOD;
		s = (s + ((lli)d[i] * c[i])) % MOD;
		if (i > 0) {
			s = (s + (2LL * (d[i-1] - d[i]) * cs[i])) % MOD;
		}
	}
	return (int)s;
}

int main() {
	readinp();
	preprocess();
	cout << calc() << "\n";
	return 0;
}