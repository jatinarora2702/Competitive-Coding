#include <bits/stdc++.h>
#define N 100005

using namespace std;

int n, c[N], h[N], r[N], hc[N], rc[N];

void getinp() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> h[i];
	}
}

void init() {
	for(int i = 0; i <= n; i++) {
		r[i] = 0;
		rc[i] = 0;
		hc[i] = 0;
	}
}

void calcrad() {
	int s;
	for(int i = 0; i < n; i++) {
		int k = max(i - c[i], 0);
		r[k]++;
		if (i + c[i] + 1 < n) {
			r[i + c[i] + 1]--;
		}
	}
	s = 0;
	for(int i = 0; i < n; i++) {
		s += r[i];
		r[i] = s;
	}
}

bool isValid() {
	for(int i = 0; i < n; i++) {
		if(h[i] > n) {
			return false;
		}
		hc[h[i]]++;
	}
	for(int i = 0; i < n; i++) {
		rc[r[i]]++;
	}
	for(int i = 0; i <= n; i++) {
		if (hc[i] != rc[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		getinp();
		init();
		calcrad();
		cout << (isValid() ? "YES\n" : "NO\n");
	}
}