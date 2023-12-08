#include <bits/stdc++.h>
using namespace std;

vector<int> fn(vector<int> v) {
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}

int main() {
	int n, x;
	vector<int> v;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	v = fn(v);
	cout << "done:";
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
	return 0;
}