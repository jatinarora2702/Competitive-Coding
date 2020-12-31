#include <bits/stdc++.h>
#define N 200005
using namespace std;

vector<int> v(3, 0);
char a[] = {'R', 'G', 'B'};

int main() {
	int q, n, k, i, j, tmp, m;
	string s;
	cin >> q;
	while(q--) {
		cin >> n >> k >> s;
		for(j = 0; j < 3; j++) {
			v[j] = 0;
		}
		for(i = 0; i < k; i++) {
			for(j = 0; j < 3; j++) {
				v[j] += (s[i] == a[(i+j)%3]) ? 0 : 1;
			}
		}
		m = k + 1;
		for(j = 0; j < 3; j++) {
			m = min(m, v[j]);
		}
		for(i = k; i < n; i++) {
			for(j = 0; j < 3; j++) {
				v[j] -= (s[i-k] == a[j%3]) ? 0 : 1;
			}
			tmp = v[2];
			v[2] = v[1];
			v[1] = v[0];
			v[0] = tmp;

			for(j = 0; j < 3; j++) {
				v[j] += (s[i] == a[(k-1+j)%3]) ? 0 : 1;
			}
			for(j = 0; j < 3; j++) {
				m = min(m, v[j]);
			}
		}
		cout << m << "\n";
	}
	return 0;
}