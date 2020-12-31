#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> r[10];
	int a[] = {56, 51, 61, 72, 85, 101, 4, 72, 33};
	int n = 9;
	vector<int> v;
	for(int i = 0; i < n; i++) {
		v.push_back(a[i]);
	}
	int m = *max_element(v.begin(), v.end());
	int p = 0;
	while(m > 0) {
		for(int i = 0; i < v.size(); i++) {
			int d = v[i];
			for(int j = 0; j < p; j++) {
				d /= 10;
			}
			r[d % 10].push_back(v[i]);
		}
		v.clear();
		for(int i = 0; i < 10; i++) {
			for(int j = 0; j < r[i].size(); j++) {
				v.push_back(r[i][j]);
			}
			r[i].clear();
		}
		p++;
		m /= 10;
	}
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
	return 0;
}