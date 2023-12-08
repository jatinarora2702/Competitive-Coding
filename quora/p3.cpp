#include <bits/stdc++.h>
using namespace std;

vector < vector < int > > process(vector < vector < int > > a, vector < int > q) {
	int n = a.size();
	for(int i = 0; i < q.size(); i++) {
		if (q[i] == 0) {
			vector < vector < int > > tmp(n, vector < int >(n));
			for(int j = 0; j < n; j++) {
				for(int k = 0; k < n; k++) {
					tmp[k][n-1-j] = a[j][k];
				}
			}
			for(int j = 0; j < n; j++) {
				for(int k = 0; k < n; k++) {
					a[j][k] = tmp[j][k];
				}
			}
		}
		else if (q[i] == 1) {
			for(int j = 0; j < n; j++) {
				for(int k = 0; k < j; k++) {
					int t = a[j][k];
					a[j][k] = a[k][j];
					a[k][j] = t;
				}
			}
		}
		else if (q[i] == 2) {
			for(int j = 0; j < n; j++) {
				for(int k = 0; k < n-j-1; k++) {
					int t = a[j][k];
					a[j][k] = a[n-1-k][n-1-j];
					a[n-1-k][n-1-j] = t;
				}
			}	
		}
	}
	return a;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector < vector < int > > a(n, vector < int >(n));
	vector < int > q(m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		cin >> q[i];
	}
	a = process(a, q);
	for(int i = 0; i < a.size(); i++) {
		for(int j = 0; j < a.size(); j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}