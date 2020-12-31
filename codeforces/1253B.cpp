#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define N 1000005

using namespace std;

typedef long long lli;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;

int a[N];
set < int > st;
vector < int > v;

int main() {
	int n, f, m, x;
	cin >> n;
	f = 1;
	m = 0;
	for(int i = 0; i < n; i++) {
		cin >> x;
		if (f == 0) {
			continue;
		}
		if (x > 0) {
			if (a[x] == 0) {
				if (st.find(x) == st.end()) {
					a[x] = 1;
					st.insert(x);
					m++;
				}
				else {
					f = 0;
				}
			}
			else {
				f = 0;
			}
		}
		else {
			if (a[-x] == 1) {
				a[-x] = 0;
				m--;
				if (m == 0) {
					v.PB(i + 1);
					st.clear();
				}
			}
			else {
				f = 0;
			}
		}
	}
	if (f == 1 && m == 0) {
		cout << v.size() << "\n";
		for(int i = 0; i < v.size(); i++) {
			if (i > 0) {
				cout << v[i] - v[i-1] << " ";
			}
			else {
				cout << v[i] << " ";
			}
		}
		cout << "\n";
	}
	else {
		cout << "-1\n";
	}
	return 0;
}