#include <bits/stdc++.h>
#define PB push_back

#define N 100005
#define M 2000005

using namespace std;

typedef long long lli;

int n, a[N];
vector < int > v[M], vc;

void calcxor() {
	int x = 0;
	for(int i = 0; i < n; i++) {
		x ^= a[i];
		if (v[x].size() == 0) {
			vc.PB(x);
		}
		v[x].PB(i);
	}
}

lli count() {
	calcxor();
	lli cnt = 0LL;
	for(int i = 0; i < vc.size(); i++) {
		int k = vc[i];
		int m = v[k].size();
		if (k == 0) {
			for(int j = 0; j < m; j++) {
				cnt += (lli)v[k][j];
			}
		}
		for(int j = 0; j < m-1; j++) {
			int d = v[k][j+1] - v[k][j];
			cnt += (lli)d * (lli)(j+1) * (lli)(m-1-j);
		}
		cnt -= ((lli)m * (lli)(m-1)) / 2LL;
	}
	return cnt;
}

void init() {
	for(int i = 0; i < vc.size(); i++) {
		v[vc[i]].clear();
	}
	vc.clear();
}

void getinp() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		init();
		getinp();
		cout << count() << "\n";
	}
	return 0;
}
