#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define M 7005
#define N 60

using namespace std;

typedef long long ll;

int main() {
	int n, y;
	ll x;
	int a[M][N];
	int excludes[M];
	vector < int > g[N];
	vector < pair < int, int > > algos(N);
	vector < int > b;

	for(int i = 0; i < N; i++) {
		algos[i] = MP(0, 0);
	}

	cin >> n;
	for(int i = 0; i < n; i++) {
		excludes[i] = 1;
		for(int j = 0; j < N; j++) {
			a[i][j] = 0;
		}
	}
	for(int i = 0; i < n; i++) {
		cin >> x;
		int j = 0;
		vector < int > links;
		while(x > 0LL) {
			if (x % 2LL == 1LL) {
				links.PB(j);
				a[i][j] = 1;
				algos[j].FF += (i+1);
				algos[j].SS += 1;
			}
			x /= 2LL;
			j++;
		}
		for(j = 0; j < links.size(); j++) {
			for(int k = j+1; k < links.size(); k++) {
				g[j].PB(k);
				g[k].PB(j);
			}
		}
	}

	for(int i = 0; i < n; i++) {
		cin >> y;
		b.PB(y);
	}

	while(true) {
		int f = 1;
		while(f == 1) {
			f = 0;
			for(int i = 0; i < N; i++) {
				if (algos[i].SS == 1) {
					f = 1;
					int k = algos[i].FF;
					excludes[k-1] = 0;
					algos[i].FF = 0;
					algos[i].SS = 0;
					for(int j = 0; j < g[i].size(); j++) {
						algos[g[i][j]].FF -= k;
						algos[g[i][j]].SS -= 1;
					}
				}
			}
		}
		int index, cnt;
		index = -1;
		cnt = 0;
		for(int i = 0; i < n; i++) {
			if (excludes[i] == 1) {
				int t = 1;
				for(int j = 0; j < N; j++) {
					if (algos[j].SS > 0 && a[i][j] == 0) {
						t = 0;
						break;
					}
				}
				if (t == 1) {
					cnt++;
					if (cnt == 1) {
						index = i;
					}
				}
			}
		}
		if (cnt == 1) {
			excludes[index] = 0;
			for(int i = 0; i < N; i++) {
				if (algos[i].SS > 0) {
					algos[i].FF -= (index+1);
					algos[i].SS -= 1;
				}
			}
			continue;
		}
		break;
	}
	ll s = 0LL;
	int takencnt = 0;
	for(int i = 0; i < n; i++) {
		s += (ll)b[i] * (ll)excludes[i];
		if (excludes[i] == 1) {
			takencnt++;
		}
	}
	if (takencnt <= 1) {
		s = 0LL;
	}
	cout << s << "\n";
	return 0;
}