#include <bits/stdc++.h>
using namespace std;

vector < pair < pair < int, int >, int > > v[2];
vector < int > vs[2][2];

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		v[0].push_back(make_pair(make_pair(x1, y1), i));
		v[1].push_back(make_pair(make_pair(x2, y2), i));
	}
	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	for(int i = 0; i < n; i++) {
		upper_bound()
	}
}