#include <bits/stdc++.h>
using namespace std;

vector < int > v[2];
int main() {
	int t, it[2];
	string s;
	cin >> t;
	while(t--) {
		cin >> s;
		v[0].clear();
		v[1].clear();
		for(int i = 0; i < s.length(); i++) {
			v[(s[i] - '0') % 2].push_back(s[i] - '0');
		}
		it[0] = it[1] = 0;
		while(it[0] < v[0].size() && it[1] < v[1].size()) {
			int f = v[0][it[0]] < v[1][it[1]] ? 0 : 1;
			cout << v[f][it[f]];
			it[f]++;
		}
		while(it[0] < v[0].size()) {
			cout << v[0][it[0]];
			it[0]++;
		}
		while(it[1] < v[1].size()) {
			cout << v[1][it[1]];
			it[1]++;
		}
		cout << "\n";
	}
	return 0;
}