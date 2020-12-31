#include <bits/stdc++.h>
#define N 55
using namespace std;

int a[N][N];
set < pair < int, int > > v;

int main() {
	int n, m, f, g;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	f = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if (a[i][j] == 1) {
				g = 0;
				if (i+1 < n && i+1 >= 0 && j+1 >= 0 && j+1 < m && a[i][j+1] == 1 && a[i+1][j] == 1 && a[i+1][j+1] == 1) {
					g = 1;
					v.insert(make_pair(i, j));
				}
				else if (i-1 < n && i-1 >= 0 && j+1 >= 0 && j+1 < m && a[i][j+1] == 1 && a[i-1][j] == 1 && a[i-1][j+1] == 1) {
					g = 1;
					v.insert(make_pair(i-1, j));
				}
				else if (i+1 < n && i+1 >= 0 && j-1 >= 0 && j-1 < m && a[i][j-1] == 1 && a[i+1][j] == 1 && a[i+1][j-1] == 1) {
					g = 1;
					v.insert(make_pair(i, j-1));
				}
				else if (i-1 < n && i-1 >= 0 && j-1 >= 0 && j-1 < m && a[i][j-1] == 1 && a[i-1][j] == 1 && a[i-1][j-1] == 1) {
					g = 1;
					v.insert(make_pair(i-1, j-1));
				}
			}
			if (g == 0) {
				f = 0;
				break;
			}
		}
		if (f == 0) {
			break;
		}
	}
	if (f == 0) {
		cout << "-1\n";
	}
	else {
		cout << v.size() << "\n";
		for(auto it : v) {
			cout << (it.first + 1) << " " << (it.second + 1) << "\n";
		}
	}
	return 0;
}