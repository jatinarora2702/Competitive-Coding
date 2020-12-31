#include<bits/stdc++.h>
#define N 100005

using namespace std;

typedef long long int lli;

int a[N], b[N];
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, x, y;
		lli s = 0LL;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = 0;
			s += a[i];
		}
		for(int i = 0; i < n-1; i++) {
			cin >> x >> y;
			x--;
			y--;
			b[x]++;
			b[y]++;
		}
		vector<int> v;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < b[i]-1; j++) {
				v.push_back(a[i]);
			}
		}
		sort(v.begin(), v.end());
		cout << s << " ";
		for(int i = v.size()-1; i >= 0; i--) {
			s += v[i];
			cout << s << " ";
		}
		cout << "\n";
	}
	return 0;
}