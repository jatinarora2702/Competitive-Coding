#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define N 200005;

using namespace std;

typedef long long int lli;

const int INF = 1e9 + 7;

vector<pair<pair<int, int>, int>> v;

int main() {
	int t, h, n, k, d, i, j;
	cin >> t;
	for(h = 1; h <= t; h++) {
		cin >> n >> k;
		if(n == 2) {
			cout << "Case #" << h << ": 0" << endl;
			cout << "1 2 1" << endl;
		}
		else if(k <= 2) {
			cout << "Case #" << h << ": 0" << endl;
			cout << 1 << " " << n << " " << k << endl;	
		}
		else {
			v.clear();
			v.PB(MP(MP(1, n), k));
			i = 1;
			j = k-1;
			d = 0;
			while(i < n && j > 1) {
				v.PB(MP(MP(i, i+1), j));
				d += j;
				i++;
				j--;
			}
			if(i < n) {
				v.PB(MP(MP(i, n), j));
				d += j;
			}
			d -= k;
			cout << "Case #" << h << ": " << d << endl;
			for(i = 0; i < v.size(); i++)
				cout << v[i].FF.FF << " " << v[i].FF.SS << " " << v[i].SS << endl;
		}
	}
	return 0;
}