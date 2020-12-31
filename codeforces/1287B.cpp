#include <bits/stdc++.h>
using namespace std;

vector<string> v;

int main() {
	int n, k, cnt;
	string s;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	cnt = 0;
	for(int i1 = 0; i1 < n; i1++) {
		for(int i2 = i1+1; i2 < n; i2++) {
			s = "";
			for(int j = 0; j < k; j++) {
				if (v[i1][j] == v[i2][j]) {
					s.push_back(v[i1][j]);
				}
				else {
					char x = (int)'S' + (int)'E' + (int)'T' - (int)v[i1][j] - (int)v[i2][j];
					s.push_back(x);
				}
			}
			cnt += upper_bound(v.begin() + i2 + 1, v.end(), s) - lower_bound(v.begin() + i2 + 1, v.end(), s);
		}
	}
	cout << cnt << "\n";
	return 0;
}