#include <bits/stdc++.h>
#define N 200005
using namespace std;

typedef long long ll;

// incorrect solution

int a[N], b[N], c[N];
pair < int, int > p[N];
vector < int > v[N];
int n, k;

void populate(int pos, int s) {
	v[pos].clear();
	int m = a[s];
	vector < int > tmp;
	while(m > 0) {
		tmp.push_back(m % 2);
		m /= 2;
	}
	for(int i = tmp.size()-1; i >= 0; i--) {
		v[pos].push_back(tmp[i] == 0 ? -1 : tmp[i]);
	}
}

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a+n, greater< int >());

	for(int i = 0; i < n; i++) {
		populate(i, i);
	}
	int ms = v[0].size();
	for(int i = 0; i < n; i++) {
		for(int j = v[i].size(); j < ms; j++) {
			v[i].push_back(0);
			a[i] *= 2;
		}
	}

	for(int i = 0; i < n; i++) {
		p[i] = make_pair(a[i], i);
	}
	sort(p, p+n, greater< pair<int, int> >());

	for(int i = 0; i < n; i++) {
		cout << p[i].first << " " << p[i].second << ", ";
	}
	cout << endl;

	// for(int i = 0; i < n; i++) {
	// 	cout << a[i] << " ";
	// }
	// cout << endl;
	// for(int i = 0; i < k; i++) {
	// 	populate(i, i);
	// }
	// ms = v[0].size();
	for(int j = 0; j < ms; j++) {
		b[j] = 0;
		c[j] = k;
	}
	for(int i = 0; i < k; i++) {
		for(int j = 0; j < ms; j++) {
			if (v[p[i].second][j] == 0) {
				c[j]--;
			}
			// v[i].push_back(0);
		}
	}
	// for(int i = 0; i < k; i++) {
	// 	for(int j = 0; j < ms; j++) {
	// 		cout << (v[i][j] == -1 ? '0' : (v[i][j] == 0 ? 'x' : ((char)('0' + v[i][j]))));
	// 	}
	// 	cout << "\n";
	// }
	for(int i = 0; i < k; i++) {
		for(int j = 0; j < ms; j++) {
			b[j] += v[p[i].second][j];
		}
	}
	int r = ms;
	for(int j = 0; j < ms; j++) {
		if (b[j] != -k && b[j] != k) {
			r = j;
			break;
		}
	}
	ll minans = 0LL;
	for(int j = r; j < ms; j++) {
		minans += c[j];
	}
	// cout << "b: ";
	// for(int j = 0; j < ms; j++) {
	// 	cout << b[j] << " ";
	// }
	// cout << "\n";
	// cout << "c: ";
	// for(int j = 0; j < ms; j++) {
	// 	cout << c[j] << " ";
	// }
	// cout << "\n";
	cout << "minm=" << minans << "\n";
	for(int i = k; i < n; i++) {
		int l = i-k;
		for(int j = 0; j < ms; j++) {
			b[j] -= v[p[l].second][j];
			c[j] += (v[p[l].second][j] == 0 ? 1 : 0);
		}
		// populate(l, i);
		for(int j = 0; j < ms; j++) {
			// v[p[i].second].push_back(0);
			if (v[p[i].second][j] == 0) {
				c[j]--;
			}
		}
		for(int j = 0; j < ms; j++) {
			b[j] += v[p[i].second][j];
		}
		r = ms;
		for(int j = 0; j < ms; j++) {
			if (b[j] != -k && b[j] != k) {
				r = j;
				break;
			}
		}
		ll ans = 0LL;
		for(int j = r; j < ms; j++) {
			ans += c[j];
		}
		minans = min(minans, ans);
		// for(int j = 0; j < ms; j++) {
		// 	cout << (v[l][j] == -1 ? '0' : (v[l][j] == 0 ? 'x' : ((char)('0' + v[l][j]))));
		// }
		// cout << "\n";
		// cout << "b: ";
		// for(int j = 0; j < ms; j++) {
		// 	cout << b[j] << " ";
		// }
		// cout << "\n";
		// cout << "c: ";
		// for(int j = 0; j < ms; j++) {
		// 	cout << c[j] << " ";
		// }
		// cout << "\n";
		// cout << "minm=" << minans << "\n";
	}
	cout << minans << "\n";
	return 0;
}